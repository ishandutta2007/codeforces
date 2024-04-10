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
const int maxn = 2e5 + 100;
int n, m;
int par[maxn];
bool hascycle[maxn];

int get_par (int v) {
	if (par[v] < 0)
		return v;
	return par[v] = get_par (par[v]);
}

bool merge (int v, int u) {
	v = get_par (v), u = get_par (u);
	if (v == u) {
		bool ret = 1;
		if (hascycle[v])
			ret = 0;
		hascycle[v] = 1;
		return ret;
	}
	par[v] = u;
	bool ret = 1;
	if (hascycle[u] and hascycle[v])
		ret = 0;
	hascycle[u] |= hascycle[v];
	return ret;
}

pii p[maxn];
int a[maxn], b[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	memset (par, -1, sizeof par);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int c;
		cin >> a[i] >> b[i] >> c;
		p[i] = {c, i};
	}
	sort (p + 1, p + m + 1, greater <pii> ());
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int idx = p[i].S;
		int v = a[idx], u = b[idx];
		if (merge (v, u))
			ans += p[i].F;
	}
	cout << ans << endl;
}