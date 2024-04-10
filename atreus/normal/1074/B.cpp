#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1000 + 4;
const int inf = (int)1e9;

int par[maxn];
vector <int> t[maxn];
bool mark[maxn], mark2[maxn];

void dfs (int v, int p = -1) {
	par[v] = p;
	for (auto u : t[v])
		if (u != p)
			dfs (u, v);
}

int main(){
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		memset (mark, 0, sizeof mark);
		memset (mark2, 0, sizeof mark2);
		memset (par, -1, sizeof par);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			t[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int v, u;
			cin >> v >> u;
			t[v].PB (u);
			t[u].PB (v);
		}
		int k;
		cin >> k;
		int v;
		for (int i = 0; i < k; i++) {
			cin >> v;
			mark[v] = 1;
		}
		dfs (v);
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> v;
			mark2[v] = 1;
		}
		cout << "B " << v << endl;
		int u;
		cin >> u;
		while (mark[u] == 0)
			u = par[u];
		cout << "A " << u << endl;
		int w;
		cin >> w;
		cout << "C ";
		if (mark2[w] == 1)
			cout << u << endl;
		else
			cout << -1 << endl;
	}
}