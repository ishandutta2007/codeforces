#include <iostream>
#include <vector>
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

int nbFilles, nbAmis, maxPoids;
pair<int, int> filles[10 * 1000];
vector<int> groupes[10 * 1000];
int parent[10 * 1000];

int Find(int a) {
	if(a == parent[a])
		return a;
	return (parent[a] = Find(parent[a]));
}

int dyn[1001][1042];
bool estPasse[1001][1042];

int maxBeaute(int groupe, int poids) {
	if(poids > maxPoids) {
		return -INFINI;
	}
	
	if(groupe == nbFilles + 1)
		return 0;
	if(estPasse[groupe][poids])
		return dyn[groupe][poids];
	estPasse[groupe][poids] = true;
	
	int maxi = maxBeaute(groupe + 1, poids);
	int sommeBeautes = 0, sommePoids = 0;
	for(int fille : groupes[groupe]) {
		maxi = max(maxi, maxBeaute(groupe + 1, poids + filles[fille].first) + filles[fille].second);
		sommeBeautes += filles[fille].second;
		sommePoids += filles[fille].first;
	}
	
	maxi = max(maxi, maxBeaute(groupe + 1, poids + sommePoids) + sommeBeautes);
	
	dyn[groupe][poids] = maxi;
	return maxi;
}

int main() {
	cin >> nbFilles >> nbAmis >> maxPoids;
	
	for(int iFille = 1;iFille <= nbFilles;iFille++) {
		parent[iFille] = iFille;
		groupes[iFille].push_back(iFille);
		cin >> filles[iFille].first;
	}
	
	for(int iFille = 1;iFille <= nbFilles;iFille++) {
		cin >> filles[iFille].second;
	}
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		int a, b;
		cin >> a >> b;
		
		if(Find(a) != Find(b)) {
			for(int elem : groupes[Find(b)]) {
				groupes[Find(a)].push_back(elem);
			}
			groupes[Find(b)].clear();
			parent[Find(b)] = Find(a);
		}
	}
	
	cout << maxBeaute(1, 0) << endl;
	return 0;
}