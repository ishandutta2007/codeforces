#include <cstdio>
using namespace std;

int pgcds[(1 << 20)];

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

void setEntier(int pos, int val) {
	pos += (1 << 19);
	pgcds[pos] = val;
	while(pos != 0) {
		pos /= 2;
		pgcds[pos] = pgcd(pgcds[pos * 2 + 1], pgcds[pos * 2]);
	}
}

int nbIncs(int noeud, int nb) {
	if(pgcds[noeud] % nb == 0)
		return 0;
	if(noeud >= (1 << 19))
		return 1;
	if(pgcds[2 * noeud] % nb != 0 && pgcds[2 * noeud + 1] % nb != 0)
		return 2;
	if(pgcds[2 * noeud] % nb != 0)
		return nbIncs(2 * noeud, nb);
	return nbIncs(2 * noeud + 1, nb);
}

bool check(int deb, int fin, int nb) {
	deb += (1 << 19);
	fin += (1 << 19);

	int nbI = 0;
	while(deb < fin) {
		if(deb % 2 == 1) {
			nbI += nbIncs(deb, nb);
			deb++;
		}

		if(nbI >= 2) return false;

		if(fin % 2 == 1) {
			fin--;
			nbI += nbIncs(fin, nb);
		}

		if(nbI >= 2) return false;

		deb /= 2;
		fin /= 2;
	}

	return true;
}

int main() {
	int taille;
	scanf("%d", &taille);

	for(int i = 0;i < taille;i++) {
		int val;
		scanf("%d", &val);
		setEntier(i, val);
	}

	int nbReqs;
	scanf("%d", &nbReqs);

	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int type;
		scanf("%d", &type);

		if(type == 1) {
			int deb, fin, nb;
			scanf("%d%d%d", &deb, &fin, &nb);

			if(check(deb - 1, fin, nb)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			int pos, val;
			scanf("%d%d", &pos, &val);
			setEntier(pos - 1, val);
		}
	}

	return 0;
}