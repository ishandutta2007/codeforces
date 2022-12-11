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

const int mod = 1000000007;
const int N = 1010;

int m;
int c[N][N];
int p[N];
ll v[N];
char tmp[N];

void init() {
	for (int n = 0; n <= m; n++) c[n][0] = c[n][n] = 1;
	for (int n = 1; n <= m; n++) for (int k = 1; k < n; k++) {
		c[n][k] = c[n-1][k] + c[n-1][k-1];
		if (c[n][k] >= mod) c[n][k] -= mod;
	}
	p[0] = 1;
	for (int n = 1; n <= m; n++) {
		for (int k = 1; k <= n; k++) {
			p[n] = (1LL * p[n-k] * c[n-1][k-1] + p[n]) % mod;
		}
	}
}

int main() {
	int n;
	scanf("%d%d", &m, &n);
	FOR(i,n) {
		scanf("%s", tmp);
		FOR(j,m) v[j] = v[j]*2+(tmp[j]-'0');
	}
	init();
	sort(v,v+m);
	int last = 0, res = 1;
	for (int i=1; i<=m; i++) if (i==m || v[i] != v[i-1]) {
		res = 1LL * res * p[i-last] % mod;
		last = i;
	}
	printf("%d\n", res);
	return 0;
}