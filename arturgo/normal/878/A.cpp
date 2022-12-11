#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int nbLignes;
	cin >> nbLignes;
	
	int a = 0, b = 1023;
	for(int iLigne = 0;iLigne < nbLignes;iLigne++) {
		char op;
		int c;
		cin >> op >> c;
		
		if(op == '^') {
			a = a ^ c;
			b = b ^ c;
		}
		if(op == '|') {
			a = a | c;
			b = b | c;
		}
		if(op == '&') {
			a = a & c;
			b = b & c;
		}
	}
	
	cout << 3 << endl;
	
	int opXor = 0, opOr = 0, opAnd = 0;
	
	for(int iBit = 0;iBit < 10;iBit++) {
		if(a % 2 == 0 && b % 2 == 0) {
			opAnd += (1 << iBit);
		}
		if(a % 2 == 1 && b % 2 == 1) {
			opOr += (1 << iBit);
		}
		if(a % 2 == 1 && b % 2 == 0) {
			opXor += (1 << iBit);
		}
		
		a /= 2;
		b /= 2;
	}
	
	cout << "| " << opOr << endl;
	cout << "^ " << opXor << endl;
	cout << "& " << 1023 - opAnd << endl;
	return 0;
}