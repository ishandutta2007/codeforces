#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbCols;
	cin >> nbCols;
	
	if(nbCols == 1) {
		cout << "a" << endl << "a" << endl << "b" << endl << "b" << endl;
		return 0;
	}
	
	cout << "a";
	for(int iCol = 1;iCol < nbCols - 1;iCol++) {
		cout << (char)(((iCol+1) / 2) % 26 + 'a');
	}
	
	if(nbCols % 2 == 0) {
		cout << (char)((nbCols / 2 + 5) % 26 + 'a');
	}
	else {
		cout << (char)((nbCols / 2) % 26 + 'a');
	}
	
	cout << endl;
	
	cout << "a";
	for(int iCol = 1;iCol < nbCols - 1;iCol++) {
		cout << (char)(((iCol+1) / 2 + 1) % 26 + 'a');
	}
	
	if(nbCols % 2 == 0) {
		cout << (char)((nbCols / 2 + 5) % 26 + 'a');
	}
	else {
		cout << (char)((nbCols / 2 + 1) % 26 + 'a');
	}
	
	cout << endl;
	
	for(int iCol = 0;iCol < nbCols - 1;iCol++) {
		cout << (char)((iCol / 2 + 3) % 26 + 'a');
	}
	
	if(nbCols % 2 == 0) {
		cout << (char)(((nbCols - 1) / 2 + 3) % 26 + 'a');
	}
	else {
		cout << (char)(((nbCols - 1) / 2 + 5) % 26 + 'a');
	}
	
	cout << endl;
	
	for(int iCol = 0;iCol < nbCols - 1;iCol++) {
		cout << (char)((iCol / 2 + 2) % 26 + 'a');
	}
	
	if(nbCols % 2 == 0) {
		cout << (char)(((nbCols - 1) / 2 + 2) % 26 + 'a');
	}
	else {
		cout << (char)(((nbCols - 1) / 2 + 5) % 26 + 'a');
	}
	
	cout << endl;
}