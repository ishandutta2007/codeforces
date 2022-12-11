#include <iostream>
#include <map>
#include <set>
using namespace std;

map<pair<long long, long long>, long long> costs;

long long getCost(long long a, long long b) {
	long long somme = 0;
	if(costs.find(make_pair(a, b)) != costs.end())
		somme += costs[make_pair(a, b)];
	if(costs.find(make_pair(b, a)) != costs.end())
		somme += costs[make_pair(b, a)];
	return somme;
}

long long getPPCA(long long a, long long b) {
	while(a != b) {
		if(a < b) {
			b /= 2;
		}
		else {
			a /= 2;
		}
	}
	
	return a;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int nbActions;
	cin >> nbActions;
	
	for(int iAction = 0;iAction < nbActions;iAction++) {
		int type;
		long long debut, fin;
		cin >> type >> debut >> fin;
		
		if(type == 1) {
			long long cost;
			cin >> cost;
			
			long long ppca = getPPCA(debut, fin);
			
			while(debut > ppca) {
				long long pro = debut / 2;
				if(costs.find(make_pair(pro, debut)) == costs.end())
					costs[make_pair(pro, debut)] = 0;
				costs[make_pair(pro, debut)] += cost;
				debut = pro;
			}
			
			while(fin > ppca) {
				long long pro = fin / 2;
				if(costs.find(make_pair(pro, fin)) == costs.end())
					costs[make_pair(pro, fin)] = 0;
				costs[make_pair(pro, fin)] += cost;
				fin = pro;
			}
		}
		else {
			long long somme = 0;
			long long ppca = getPPCA(debut, fin);
			
			while(debut > ppca) {
				long long pro = debut / 2;
				somme += getCost(pro, debut);
				debut = pro;
			}
			
			while(fin > ppca) {
				long long pro = fin / 2;
				somme += getCost(pro, fin);
				fin = pro;
			}
			
			cout << somme << endl;
		}
	}
	return 0;
}