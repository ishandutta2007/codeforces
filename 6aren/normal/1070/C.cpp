#include<bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int base = (1<<20);

int n, k, m;
vector<pair<int, int>> d[N];
long long ans = 0, cnt[base * 2 + 5], sum[base * 2 + 5];

void upd(int c, int p) {
	long long plus = 1LL * c * p;
	for (p += base; p > 0; p >>= 1) {
		cnt[p] += c;
		sum[p] += plus;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, c, p;
		cin >> l >> r >> c >> p; 
		d[l].push_back(make_pair(c, p));
		d[r + 1].push_back(make_pair(-c, p));
	}
	for (int i = 1; i <= n; i++) {
		for (auto u : d[i]) {
			upd(u.first, u.second);
		}
		int u = 1;
		int kk = k;
		while (u < base) {
			if (kk < cnt[2 * u]) {
				u *= 2;
			} else {
				ans += sum[2 * u];
				kk -= cnt[2 * u];
				u = u * 2 + 1;
			}
		}
		ans += 1LL * min(1LL * kk, cnt[u]) * (u - base);
	}
	cout << ans;
	return 0;
}