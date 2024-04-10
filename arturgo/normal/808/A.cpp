#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int annee;
	cin >> annee;
	
	long long puis10 = 1;
	
	while(puis10 * 10 <= annee) {
		puis10 *= 10;
	}
	
	int val = annee / puis10;
	
	cout << (val + 1) * puis10 - annee << endl;
	return 0;
}