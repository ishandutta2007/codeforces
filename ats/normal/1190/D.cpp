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
void za(vector<int> &v) {
	int N = v.size();
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		mp[v[i]] = 0;
	}
	int c = 0;
	for (auto &m : mp) {
		m.second = c;
		c++;
	}
	for (int i = 0; i < N; i++) {
		v[i] = mp[v[i]];
	}

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > A(N);
	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];

	}
	za(x);
	za(y);
	for (int i = 0; i < N; i++) {
		//cerr << x[i] << " " << y[i] << endl;
		A[y[i]].push_back(x[i]);
	}
	fenwick_tree<int> ft(N);
	int res = 0;
	for (int i = N - 1; i >= 0; i--) {
		sort(A[i].begin(), A[i].end());

		for (int j = 0; j < A[i].size(); j++) {
			int L = ft.sum(0, A[i][j] - 1);
			int R;
			if (j + 1 < A[i].size()) {
				R = ft.sum(A[i][j] + 1, A[i][j + 1] - 1);
			}
			else {
				R = ft.sum(A[i][j] + 1, N - 1);
			}
			res += (L + 1) * (R + 1);
			if (ft.sum(A[i][j], A[i][j]) == 0) {
				ft.add(A[i][j], 1);
			}
		}


	}

	cout << res << endl;
}