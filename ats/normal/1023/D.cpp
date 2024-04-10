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
	vector<vector<int> > A(Q);
	vector<int> res(N);
	int a;
	fenwick_tree<int> ft(N);
	int n0 = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		res[i] = a;
		if (a == 0) {
			n0++;
			ft.add(i, 1);
		}
		else {
			a--;
			A[a].push_back(i);
		}
	}
	bool ok = true;
	for (int i = Q - 1; i >= 0; i--) {
		if ((int)A[i].size() > 0) {
			int mn = N;
			int mx = -1;
			for (int j = 0; j < (int)A[i].size(); j++) {
				mn = min(mn, A[i][j]);
				mx = max(mx, A[i][j]);
				ft.add(A[i][j], 1);
			}
			if (ft.sum(mn, mx) != mx - mn + 1) {
				ok = false;
			}
		}
	}
	if ((int)A[Q - 1].size() == 0) {
		if (n0 == 0) {
			ok = false;
		}
		else {
			for (int i = 0; i < N; i++) {
				if (res[i] == 0) {
					res[i] = Q;
					break;
				}
			}
		}
	}
	if (ok) {
		cout << "YES" << endl;
		int b = 0;
		for (int i = 0; i < N; i++) {
			if (res[i] == 0) {
				res[i] = b;
			}
			else {
				b = res[i];
			}
		}
		b = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (res[i] == 0) {
				res[i] = b;
			}
			else {
				b = res[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (i > 0)cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}