#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int inf = 1e9;
const int mod = 1e9 + 7;

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], t[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	map<int, multiset<int>> costs;
	map<int, int> sums;
	for(int i = 0; i < n; i++) {
		costs[a[i]].insert(t[i]);
		sums[a[i]] += t[i];
	}
	int add = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int A = begin(costs)->first;
		sums[A] -= *costs[A].rbegin();
		costs[A].erase(prev(end(costs[A])));
		ans += sums[A];
		add++;
		if(costs[A].empty()) {
			costs.erase(A);
			add = 0;
		} else if(costs.size() > 1) {
			int B = next(begin(costs))->first;
			if(A + add == B) {
				if(costs[A].size() > costs[B].size()) {
					costs[A].swap(costs[B]);
				}
				for(auto it: costs[A]) {
					costs[B].insert(it);
				}
				sums[B] += sums[A];
				costs.erase(A);
				add = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}