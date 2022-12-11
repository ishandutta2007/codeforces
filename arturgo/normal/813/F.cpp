#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

struct Req {
	int debT, finT;
	int deb, fin;
	
	Req(int _deb = 0, int _fin = 0, int _debT = 0, int _finT = 0) {
		deb = _deb;
		fin = _fin;
		debT = _debT;
		finT = _finT;
	}
};

int sz = 0;
pair<int*, int> chs[30 * 1000 * 1000];

int parents[1000 * 1000];
int tailles[1000 * 1000];

int Find(int a) {
	if(parents[a] == 0) {
		return a;
	}
	return Find(parents[a]);
}

void Union(int a, int b) {
	a = Find(a); b = Find(b);
	if(tailles[a] > tailles[b])
		Union(b, a);
	else if(a != b) {
		chs[sz++] = make_pair(&parents[a], parents[a]);
		parents[a] = b;
		
		chs[sz++] = make_pair(&tailles[b], tailles[b]);
		tailles[b] += tailles[a];
	}
}

void solve(int deb, int fin, vector<Req>& reqs) {
	int date = sz;
	
	int mil = (deb + fin) / 2;
	
	bool estBiparti = true;
	
	vector<Req> gauches, droites;
	for(Req req : reqs) {
		if(req.debT <= deb && req.finT >= fin) {
			Union(2 * req.deb, 2 * req.fin - 1);
			Union(2 * req.deb - 1, 2 * req.fin);
			
			if(Find(2 * req.deb) == Find(2 * req.deb - 1)) {
				estBiparti = false;
			}
		}
		else {
			if(max(deb, req.debT) < min(mil, req.finT))
				gauches.push_back(
					Req(req.deb, req.fin, max(deb, req.debT), min(mil, req.finT))
				);
			if(max(mil, req.debT) < min(fin, req.finT))
				droites.push_back(
					Req(req.deb, req.fin, max(mil, req.debT), min(fin, req.finT))
				);
		}
	}
	
	if(!estBiparti) {
		for(int iReq = 0;iReq < fin - deb;iReq++) {
			printf("NO\n");
		}
	}
	else if(fin - deb == 1) {
		printf("YES\n");
	}
	else {
		solve(deb, mil, gauches);
		solve(mil, fin, droites);
	}
	
	while(sz > date) {
		pair<int*, int> ch = chs[--sz];
		*ch.first = ch.second;
	}
}

map<pair<int, int> , int> temps; 

int main() {
	int nbNoeuds, nbReqs;
	scanf("%d%d", &nbNoeuds, &nbReqs);
	
	vector<Req> reqs;
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int deb, fin;
		scanf("%d%d", &deb, &fin);
		
		if(deb > fin) {
			swap(deb, fin);
		}
		
		if(temps.find(make_pair(deb, fin)) != temps.end()) {
			reqs.push_back(Req(deb, fin, temps[make_pair(deb, fin)], iReq));
			temps.erase(make_pair(deb, fin));
		}
		else {
			temps[make_pair(deb, fin)] = iReq;
		}
	}
	
	for(pair<pair<int, int>, int> t : temps) {
		reqs.push_back(Req(t.first.first, t.first.second, t.second, nbReqs));
	}
	
	solve(0, nbReqs, reqs);
}