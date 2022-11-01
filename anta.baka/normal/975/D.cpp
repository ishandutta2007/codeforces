#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	map<ll, int> cnt;
	map<pair<int, int>, int> same;
	for(int i = 0; i < n; i++) {
		int x, vx, vy; cin >> x >> vx >> vy;
		cnt[ll(a) * vx - vy]++;
		same[{vx, vy}]++;
	}
	ll ans = 0;
	for(auto p : cnt) ans += p.second * ll(p.second - 1);
	for(auto p : same) ans -= p.second * ll(p.second - 1);
	cout << ans;
}