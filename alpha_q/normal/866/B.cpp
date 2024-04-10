#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

int n, p, id[N];
ll _s[N];
ll s[N], a[N], b[N];
ll tot, k, rem;

bool cmp (int i, int j) {
	return a[i] - b[i] == a[j] - b[j] ? a[i] > a[j] : a[i] - b[i] > a[j] - b[j];
}

ll val (ll x) {
	ll cost = 0, one = p * x;
	memcpy(s, _s, sizeof _s);
	for (int _i = 1; _i <= n; ++_i) {
		int i = id[_i];
		if (one == 0 or (one <= rem and a[i] < b[i])) {
			one = 0;
			cost += s[i] * b[i];
		} else if (s[i] <= one) {
			if (a[i] >= b[i]) {
				one -= s[i];
				cost += s[i] * a[i];
			} else {
				if (one - s[i] > rem) {
					one -= s[i];
					cost += s[i] * a[i];
				} else {
					cost += (one - rem) * a[i];
					s[i] -= (one - rem);
					cost += s[i] * b[i];
					one = 0;
				}
			}
		} else {
			if (a[i] >= b[i]) {
				cost += one * a[i];
				s[i] -= one;
				cost += s[i] * b[i];
				one = 0;
			} else {
				cost += (one - rem) * a[i];
				s[i] -= (one - rem);
				cost += s[i] * b[i];
				one = 0;
			}
		}
	}
	return cost;
}

int main() {
  scanf("%d %d", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld", _s + i, a + i, b + i);
    tot += _s[i];
  }
  k = (tot + p - 1) / p;
  rem = k * p - tot;
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, cmp);
  // cout << k << endl;
  // for (int i = 0; i <= k; ++i) {
  // 	cout << i << " --> " << val(i) << endl;
  // }
  ll lo = 0, hi = k - 1;
  while (lo < hi) {
  	ll mid = lo + hi >> 1;
  	// cout << lo << " " << hi << endl;
  	// cout << val(mid) << " " << val(mid + 1) << endl;
  	if (val(mid) < val(mid + 1)) {
  		lo = mid + 1;
  	} else {
  		hi = mid;
  	}
  }
  ll ans = max(val(lo), val(k));
  printf("%lld\n", ans);
  return 0; 
}