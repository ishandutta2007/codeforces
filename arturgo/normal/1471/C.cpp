#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbAmis, nbCadeaux;
		cin >> nbAmis >> nbCadeaux;
		
		vector<int> indices;
		for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
			int indice;
			cin >> indice;
			indices.push_back(indice);
		}
		
		sort(indices.begin(), indices.end());
		reverse(indices.begin(), indices.end());
		
		vector<int> cadeaux;
		for(int iCadeau = 0;iCadeau < nbCadeaux;iCadeau++) {
			int cadeau;
			cin >> cadeau;
			cadeaux.push_back(cadeau);
		}
		
		int somme = 0;
		
		int iCadeau = 0;
		for(int indice : indices) {
			int mini = cadeaux[indice - 1];
			
			if(iCadeau != (int)cadeaux.size() && cadeaux[iCadeau] < mini) {
				mini = cadeaux[iCadeau];
				iCadeau++;
			}
			
			somme += mini;
		}
		
		cout << somme << endl;
	}
	return 0;
}