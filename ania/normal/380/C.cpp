#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

typedef pair<int, pii> tri;

const int M = 1<<20;

int n;
char s[M];
tri T[M*2+13];

tri merge(tri le, tri ri) {
	int nm = min(le.se.fi, ri.se.se);
	tri res;
	res.fi = le.fi + ri.fi + nm;
	res.se.fi = le.se.fi + ri.se.fi - nm;
	res.se.se = le.se.se + ri.se.se - nm;
	return res;
}

int get(int le, int ri) {
	le += M;
	ri += M;
	tri L, R;
	L = T[le];
	while (le+1 < ri) {
		if (le%2 == 0) L = merge(L, T[le+1]);
		if (ri%2 == 1) R = merge(T[ri-1], R);
		le /= 2;
		ri /= 2;
	}
	L = merge(L, R);
	return L.fi;
}

int main() {
	scanf("%s", s);
	for (n=0; s[n]; n++) ;
	FOR(i,n) {
		if (s[i] == '(') T[M+i].se.fi=1;
		else T[M+i].se.se = 1;
	}
	for (int i = M-1; i >= 1; i--) {
		int le = 2*i, ri = 2*i+1;
		T[i] = merge(T[le], T[ri]);
	}
	int q;
	scanf("%d", &q);
	FOR(iii,q) {
		int le, ri;
		scanf("%d%d", &le, &ri);
		le--;
		printf("%d\n", 2*get(le, ri));
	}
	return 0;
}