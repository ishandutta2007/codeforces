#include <bits/stdc++.h>

using namespace std;	

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define pb push_back
#define endl '\n'

multiset <ll> bigger;

const int MAXN = (int) 1e5 + 7;
vector <pair <int, int> >  g[MAXN];
int a[MAXN];
int ans = 0;

void dfs(int v, int pr, ll h, bool die) {
	if (bigger.size()) {
		die |= *bigger.rbegin() > a[v] - h;
	}
	if (die) {
		ans++;
	}
	bigger.insert(-h);
	for (int i = 0; i < (int) g[v].size(); i++) {
		int to = g[v][i].fc;
		if (to != pr) {
			dfs(to, v, h + g[v][i].sc, die);
		}
	}
	bigger.erase(bigger.find(-h));
}

int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("input.txt");
	//ofstream cout("out.txt");
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	int u, c;
	for (int v = 2; v <= n; v++) {
		cin >> u >> c;
		g[v].pb(mp(u, c));
		g[u].pb(mp(v, c));
	}
	dfs(1, -1, 0, 0);
	cout << ans << endl;
}