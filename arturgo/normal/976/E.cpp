#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nbMonstres, nbDoubles, nbChanges;
	cin >> nbMonstres >> nbDoubles >> nbChanges;
	
	vector<pair<long long, long long>> monstres;
	
	for(int iMonstre = 0;iMonstre < nbMonstres;iMonstre++) {
		int hp, dmg;
		cin >> hp >> dmg;
		monstres.push_back({hp, dmg});
	}
	
	sort(monstres.begin(), monstres.end(), 
		[&](pair<long long, long long> a, pair<long long, long long> b) {
			return a.first - a.second > b.first - b.second;
		}
	);
	
	long long sommeDmg = 0;
	int iMonstre = 0;
	for(;iMonstre < min(nbChanges, nbMonstres);iMonstre++) {
		sommeDmg += max(monstres[iMonstre].first, monstres[iMonstre].second);
	}
	
	for(;iMonstre < nbMonstres;iMonstre++) {
		sommeDmg += monstres[iMonstre].second;
	}
	
	if(nbChanges == 0) {
		cout << sommeDmg << endl;
		return 0;
	}
	
	long long maxDmg = sommeDmg;
	iMonstre = 0;
	for(;iMonstre < min(nbChanges, nbMonstres);iMonstre++) {
		long long curSomme = sommeDmg;
		curSomme -= max(monstres[iMonstre].first, monstres[iMonstre].second);
		curSomme += max(monstres[iMonstre].first * (1ll << nbDoubles), monstres[iMonstre].second);
		maxDmg = max(curSomme, maxDmg);
	}
	
	for(;iMonstre < nbMonstres;iMonstre++) {
		long long curSomme = sommeDmg;
		curSomme -= max(monstres[nbChanges - 1].first, monstres[nbChanges - 1].second) + monstres[iMonstre].second;
		curSomme += max(monstres[iMonstre].first * (1ll << nbDoubles), monstres[iMonstre].second) + monstres[nbChanges - 1].second;
		
		maxDmg = max(curSomme, maxDmg);
	}
	
	cout << maxDmg << endl;
	return 0;
}