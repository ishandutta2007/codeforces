#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 37;

ll a[maxn], fen[maxn + 100];

ll get (int idx) {
	ll ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

ll get (int l, int r) {
	return get (r) - get (l - 1);
}

void change (int idx, ll x) {
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += x;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		change (i, a[i]);
	}
	ll cnt = n, sum = get (1, n);
	ll ans = 0;
	while (cnt) {
//		cout << ans << " " << sum << " " << t << endl;
		if (sum <= t) {
			ans += (t / sum) * cnt;
			t %= sum;
		}
		int lo = 0, hi = n;
		while (hi - lo > 1) {
			int mid = (hi + lo) >> 1;
//			cout << mid << " -> " << get (1, mid) << endl;
			if (get (1, mid) > t)
				hi = mid;
			else
				lo = mid;
		}
//		cout << hi << endl;
		change (hi, -a[hi]);
		sum = get (1, n);
		cnt --;
	}
	cout << ans << endl;
}