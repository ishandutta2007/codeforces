#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 120000;
int was[MAXN];

vector<pair<int, int>> eds[MAXN];
vector<int> go[MAXN];
int pe[MAXN];
int p[MAXN];
int h[MAXN];
int ad[MAXN];
vector<pair<int, int> > vv;
int cc[MAXN];

int n, m;

int dfs1(int v) {
	int cur = 0;
	was[v] = 1;
	for (auto e: eds[v]) {
		int u = e.first;
		if (was[u]) {
			if (h[u] < h[v] - 1) {
				--ad[u];
				vv.push_back(make_pair(v, u));
				go[v].push_back(e.second);
				++cur;
			}
		}
		else {
			h[u] = h[v] + 1;
			p[u] = v;
			pe[u] = e.second;
			cur += dfs1(u);
		}
	}
	cur += ad[v];
	if (h[v] != 0) {
		cc[pe[v]] = cur;
	}
	return cur;
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(make_pair(b, i));
		eds[b].push_back(make_pair(a, i));
	}
	for (int i = 0; i < n; ++i)
		if (!was[i])
			dfs1(i);
	vector<int> ans;
	for (auto e: vv) {
		int a, b;
		tie(a, b) = e;
		int fl = 0;
		while (a != b) {
			if (cc[pe[a]] != 1) {
				fl = 1;
				break;
			}
			a = p[a];
		}
		if (!fl) {
			tie(a, b) = e;
			ans.push_back(go[a][0]);
			while (a != b) {
				ans.push_back(pe[a]);
				a = p[a];
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i: ans)
		cout << i + 1 << " ";
}