#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nombre, nbParties;
	cin >> nombre >> nbParties;
	
	vector<int> sol;
	
	int iDiv = 2;
	while(iDiv * iDiv <= nombre) {
		if(nombre % iDiv == 0) {
			sol.push_back(iDiv);
			nombre /= iDiv;
		}
		else {
			iDiv++;	
		}
	}
	
	if(nombre != 0)
		sol.push_back(nombre);
	
	if(sol.size() < nbParties) {
		cout << -1 << endl;
	}
	else {
		while(sol.size() > nbParties) {
			int der = sol.back();
			sol.pop_back();
			sol.back() *= der;
		}
		
		for(int val : sol) {
			cout << val << " ";
		}
		cout << endl;
	}
}