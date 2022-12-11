#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int INFINI = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000ll;

vector<pair<int, int>> voisins[200 * 1000];
int curDist[200 * 1000];

int curEvent = 0;
int debuts[200 * 1000], fins[200 * 1000];

void construit_inters(int noeud, int parent) {
	debuts[parent] = curEvent++;

	for(pair<int, int> voisin : voisins[noeud]) {
		if(voisin.second == parent)
			continue;
		construit_inters(voisin.first, voisin.second);
		curEvent++;
	}

	fins[parent] = curEvent;
}

int doitAjouter[(1 << 20)];
int maxDiam[(1 << 20)];
int maxi[(1 << 20)];
int mini[(1 << 20)];
int maxDec[(1 << 20)];
int maxInc[(1 << 20)];

void update(int n) {
	if(n < (1 << 19)) {
		doitAjouter[2 * n] += doitAjouter[n];
		doitAjouter[2 * n + 1] += doitAjouter[n];
		doitAjouter[n] = 0;
	}
	else {
		maxi[n] += doitAjouter[n];
		mini[n] += doitAjouter[n];
		doitAjouter[n] = 0;
		return;
	}

	maxi[n] = max(
		maxi[2 * n] + doitAjouter[2 * n],
		maxi[2 * n + 1] + doitAjouter[2 * n + 1]
	);

	maxDiam[n] = max(
		max(maxDiam[2 * n], maxDiam[2 * n + 1]),
		max(maxDec[2 * n] - doitAjouter[2 * n] + maxi[2 * n + 1] + doitAjouter[2 * n + 1], 
			maxi[2 * n] + doitAjouter[2 * n] + maxInc[2 * n + 1] - doitAjouter[2 * n + 1])
	);

	mini[n] = min(
		mini[2 * n] + doitAjouter[2 * n],
		mini[2 * n + 1] + doitAjouter[2 * n + 1]
	);

	maxDec[n] = max(
		max(maxDec[2 * n] - doitAjouter[2 * n], maxDec[2 * n + 1] - doitAjouter[2 * n + 1]),
		maxi[2 * n] + doitAjouter[2 * n] - 2 * (mini[2 * n + 1] + doitAjouter[2 * n + 1])
	);

	maxInc[n] = max(
		max(maxInc[2 * n] - doitAjouter[2 * n], maxInc[2 * n + 1] - doitAjouter[2 * n + 1]),
		maxi[2 * n + 1] + doitAjouter[2 * n + 1] - 2 * (mini[2 * n] + doitAjouter[2 * n])
	);
}

void ajoute_dist(int deb, int fin, int val, int n = 1, int d = 0, int f = (1 << 19)) {
	update(n);

	if(deb >= f || d >= fin)
		return;
	if(deb <= d && f <= fin) {
		doitAjouter[n] += val;
		update(n);
		return;
	}

	int m = (d + f) / 2;
	ajoute_dist(deb, fin, val, 2 * n, d, m);
	ajoute_dist(deb, fin, val, 2 * n + 1, m, f);
	update(n);
}

/*void affiche(int noeud, int d, int f) {
	if(noeud >= (1 << 20))
		return;

	update(noeud);

	int m = (d + f) / 2;
	affiche(2 * noeud, d, m);
	affiche(2 * noeud + 1, m, f);
	update(noeud);
}*/

signed main() {
	ios_base::sync_with_stdio(false);

	int nbVilles, nbReqs;
	int maxDist;

	cin >> nbVilles >> nbReqs >> maxDist;

	for(int iVille = 0;iVille < nbVilles - 1;iVille++) {
		int deb, fin;
		int dist;
		cin >> deb >> fin >> dist;
		deb--; fin--;

		voisins[deb].push_back({fin, iVille});
		voisins[fin].push_back({deb, iVille});
		curDist[iVille] = dist;
	}

	for(int iNoeud = 0;iNoeud < (1 << 20);iNoeud++) {
		maxDec[iNoeud] = maxInc[iNoeud] = -INFINI;
	}

	construit_inters(0, nbVilles);

	for(int iVille = 0;iVille < nbVilles - 1;iVille++) {
		ajoute_dist(debuts[iVille], fins[iVille], curDist[iVille]);
	}

	int last = 0;

	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int d, e;
		cin >> d >> e;

		d = (d + last) % (nbVilles - 1);
		e = (e + last) % maxDist;

		ajoute_dist(debuts[d], fins[d], e - curDist[d]);

		curDist[d] = e;

		cout << (last = max(maxDiam[1], maxi[1])) << endl;
	}
	return 0;
}