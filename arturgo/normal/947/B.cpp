#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int nbJours;
vector<unsigned long long> tailles, temps;

unsigned long long fonte = 0;
multiset<unsigned long long> nonNuls;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbJours;
	
	for(int iJour = 0;iJour < nbJours;iJour++) {
		int taille;
		cin >> taille;
		tailles.push_back(taille);
	}
	
	for(int iJour = 0;iJour < nbJours;iJour++) {
		int temp;
		cin >> temp;
		temps.push_back(temp);
	}
	
	for(int iJour = 0;iJour < nbJours;iJour++) {
		nonNuls.insert(fonte + tailles[iJour]);
		fonte += temps[iJour];
		
		unsigned long long ici = 0;
		while(!nonNuls.empty() && *nonNuls.begin() <= fonte) {
			ici += temps[iJour] + *nonNuls.begin() - fonte;
			nonNuls.erase(nonNuls.begin());
		}
		
		ici += nonNuls.size() * temps[iJour];
		cout << ici << " ";
	}
	cout << endl;
	return 0;
}