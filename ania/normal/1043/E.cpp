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

const int N = 300300;

int x[N], y[N];
pair<ll,int> a[N];
ll res[N];

int main() {
	int n,m;
	ll suma = 0, totalx = 0;
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		scanf("%d%d", &x[i], &y[i]);
		a[i] = mp(y[i] - x[i], i);
		totalx += x[i];
	}
	sort(a,a+n);
	FOR(ii,n) {
		int i = a[ii].se;
		res[i] += totalx + 1LL * (n-2) * x[i] + suma + 1LL * a[ii].fi * (n-ii-1);
		suma += a[ii].fi;
	}
	//FOR(i,n) printf("%lld ", res[i]);
	//printf("\n");
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		res[a] -= min(x[a]+y[b], x[b]+y[a]);
		res[b] -= min(x[a]+y[b], x[b]+y[a]);
	}
	FOR(i,n) printf("%lld ", res[i]);
	printf("\n");
	return 0;
}