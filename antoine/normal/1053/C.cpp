#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

template<int sz> struct FT {
	array<ll, sz + 1> v;
	FT() {
		fill(v.begin(), v.end(), 0);
	}

	void update(int i, const ll a) {
		for (++i; i < (int)v.size(); i += i & -i) {
			v[i] += a;
		}
	}

	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < (int)v.size() - 1);
		ll sum = 0;
		for (++i; i; i -= i & -i) {
			sum += v[i];
		}
		return sum;
	}
	ll query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};


// FT on w
// FT on w[i] * (a[i] - i)

const int mod = 1e9 + 7;
const int MaxN = (int)2e5;
int n, q;
int a[MaxN];
ll w[MaxN];
FT<MaxN> ftw;
FT<MaxN> ftp;

void setW(const int i, const ll val) {
	assert(0 <= i && i < n);
	w[i] = val;
	ftw.update(i, (- ftw.query(i, i) + val));
	ftp.update(i, (- ftp.query(i, i) + val * (a[i] - i)) % mod);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		setW(i, x);
	}
	

	while(q--) {
		int x, y;
		cin >> x >> y;
		if (x < 0)
			setW(-x - 1, y);
		else {
			--x, --y;

			int lo = x;
			int hi = y;
			const ll total = ftw.query(x, y);
			while (lo < hi) {
				const int mid = (lo + hi) >> 1;
				if (ftw.query(x, mid) >= ((total + 1) >> 1))
					hi = mid;
				else
					lo = mid + 1;
			}

			assert(lo == hi);
			const int k = lo;

			const ll sumL = ftw.query(x, k - 1);
			const ll sumR = ftw.query(k + 1, y);
			// assert(w[k] == ftw.query(k, k));
			// assert(sumL + w[k] + sumR == total);

			ll ans = 0;
			ans += sumL % mod * (a[k] - k) % mod - ftp.query(x, k - 1);
			ans += sumR % mod * (k - a[k]) % mod + ftp.query(k + 1, y);
			((ans %= mod) += mod) %= mod;
			cout << ans << '\n';
		}
	}
	return 0;
}