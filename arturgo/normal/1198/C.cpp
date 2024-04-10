#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main() {
	int nbTests;
	scanf("%d", &nbTests);

	for(int iTest = 0;iTest < nbTests;iTest++) {
		int n, m;
		scanf("%d%d", &n, &m);

		set<int> presents;
		vector<pair<int, int>> arcs;

		vector<bool> indep(3 * n, true);
		vector<vector<int>> voisins(3 * n);

		for(int iArc = 0;iArc < m;iArc++) {
			int deb, fin;
			scanf("%d%d", &deb, &fin);
			deb--; fin--;
			presents.insert(iArc);
			arcs.push_back({deb, fin});
			voisins[deb].push_back(iArc);
			voisins[fin].push_back(iArc);
		}

		vector<int> couplage;
		while(!presents.empty()) {
			int mel = *presents.begin();

			couplage.push_back(mel);

			for(int arc : voisins[arcs[mel].first])
				presents.erase(arc);
			for(int arc : voisins[arcs[mel].second])
				presents.erase(arc);
			indep[arcs[mel].first] = false;
			indep[arcs[mel].second] = false;
		}

		if((int)couplage.size() >= n) {
			printf("Matching\n");

			int nb = 0;
			for(int arc : couplage) {
				printf("%d ", arc + 1);
				nb++;
				if(nb == n)
					break;
			}
			printf("\n");
		}
		else {
			printf("IndSet\n");

			int nb = 0;
			for(int i = 0;i < 3 * n;i++) {
				if(indep[i]) {
					printf("%d ", i + 1);
					nb++;
					if(nb == n)
						break;
				}
			}
			printf("\n");
		}
	}


	return 0;
}