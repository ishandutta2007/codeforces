#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
long long puis2[(1 << 18)], puisD[(1 << 18)];

struct Nombre {
	int g, d, t, u;
	long long h;
};

vector<Nombre> nombres;

int genereVide(int h = 17) {
	Nombre nouv;
	nouv.t = (1 << h);
	nouv.h = nouv.u = 0;
	
	if(h == 0) {
		nouv.g = nouv.d = -1;
	}
	else {
		nouv.g = genereVide(h - 1);
		nouv.d = genereVide(h - 1);
	}
	
	nombres.push_back(nouv);
	return (int)nombres.size() - 1;
}

int modulo(int n) {
	if(nombres[n].t == 1)
		return nombres[n].u;
	return (modulo(nombres[n].g) + puis2[nombres[n].t / 2] * modulo(nombres[n].d)) % MOD;
}

bool compareNombre(int a, int b) {
	if(nombres[a].h == nombres[b].h)
		return false;
		
	if(nombres[a].t == 1) {
		return nombres[a].u > nombres[b].u;
	}
	
	if(nombres[nombres[a].d].h != nombres[nombres[b].d].h)
		return compareNombre(nombres[a].d, nombres[b].d);
	return compareNombre(nombres[a].g, nombres[b].g);
}

int set(int n, int p, int val) {
	Nombre nouv = nombres[n];
	
	if(nombres[n].t == 1) {
		nouv.u = val;
		nouv.h = val;
		
		nombres.push_back(nouv);
		return (int)nombres.size() - 1;
	}
	
	if(p < nombres[n].t / 2) {
		nouv.g = set(nombres[n].g, p, val);
	}
	else {
		nouv.d = set(nombres[n].d, p - nombres[n].t / 2, val);
	}
	
	nouv.u = nombres[nouv.g].u + nombres[nouv.d].u;
	nouv.h = nombres[nouv.g].h + nombres[nouv.d].h * puisD[nouv.t / 2];
	
	nombres.push_back(nouv);
	return (int)nombres.size() - 1;
}

int get(int n, int p) {
	if(nombres[n].t == 1)
		return nombres[n].u;
	
	if(p < nombres[n].t / 2) {
		return get(nombres[n].g, p);
	}
	return get(nombres[n].d, p - nombres[n].t / 2);
}

int ajoute(int n, int p) {
	int pre0 = p;
	
	while(get(n, pre0) != 0) {
		pre0++;
	}
	
	n = set(n, pre0, 1);
	
	for(int iPos = p;iPos < pre0;iPos++) {
		n = set(n, iPos, 0);
	}
	
	return n;
}

struct Event {
	int pos, id, der;
	
	Event(int _pos = 0, int _id = 0, int _der = 0) {
		pos = _pos;
		id = _id;
		der = _der;
	}
};

bool operator < (const Event &a, const Event &b) {
	return compareNombre(a.id, b.id);
}

vector<pair<int, int> > voisins[100 * 1000];
bool estPasse[100 * 1000];
int parents[100 * 1000];

void init() {
	puis2[0] = 1;
	puisD[0] = 1;
	for(int i = 1;i < (1 << 18);i++) {
		puis2[i] = (2 * puis2[i - 1]) % MOD;
		puisD[i] = (30001 * puisD[i - 1]) % MOD;
	}
}

int main() {
	init();
	
	int nbVilles, nbRoutes;
	cin >> nbVilles >> nbRoutes;
	
	for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
		int deb, fin, ind;
		cin >> deb >> fin >> ind;
		
		voisins[deb - 1].push_back(make_pair(fin - 1, ind));
		voisins[fin - 1].push_back(make_pair(deb - 1, ind));
	}
	
	int deb, fin;
	cin >> deb >> fin;
	
	deb--; fin--;
	
	priority_queue< Event > events;
	events.push(Event(deb, genereVide(), -1));
	
	while(!events.empty()) {
		Event cur = events.top();
		events.pop();

		if(cur.pos == fin) {
			parents[cur.pos] = cur.der;
			cout << modulo(cur.id) << endl;
			
			vector<int> prec;
			prec.push_back(fin);
			
			while(prec.back() != -1) {
				prec.push_back(parents[prec.back()]);
			}
			
			prec.pop_back();
			
			cout << prec.size() << endl;
			
			while(!prec.empty()) {
				cout << prec.back() + 1 << " ";
				prec.pop_back();
			}
			cout << endl;
			return 0;
		}
		
		if(estPasse[cur.pos])
			continue;
		estPasse[cur.pos] = true;
		parents[cur.pos] = cur.der;
		
		for(pair<int, int> voisin : voisins[cur.pos]) {
			events.push(Event(voisin.first, ajoute(cur.id, voisin.second), cur.pos));
		}
	}
	
	cout << -1 << endl;
	return 0;
}