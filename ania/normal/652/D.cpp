#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 200200;
const int N = 1<<19;

map<int,int> re, M;
pii t[maxn];
int tt[maxn], p[2*maxn];
int T[2*N];

void add(int x) {
	x = M[x]+N;
	while (x >= 1) {
		T[x]++;
		x /= 2;
	}
}

int cnt(int x) {
	x = M[x]+N;
	int r = T[x];
	while (x > 1) {
		if (x%2==0) r += T[x+1];
		x /= 2;
	}
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d%d", &t[i].se, &t[i].fi);
		tt[i] = t[i].se;
		p[2*i] = t[i].fi;
		p[2*i+1] = t[i].se;
	}
	sort(p,p+2*n);
	FOR(i,2*n) M[p[i]] = i;
	sort(t,t+n);
	FOR(i,n) {
		re[t[i].se] = cnt(t[i].se);
		add(t[i].se);
	}
	FOR(i,n) printf("%d\n", re[tt[i]]);
	return 0;
}