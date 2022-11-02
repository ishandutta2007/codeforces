#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;

void solve() {
	vector<int> g[4];
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		g[a * 2 + b].push_back(t);
	}
	if(g[3].size() + g[1].size() < k || g[3].size()  + g[2].size() < k) {
		cout << -1 << "\n";
		return;
	}
	for(int i = 0; i < 4; i++) {
		sort(g[i].begin(), g[i].end());
	}
	int st = 0;
	ll ans = 1ll<<50;
	ll cur = 0;
	multiset<int> a1, a2;
	for(int i = 0; i < g[1].size() && i < k; i++) {
		a1.insert(g[1][i]);	
		cur += g[1][i];
	}
	for(int i = 0; i < g[2].size() && i < k; i++) {
		a2.insert(g[2][i]);	
		cur += g[2][i];
	}

	for(int i = 0; i <= g[3].size() && i <= k; i++) {
		if(a1.size() + i > k) {
			cur -= *(--a1.end());
			a1.erase(--a1.end());
		}
		if(a2.size() + i > k) {
			cur -= *(--a2.end());
			a2.erase(--a2.end());
		}
		if(a1.size() + i == k && a2.size() + i == k) ans = min(ans, cur);
		if(i < g[3].size()) cur += g[3][i];
	}
	cout << ans << "\n";
}

int main() {
	int t = 1;
	//cin>>t;
	for(int i = 1; i <= t; i++) {
		solve();
	}	
	return 0;
}