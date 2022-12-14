#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 1e5 + 1;

void solve() {
	map<int,bool> mp;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (mp[x] == 1)
			mp[-x] = 1;
		else
			mp[x] = 1;
	}
	cout << mp.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}