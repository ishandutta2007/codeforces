#include <iostream>
#define int long long
using namespace std;

const int FEUILLES = (1 << 18);

int nbNombres;
int flags[2 * FEUILLES];

void update(int n) {
	if(n >= FEUILLES) return;
	flags[2 * n] = max(flags[2 * n], flags[n]);
	flags[2 * n + 1] = max(flags[2 * n + 1], flags[n]);
	flags[n] = 0;
}

void affiche(int noeud = 1) {
	update(noeud);

	if(noeud >= FEUILLES) {
		if(noeud - FEUILLES < nbNombres)
			cout << flags[noeud] << " ";
		return;
	}

	affiche(2 * noeud);
	affiche(2 * noeud + 1);
}

void modif(int id, int val, int n = 1, int d = 0, int f = FEUILLES) {
	update(n);

	if(n >= FEUILLES) {
		flags[n] = val;
		return;
	}

	int m = (d + f) / 2;

	if(id < m) {
		modif(id, val, 2 * n, d, m);
	}
	else {
		modif(id, val, 2 * n + 1, m, f);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin >> nbNombres;

	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> flags[iNombre + FEUILLES];
	}

	int nbReqs;
	cin >> nbReqs;

	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int type;
		cin >> type;

		if(type == 1) {
			int id, val;
			cin >> id >> val;
			modif(id - 1, val);
		}
		else {
			int prog;
			cin >> prog;
			flags[1] = max(flags[1], prog);
		}
	}

	affiche();
	cout << endl;
	return 0;
}