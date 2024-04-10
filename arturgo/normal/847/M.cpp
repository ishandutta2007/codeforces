#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int nbMesures;
	cin >> nbMesures;
	
	int a, b;
	cin >> a >> b;
	
	int d = b - a;
	
	bool ok = true;
	for(int iMesure = 2;iMesure < nbMesures;iMesure++) {
		int c;
		cin >> c;
		
		if(c - b != d) {
			ok = false;	
		}
		b = c;
	}
	
	if(ok) {
		cout << b + d << endl;
	}
	else {
		cout << b << endl;
	}
}