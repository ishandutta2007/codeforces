#include <iostream>
#include <algorithm>
using namespace std;

const int ID = 0, IV = 1, ST = 2, RS = 3;

int groupeMult[4][4] = {
	{ID, IV, ST, RS},
	{IV, ID, ST, RS},
	{ST, RS, ST, RS},
	{RS, ST, ST, RS}
};

int elems[(1 << 20)];
int tailles[(1 << 20)];
int nbSous[(1 << 20)];

void apply(int noeud) {
	if(noeud < (1 << 19)) {
		elems[2 * noeud] = groupeMult[elems[2 * noeud]][elems[noeud]];
		elems[2 * noeud + 1] = groupeMult[elems[2 * noeud + 1]][elems[noeud]];
	}
	
	if(elems[noeud] == IV) {
		nbSous[noeud] = tailles[noeud] - nbSous[noeud];
	}
	if(elems[noeud] == ST) {
		nbSous[noeud] = tailles[noeud];
	}
	if(elems[noeud] == RS) {
		nbSous[noeud] = 0;
	}
	
	elems[noeud] = ID;
}

void modif(int deb, int fin, int elem, int cdeb = 0, int cfin = (1 << 19), int noeud = 1) {
	tailles[noeud] = cfin - cdeb;
	
	apply(noeud);
	
	if(deb >= cfin || fin <= cdeb)
		return ;
	
	if(deb <= cdeb && cfin <= fin) {
		elems[noeud] = groupeMult[elems[noeud]][elem];
		apply(noeud);
		return;
	}
	
	int cmil = (cdeb + cfin) / 2;
	
	modif(deb, fin, elem, cdeb, cmil, 2 * noeud);
	modif(deb, fin, elem, cmil, cfin, 2 * noeud + 1);
	
	nbSous[noeud] = nbSous[2 * noeud] + nbSous[2 * noeud + 1];
}

int getMex(int cdeb = 0, int cfin = (1 << 19), int noeud = 1) {
	tailles[noeud] = cfin - cdeb;
	apply(noeud);
	
	if(nbSous[noeud] == tailles[noeud]) {
		return -1;
	}
	
	if(tailles[noeud] == 1) {
		return cdeb;
	}
	
	int cmil = (cdeb + cfin) / 2;
	
	int repg = getMex(cdeb, cmil, 2 * noeud);
	if(repg != -1)
		return repg;
	
	return getMex(cmil, cfin, 2 * noeud + 1);
}

int types[100 * 1000];

pair<long long, int> vals[400 * 1000];
int image[400 * 1000];
long long ante[400 * 1000];

int main() {
	int nbReqs;
	cin >> nbReqs;
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		long long deb, fin;
		cin >> types[iReq] >> deb >> fin;
		
		vals[2 * iReq] = {deb - 1, 2 * iReq};
		vals[2 * iReq + 1] = {fin, 2 * iReq + 1};
	}
	
	vals[2 * nbReqs] = {0, 2 * nbReqs};
	
	sort(vals, vals + 2 * nbReqs + 1);
	
	for(int deb = 0;deb < 2 * nbReqs + 1;) {
		int fin = deb;
		while(fin != 2 * nbReqs + 1 && vals[deb].first == vals[fin].first) {
			image[vals[fin].second] = deb;
			fin++;
		}
		
		ante[deb] = vals[deb].first;
		
		deb = fin;
	}
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int deb = image[2 * iReq];
		int fin = image[2 * iReq + 1];
		
		if(types[iReq] == 1) {
			modif(deb, fin, ST);
		}
		if(types[iReq] == 2) {
			modif(deb, fin, RS);
		}
		if(types[iReq] == 3) {
			modif(deb, fin, IV);
		}
		
		cout << ante[getMex()] + 1 << endl;
	}
}