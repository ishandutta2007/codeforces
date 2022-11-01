#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5, INF = 1e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	map<ll, set<int>> pos;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		pos[x].insert(i);
	}
	vector<pair<int, ll>> v;
	for(auto it = pos.begin(); it != pos.end(); it++) {
		ll x = it->first;
		set<int> &s = it->second;
		while(sz(s) > 1) {
			s.erase(s.begin());
			int pos1 = *s.begin();
			s.erase(s.begin());
			pos[x + x].insert(pos1);
		}
		if(sz(s)) v.push_back({*s.begin(), x});
	}
	sort(all(v));
	cout << sz(v) << '\n';
	for(pair<int, ll> x : v) cout << x.second << ' ';
}