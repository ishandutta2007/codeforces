#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,a,b) for (int i = (a); i >=(b); i--)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); i++)
#define fi first
#define se second

const int maxn = 1000100;

int n,m;
pii v[maxn];
int par[maxn], si[maxn];
bool used[maxn];
vector<int> g[maxn];
long long cur;

inline long long ff(int x) {
	return 1LL * si[x] * (si[x]-1);
}

int fi(int a) {
	if (par[a] == a) return a;
	return par[a] = fi(par[a]);
}

void uni(int a, int b) {
	int fa = fi(a), fb = fi(b);
	//printf("uni %d %d -> %d %d\n", a, b, fa, fb);
	if (fa == fb) return;
	cur -= ff(fa);
	cur -= ff(fb);
	si[fa] += si[fb];
	cur += ff(fa);
	par[fb] = fa;
}

long long add(int u) {
	cur = ff(u);
	used[u] = true;
	//printf("add %d\n", u);
	FOR(i,g[u].size()) {
		int w = g[u][i];
		if (used[w]) uni(u,w);
	}
	//printf("add %d -> %d\n", u, cur);
	return cur;
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		par[i] = i;
		si[i] = 1;
	}
	FOR(i,n) {
		scanf("%d", &v[i].fi);
		v[i].se = i;
	}
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	sort(v,v+n);
	long long res = 0;
	REPD(i,n-1,0) {
		res += 1LL * v[i].fi * add(v[i].se);
	}
	printf("%.9lf\n", 1.0 * res / n / (n-1));
	return 0;
}