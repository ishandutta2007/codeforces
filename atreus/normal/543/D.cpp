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
const int maxn = 2e5 + 100;
const int inf = (int)1e9;

ll power (ll a, ll b) {
	if (b == 0)
		return 1;
	ll ret = power (a, b / 2);
	ret *= ret;
	ret %= mod;
	if (b & 1)
		ret *= a;
	return ret % mod;
}

vector <int> v[maxn];

vector <ll> par[maxn], rev[maxn];

ll dp_up[maxn], dp_down[maxn];

void dfs_down (int u, int p = -1, ll tmp = 0) {
	dp_up[u] = 1;
	if (p != -1) {
		dp_up[u] = dp_up[p] * tmp % mod + 1 % mod;
		dp_up[u] %= mod;
	}
	for (int i = 0; i < v[u].size(); i++) {
		int w = v[u][i];
		ll cmp = 1;
		if (i > 0)
			cmp *= par[u][i - 1];
		if (i < v[u].size() - 1)
			cmp *= rev[u][i + 1];
		cmp %= mod;
		dfs_down (w, u, cmp);
	}
}

void dfs_up (int u) {
	dp_down[u] = 1;
	for (auto w : v[u]) {
		dfs_up (w);
		if (par[u].empty())
			par[u].PB ((dp_down[w] + 1) % mod);
		else
			par[u].PB (par[u].back() * (dp_down[w] + 1) % mod);
		dp_down[u] *= (dp_down[w] + 1);
		dp_down[u] %= mod;
	}
	for (int i = v[u].size() - 1; i >= 0; i--) {
		int w = v[u][i];
		if (rev[u].empty())
			rev[u].PB ((dp_down[w] + 1) % mod);
		else
			rev[u].PB ((dp_down[w] + 1) * rev[u].back() % mod);
	}
	reverse (rev[u].begin(), rev[u].end());
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
	dfs_up (1);
	dfs_down (1);
	for (int i = 1; i <= n; i++)
		cout << dp_up[i] * dp_down[i] % mod << " ";
}