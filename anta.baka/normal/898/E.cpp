#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline int f(int x) {
	int y = sqrt(x + .0);
	if(y * y == x) return 0;
	return int(min(abs(x - y*y), abs(x - (y+1)*(y+1))));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a, b; // sq, !sq
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		int y = f(x);
		if(y == 0) a.push_back(x == 0 ? 2 : 1);
		else b.push_back(y);
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	ll ans = 0;
	while(a.size() > b.size()) {
		ans += a.back(); a.pop_back(); b.push_back(0);
	}
	while(b.size() > a.size()) {
		ans += b.back(); b.pop_back(); a.push_back(0);
	}
	cout << ans;
}