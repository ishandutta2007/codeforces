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
#include <assert.h>
using namespace std;
int MOD = 1000000007;
int Block = 1000;
template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int i, int j) {
		if (i == 0) {
			T S = 0;
			for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
			return S;
		}
		else return sum(0, j) - sum(0, i - 1);
	}
	void add(int k, T a) {
		for (; k < x.size(); k |= k + 1) x[k] += a;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> revA(N);
	vector<int> res;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i]--;
		revA[A[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i]; B[i]--;
	}
	vector<int> X(N);
	for (int i = 0; i < N; i++) {
		X[i] = i / Block;
	}
	int bs = X.back() + 1;
	vector<fenwick_tree<int> > ft(bs, fenwick_tree<int>(N));
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		v[i] = revA[B[i]];
		ft[X[i]].add(revA[B[i]], 1);
	}
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--; r1--; l2--; r2--;
			int L = X[l2];
			int R = X[r2];
			int ans = 0;
			if (L == R) {
				for (int j = l2; j <= r2; j++) {
					if (l1 <= v[j] && v[j] <= r1) {
						ans++;
					}
				}
			}
			else {
				for (int j = L + 1; j <= R - 1; j++) {
					ans += ft[j].sum(l1, r1);
				}

				for (int j = l2; j < N && X[j] == X[l2]; j++) {
					if (l1 <= v[j] && v[j] <= r1) {
						ans++;
					}
				}
				for (int j = r2; j >= 0 && X[j] == X[r2]; j--) {
					if (l1 <= v[j] && v[j] <= r1) {
						ans++;
					}
				}
			}
			res.push_back(ans);
		}
		else {
			int x, y;
			cin >> x >> y; x--; y--;
			int xx = revA[B[x]];
			//assert(v[x] == xx);
			int yy = revA[B[y]];
			//assert(v[y] == yy);
			ft[X[x]].add(xx, -1);
			ft[X[x]].add(yy, 1);
			ft[X[y]].add(yy, -1);
			ft[X[y]].add(xx, 1);
			swap(v[x], v[y]);
			swap(B[x], B[y]);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}