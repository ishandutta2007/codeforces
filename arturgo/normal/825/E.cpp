#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nbFils[1000 * 1000];
vector<int> parents[1000 * 1000];

int solution[1000 * 1000];

priority_queue<int> ouverts;

int main() {
	int nbVilles, nbRoutes;
	cin >> nbVilles >> nbRoutes;
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int deb, fin;
		cin >> deb >> fin;
		parents[fin].push_back(deb);
		nbFils[deb]++;
	}
	
	for(int iVille = 1;iVille <= nbVilles;iVille++) {
		if(nbFils[iVille] == 0) {
			ouverts.push(iVille);
		}
	}
	
	for(int iFois = nbVilles;iFois >= 1;iFois--) {
		int cur = ouverts.top();
		ouverts.pop();
		solution[cur] = iFois;
		for(int p : parents[cur]) {
			nbFils[p]--;
			if(nbFils[p] == 0)
				ouverts.push(p);
		}
	}
	
	for(int iVille = 1;iVille <= nbVilles;iVille++) {
		cout << solution[iVille] << " ";
	}
	cout << endl;
}