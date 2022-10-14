#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

vector <pair<int, int>> fact(int n) {
	int i = 2;
	vector <pair<int, int>> p;
	for (; i * i <= n; i++) {
		if (n % i == 0) {
			p.pb({i, 1});
			n /= i;
		}
		while (n % i == 0) {
			p.back().se++;
			n /= i;
		}
	}
	if (n != 1) {
		p.pb({n, 1});
	}
	return p;
}

long long my_pow(long long n, int m) {
	if (m == 0) {
		return 1;
	}
	int now = my_pow(n, m / 2);
	if (m % 2 == 0) {
		return now * now;
	}
	return now * now * n;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (auto &c : a) {
		cin >> c;
	}
	map <int, int> cnt;
	vector <int> M(1e5 + 10);
	vector <pair<int, int>> now(0);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		now = fact(a[i]);
		long long l = 1;
		long long h = 1;
		for (auto &c : now) {
			h *= my_pow(c.fi, c.se % k);
			M[c.fi] = max(M[c.fi], c.se);
		}
		for (auto &c : now) {
			l *= my_pow(c.fi, (k - c.se % k) % k);
			if ((k - c.se % k) % k > M[c.fi]) {
				l = -1;
				break;
			}
		}
		ans += cnt[l];
		cnt[h]++;
	}
	cout << ans;
	return 0;
}