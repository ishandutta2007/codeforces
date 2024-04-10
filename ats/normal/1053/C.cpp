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
struct fenwick_tree {
	vector<int> x;
	fenwick_tree(int n) : x(n, 0) { }
	int sum(int i, int j) {
		if (i == 0) {
			int S = 0;
			for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
			return S;
		}
		else return sum(0, j) - sum(0, i - 1);
	}
	void add(int k, int a) {
		for (; k < x.size(); k |= k + 1) x[k] += a;
	}
};
struct fenwick_tree_mod {
	vector<int> x;
	fenwick_tree_mod(int n) : x(n, 0) { }
	int sum(int i, int j) {
		if (i == 0) {
			int S = 0;
			for (j; j >= 0; j = (j & (j + 1)) - 1) S = (S + x[j]) % MOD;
			return S;
		}
		else {
			int S = sum(0, j) - sum(0, i - 1);
			if (S < 0)S += MOD;
			return S;
		}
	}
	void add(int k, int a) {
		for (; k < x.size(); k |= k + 1) x[k] = (x[k] + a) % MOD;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> W(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] -= i;
	}
	fenwick_tree ft(N);
	fenwick_tree_mod aw(N);
	for (int i = 0; i < N; i++) {
		cin >> W[i];
		ft.add(i, W[i]);
		aw.add(i, (W[i] * A[i]) % MOD);
	}
	int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (a < 0) {
			a = -a;
			a--;
			ft.add(a, b - W[a]);
			int t = ((b - W[a])*A[a]) % MOD;
			if (t < 0)t += MOD;
			aw.add(a, t);
			W[a] = b;
		}
		else {
			a--;
			b--;
			if (a == b) {
				cout << 0 << endl;
				continue;
			}
			int l = a;
			int r = b;
			int m;
			int all = ft.sum(a, b);
			while (r - l > 1) {
				m = (r + l) / 2;
				if (2 * ft.sum(a, m) < all) {
					l = m;
				}
				else {
					r = m;
				}
			}
			if (2 * ft.sum(a, l) >= all)r = l;
			res = ((A[r] * (ft.sum(a, r) % MOD)) % MOD) - aw.sum(a, r);
			res = (res - (((A[r] * (ft.sum(r, b) % MOD)) % MOD) - aw.sum(r, b))) % MOD;
			if (res < 0)res += MOD;
			cout << res << endl;
		}
	}
}