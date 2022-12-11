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

const int N = 400400;

int n;
int wei[N], par[N][20];
ll sum[N][20];

void add(int u, int w) {
	//printf("adding %d %d\n", u, w);
	while (wei[u] < w) {
		bool fnd = false;
		int can = -1;
		for (int i = 0; par[u][i] != -1; i++) {
			if (wei[par[u][i]] < w) can = i;
			else break;
		}
		if (can != -1) {
			fnd = true;
			u = par[u][can];
		}
		if (!fnd) break;
	}
	if (wei[u] < w) {
		if (par[u][0] != -1 && wei[par[u][0]] >= w) u = par[u][0];
		else u = -1;
	}
	wei[n] = w;
	par[n][0] = u;
	par[n][1] = -1;
	sum[n][0] = wei[u];
	for (int i = 1; par[n][i-1] != -1; i++) {
		par[n][i] = par[par[n][i-1]][i-1];
		sum[n][i] = sum[n][i-1] + sum[par[n][i-1]][i-1];
		par[n][i+1] = -1;
	}
	for (int i=1; i<20; i++) if (par[n][i-1] == -1) par[n][i] = -1;
	//for (int i=0; par[n][i] != -1; i++) printf("%d %d -> %d %lld\n", n, i, par[n][i], sum[n][i]);
	n++;
}

int query(int u, ll w) {
	//printf("query %d %lld\n", u, w); fflush(stdout);
	if (w < wei[u]) return 0;
	int res = 0;
	w -= wei[u];
	res++;
	bool fnd = true;
	while (fnd) {
		fnd = false;
		int can = -1;
		for (int i = 0; par[u][i] != -1; i++) {
			if (sum[u][i] <= w) can = i;
			else break;
		}
		if (can != -1) {
			fnd = true;
			res += 1 << can;
			w -= sum[u][can];
			u = par[u][can];
		}
	}
	return res;
}

int main() {
	n=1;
	FOR(i,20) par[0][i] = -1;
	int ttn;
	scanf("%d", &ttn);
	int last = 0;
	while (ttn--) {
		int qt;
		ll u,w;
		scanf("%d%lld%lld", &qt, &u, &w);
		u ^= last;
		w ^= last;
		if (qt == 1) add(u-1, w);
		else {
			last = query(u-1, w);
			printf("%d\n", last);
		}
	}
	return 0;
}