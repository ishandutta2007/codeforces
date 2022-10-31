#include <bits/stdc++.h>

using namespace std;
#define int long long
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T> >;

template <class T>
struct Fenwick {
	int n;
	V<T> seg;
	Fenwick(int _n = 0) : n(_n), seg(n + 1, 0) {}
	/// ix
	void add(int i, T x) {
		i++;
		while (i <= n) {
			seg[i] += x;
			i += i & -i;
		}
	}
	/// [0, i)sum
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += seg[i];
			i -= i & -i;
		}
		return s;
	}
	/// [a, b)sum
	T sum(int a, int b) { return sum(b) - sum(a); }
	/// sum[0, idx) >= xidx(sum[0, n) < x  n+1)
	int sum_lower_bound(T x) {
		if (x <= 0) return 0;
		int res = 0, len = 1;
		while (2 * len <= n) len *= 2;
		for (; len >= 1; len /= 2) {
			if (res + len <= n && seg[res + len] < x) {
				res += len;
				x -= seg[res];
			}
		}
		return res + 1;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> pos(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		pos[A[i]] = i;
	}
	vector<int> res(N);
	{
		Fenwick<int> ft(N);
		for (int i = 0; i < N; i++) {
			res[i] = ft.sum(pos[i], N);
			if (i > 0) res[i] += res[i - 1];
			//cerr << i << " " << res[i] << endl;
			ft.add(pos[i], 1);
		}
	}
	{
		Fenwick<int> ft1(N);
		Fenwick<int> ft2(N);
		for (int i = 0; i < N; i++) {
			ft1.add(pos[i], 1);
			ft2.add(pos[i], pos[i]);
			int x = ft1.sum_lower_bound((i / 2) + 1) - 1;
			int L = (i + 2) / 2;
			int R = i + 1 - L;
			//cerr << i << " " << x << " " << L << " " << R << endl;
			res[i] += L * x - ft2.sum(0, x + 1);
			res[i] += ft2.sum(x + 1, N) - R * x;
			res[i] -= (L * (L - 1)) / 2;
			res[i] -= (R * (R + 1)) / 2;
		}
	}

	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << res[i];
	}
	cout << endl;
}