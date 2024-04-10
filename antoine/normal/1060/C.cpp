#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> get(const int n) {
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<ll> cs(n + 1, 0);
	partial_sum(a.begin(), a.end(), cs.begin() + 1);
	vector<ll> res(n + 1, 1LL << 30);
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			res[len] = min(res[len], cs[i + len] - cs[i]);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a = get(n);
	vector<ll> b = get(m);

	ll x;
	cin >> x;
	int res = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i] * b[j] <= x)
				res = max(res, i*j);

	cout << res << '\n';
	return 0;
}