#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = sz(s);
	vi p(n);
	for (int i = 0; i < n; i++) {
		p[i] = (s[i] - '0') + (i ? p[i - 1] : 0);
	}
	const int NADKEK = 350;
	ll ans = 0;
	for (int k = 1; k < NADKEK; k++) {
		vi podkek(n + 1);
		podkek[n] = -1;
		for (int i = 0; i < n; i++) {
			podkek[i] = i - k * p[i];
		}
		sort(all(podkek));
		int cnt = 1;
		for (int i = 1; i < n + 1; i++) {
			if (podkek[i] != podkek[i - 1]) {
				ans += 1LL * cnt * (cnt - 1) / 2;
				cnt = 0;
			}
			cnt++;
		}
		ans += 1LL * cnt * (cnt - 1) / 2;
	}
	vi nxt1(n);
	nxt1[n - 1] = n;
	for (int i = n - 2; i >= 0; i--) {
		nxt1[i] = (s[i + 1] == '1' ? i + 1 : nxt1[i + 1]);
	}
	for (int l = 0; l < n; l++) {
		int r1 = l;
		if (s[l] != '1') {
			r1 = nxt1[l];
		}
		for (int c1 = 1; c1 <= n / NADKEK && r1 < n; c1++) {
			int rem = (l - 1);
			if (rem < 0) {
				rem += c1;
			}
			int LB = max(r1, NADKEK * c1 + l - 1);
			ans += max(0, (nxt1[r1] - 1 - rem + c1) / c1 - max(0, LB - rem - 1 + c1) / c1);
			r1 = nxt1[r1];
		}
	}
	cout << ans;
}