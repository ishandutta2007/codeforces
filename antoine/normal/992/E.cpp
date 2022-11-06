#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct FT {
	int n;
	vector<ll> vals;
	FT(const int n) :
			n(n), vals(vector<ll>(n + 1, 0)) {
	}

	void update(int i, const ll x) {
		for (++i; i <= n; i += i & -i)
			vals[i] += x;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, Q;
	cin >> n >> Q;

	FT ft(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ft.update(i, x);
	}
	while (Q--) {

		{
			int i, x;
			cin >> i >> x;
			--i;
			const ll dx = x - ft.query(i, i);
			ft.update(i, dx);
		}

		int ans = -1;

		if (ft.query(0, 0) == 0)
			ans = 1;
		else
			for (int i = 1; i < n; ++i) {
				const ll sum = max(1LL, ft.query(i - 1));
				int lo = i, hi = n;
				while (lo < hi) {
					const int mid = (lo + hi) >> 1;
					if (ft.query(mid) < (sum << 1))
						lo = mid + 1;
					else
						hi = mid;
				}

				i = lo;
				if (i < n && ft.query(lo) == ft.query(lo - 1) * 2) {
					ans = lo + 1;
					break;
				}
			}

		cout << ans << '\n';
	}
	return 0;
}