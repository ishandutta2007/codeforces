#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;

struct Ch {
	int vals[10];
	
	Ch() {
		for(int i = 0;i < 10;i++) {
			vals[i] = 0;
		}
	}
};

bool operator == (const Ch &a, const Ch &b) {
	for(int i = 0;i < 10;i++) {
		if(a.vals[i] != b.vals[i])
			return false;
	}
	return true;
}

long long somme[10][(1 << 18)];
Ch chs[(1 << 18)];
Ch id;

void setPos(int pos, int ch, long long val) {
	pos += (1 << 17);
	while(pos != 0) {
		somme[ch][pos] += val;
		pos /= 2;
	}
}

void propage(int pos) {
	if(chs[pos] == id)
		return;
	
	long long vals[10];
	for(int i = 0;i < 10;i++) {
		vals[i] = 0;
	}
	
	for(int i = 0;i < 10;i++) {
		vals[chs[pos].vals[i]] += somme[i][pos];
	}
	
	for(int i = 0;i < 10;i++) {
		somme[i][pos] = vals[i];
	}
	
	if(pos >= (1 << 17)) {
		chs[pos] = id;
		return;
	}
	
	for(int iFils = 0;iFils < 2;iFils++) {
		int cur = 2 * pos + iFils;
		Ch n;
		for(int i = 0;i < 10;i++) {
			n.vals[i] = chs[pos].vals[chs[cur].vals[i]];
		}
		chs[cur] = n;
	}
	chs[pos] = id;
}

void changeChiffre(int deb, int fin, int x, int y, int n = 1, int d = 0, int f = (1 << 17)) {
	if(fin <= d || deb >= f) {
		propage(n);
		return;
	}
	if(deb <= d && f <= fin) {
		propage(n);
		
		chs[n].vals[x] = y;
		
		propage(n);
		return;
	}
	
	propage(n);
	int m = (d + f) / 2;
	
	changeChiffre(deb, fin, x, y, 2*n, d, m);
	changeChiffre(deb, fin, x, y, 2*n+1, m, f);
	
	for(int i = 0;i < 10;i++) {
		somme[i][n] = somme[i][2 * n] + somme[i][2 * n + 1];
	}
}

long long getSomme(int deb, int fin, int n = 1, int d = 0, int f = (1 << 17)) {
	if(fin <= d || deb >= f) {
		propage(n);
		return 0;
	}
	if(deb <= d && f <= fin) {
		propage(n);
		
		long long s = 0;
		
		for(int i = 0;i < 10;i++) {
			s += i * somme[i][n];
		}
		
		return s;
	}
	
	propage(n);
	int m = (d + f) / 2;
	
	return getSomme(deb, fin, 2*n, d, m) + getSomme(deb, fin, 2*n+1, m, f);
}

int main() {
	int nbNombres, nbReqs;
	scanf("%d%d", &nbNombres, &nbReqs);
	
	for(int i = 0;i < 10;i++) {
		id.vals[i] = i;
	}
	
	for(int i = 0;i < (1 << 18);i++) {
		chs[i] = id;
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		scanf("%d", &nombre);
		
		vector<int> vals(10, 0);
		int c = nombre;
		
		int m = 1;
		while(c != 0) {
			vals[c % 10] += m;
			c /= 10;
			m *= 10;
		}
		
		for(int i = 0;i < 10;i++) {
			setPos(iNombre, i, vals[i]);
		}
	}
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int type;
		scanf("%d", &type);
		
		if(type == 1) {
			int deb, fin, x, y;
			scanf("%d%d%d%d", &deb, &fin, &x, &y);
			changeChiffre(deb - 1, fin, x, y);
		}
		else {
			int deb, fin;
			scanf("%d%d", &deb, &fin);
			
			printf("%I64d\n", getSomme(deb - 1, fin));
		}
	}
}