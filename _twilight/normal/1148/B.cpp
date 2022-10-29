#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>
#define ll long long

int n, m, K, ta, tb;
vector<pii> a;

boolean check(ll t) {
	int R = 0;
	while (R < (signed) a.size() && a[R].first < t)
		R++;
	int cnt = 0, ret = 1e9;
	for (int i = 0; i < R; i++) {
		cnt += a[i].second;
	} 
	ret = cnt;
	for (int i = 0, j = 0; i < R; i = j) {
		while (j < R && a[j].first == a[i].first) {
			cnt -= a[j].second;
			cnt += !a[j].second;
			j++;
		}
		ret = min(ret, cnt);
	}
	return ret <= K;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &K);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		a.emplace_back(x + ta, 0);
	}
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		a.emplace_back(x, 1);
	}
	sort(a.begin(), a.end());
	ll l = 0, r = 2e9, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (l > 2000000000) {
		puts("-1");
	} else {
		printf("%lld\n", l - 1 + tb);
	}
	return 0;
}