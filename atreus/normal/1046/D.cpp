#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;

int par[maxn];
double dp[maxn], p[maxn];
vector <int> t[maxn];
double ans = 0;

void dfs (int v, int pe = 0) {
	par[v] = pe;
	ans += (1 - p[v]) * p[pe];
	for (auto w : t[v]) {
		if (w != pe) {
			dfs (w, v);
			dp[v] += (1 - p[w]);
		}
	}
}

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%lf", &p[i]);
	}
	for (int i = 1; i <= n - 1; i++) {
		int v, u;
		scanf ("%d%d", &v, &u);
		v ++, u ++;
		t[v].PB (u);
		t[u].PB (v);
	}
	p[0] = 1;
	dfs (1);
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int idx;
		double newp;
		scanf ("%d%lf", &idx, &newp);
		idx ++;
		
		ans -= (1 - p[idx]) * p[par[idx]];
		ans += (1 - newp) * p[par[idx]];
		ans -= dp[idx] * p[idx];
		ans += dp[idx] * newp;
		dp[par[idx]] -= (1 - p[idx]);
		dp[par[idx]] += (1 - newp);
		p[idx] = newp;
		
		printf ("%.4lf \n", ans);
	}
}