#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }


template <class T> struct Fenwick {
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
	int N, K, A, B, Q;
	cin >> N >> K >> A >> B >> Q;
	Fenwick<int> ftB(N + 3);
	Fenwick<int> ftA(N + 3);
	vector<int> res;
	int t;
	int d, a;
	for (int i = 0; i < Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> d >> a;
			{
				int X = ftB.sum(d, d + 1);
				int Y = min(B, X + a);
				if (Y - X > 0) {
					ftB.add(d, Y - X);
				}
			}
			{
				int X = ftA.sum(d, d + 1);
				int Y = min(A, X + a);
				if (Y - X > 0) {
					ftA.add(d, Y - X);
				}
			}
		}
		else {
			cin >> d;
			int ans = 0;
			ans += ftB.sum(d);
			ans += ftA.sum(d + K, N + 3);
			res.push_back(ans);
		}

	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}