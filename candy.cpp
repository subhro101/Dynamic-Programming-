/* This program returns the number of possible combinations of chocolates in a box,
 * when given the number of spaces and the varieties of long and square pieces.
 * This version uses an iterative approach to solving the problem.
 * Authors: David Ehrenhaft, Subhrajyoti Pradhan, Brian Skinner
 *
 * Compiled on g++ 6.2.0
 *
 * Date last updated: 3/29/18
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

unsigned long long int findCombinations(int n, int s, int l);

int main(void){
  ifstream infile("input.txt");
  ofstream outfile;

  //output
  outfile.open("output.txt");


  //inputs n,s,l to be read from textfile, k,i for loop indexes
  int n, s, l, k, i;
  i = 1;

  //
  unsigned long long int output;

  //read how many lines
  infile >> k;


  while(i <= k) {
    //read line by line n, s, l
    infile >> n >> s >> l;

    //function call
    output = findCombinations(n, s, l);

    //output
    outfile << output << endl;
    //cout << output << endl;
    i++; //increase i for loop logic
  }
  outfile.close();

  return 1;
}




unsigned long long int findCombinations(int n, int s, int l) {
	unsigned long long int first, second, output;
  int j;

	//solves if a base case (n = 0, n = 1, n = 2), otherwise performs iterative calculation
	if(n == 0) {
		output = 0;
	}
	else if(n == 1) {
		output = s;
	}
	else if(n == 2) {
		output = s * s + l;
	}
	else {
		first = s * s + l;
		second = s;
		for(j = 3; j < n + 1; j++) {
			output = first * s + second * l;
			second = first;
			first = output;
		}
	}

	return output;
}
