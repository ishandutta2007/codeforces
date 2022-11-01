#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int n;
vector<pair<string, int>> a(1000), to[1000], ans;
vector<int> g[1000];
map<pair<string, int>, int> re;
set<string> names;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		re[a[i]] = i;
		int k; cin >> k;
		to[i].resize(k);
		for(int j = 0; j < k; j++) cin >> to[i][j].first >> to[i][j].second;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < sz(to[i]); j++)
			g[i].push_back(re[to[i][j]]);
	names.insert(a[0].first);
	bitset<1000> nw;
	nw[0] = 1;
	while(nw.count()) {
		bitset<1000> tok;
		for(int u = 0; u < n; u++) if(nw[u]) for(int v : g[u]) tok[v] = 1;
		for(int i = 0; i < n; i++)
			if(names.find(a[i].first) != names.end()) tok[i] = 0;
		map<string, int> opt;
		for(int i = 0; i < n; i++) if(tok[i]) opt[a[i].first] = max(opt[a[i].first], a[i].second);
		for(int i = 0; i < n; i++) if(tok[i] && opt[a[i].first] != a[i].second) tok[i] = false;
		else if(tok[i]) {
			names.insert(a[i].first);
			ans.push_back(a[i]);
		}
		nw = tok;
	}
	sort(all(ans));
	cout << sz(ans) << '\n';
	for(int i = 0; i < sz(ans); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}