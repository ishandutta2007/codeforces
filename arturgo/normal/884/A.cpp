#include <iostream>
using namespace std;

int main() {
	int nbJours, temps;
	cin >> nbJours >> temps;
	
	for(int iJour = 0;iJour < nbJours;iJour++) {
		int t;
		cin >> t;
		temps -= (86400 - t);
		
		if(temps <= 0) {
			cout << iJour + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}