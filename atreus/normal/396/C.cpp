#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 3e5 + 100;
const int inf = (int)1e9;

ll seg[4 * maxn], seseg[4 * maxn];

ll relax (ll ret) {
	return ((ret % mod) + mod) % mod;
}

ll get (int id, int L, int R, int idx, ll val) {
	if (L + 1 == R) {
		return relax (seg[id] - val * seseg[id]);
	}
	int mid = (L + R) / 2;
	ll ret = relax (seg[id] - val * seseg[id]);
	if (mid > idx)
		ret = relax (get (2 * id + 0, L, mid, idx, val) + ret);
	else
		ret = relax (get (2 * id + 1, mid, R, idx, val) + ret);
	return ret;
}

void change (int id, int L, int R, int l, int r, ll val, ll seval) {
	if (L == l and R == r) {
		seg[id] += val;
		seseg[id] += seval;
		seg[id] %= mod;
		seseg[id] %= mod;
		return;
	}

	int mid = (L + R) / 2;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), val, seval);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, val, seval);
}

vector <int> v[maxn];
int Mytime = 1, h[maxn], st[maxn], ft[maxn];
void dfs (int u) {
	st[u] = Mytime ++;
	for (auto w : v[u]) {
		h[w] = h[u] + 1;
		dfs (w);
	}
	ft[u] = Mytime;
}

int main(){ 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		v[p].PB (i);
	}
	dfs (1);
	
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			ll u, x, k;
			cin >> u >> x >> k;
			change (1, 1, n + 1, st[u], ft[u], relax (x + h[u] * k), k);
		}
		else {
			int u;
			cin >> u;
			cout << get (1, 1, n + 1, st[u], h[u]) << '\n';
		}
	}
}