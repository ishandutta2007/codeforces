#include <iostream>
using namespace std;

int cnts[256];

int main() {
	string s;
	cin >> s;
	
	for(char car : s) { cnts[car]++; }
	
	int nb = min(cnts['B'], cnts['l']);
	nb = min(nb, cnts['b']);
	nb = min(nb, cnts['s']);
	nb = min(nb, cnts['r']);
	nb = min(nb, cnts['a'] / 2);
	nb = min(nb, cnts['u'] / 2);
	
	cout << nb << endl;
	return 0;
}