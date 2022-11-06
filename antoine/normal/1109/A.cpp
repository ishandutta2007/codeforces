#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 3e5 + 9;
int a[MxN + 9];

ll C2(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}

	map<int, ll> mp[2];

	for (int i = 0; i <= n; ++i)
		mp[i & 1][a[i]]++;

	ll ans = 0;
	for (map<int, ll> &occ : mp) {
		for (auto &&x : occ)
			ans += C2(x.second);
	}
	cout << ans;
	return 0;
}