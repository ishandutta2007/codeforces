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
	int N, M;
	cin >> N >> M;
	vector<int> X(N);
	vector<int> Y(N);
	vector<int> A(M);
	vector<int> B(M);
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		mp[X[i] - Y[i]] = 0;
	}
	int t = 0;
	for (auto &m : mp) {
		m.second = t;
		t++;
	}
	fenwick_tree<int> ft1(t);
	fenwick_tree<int> ftY(t);
	fenwick_tree<int> ftX(t);
	for (int i = 0; i < N; i++) {
		int idx = mp[X[i] - Y[i]];
		ft1.add(idx, 1);
		ftY.add(idx, Y[i]);
		ftX.add(idx, X[i]);
	}
	vector<int> res(N, 0);
	for (int i = 0; i < N; i++) {
		int idx = mp[X[i] - Y[i]];
		res[i] += ft1.sum(0, idx) * Y[i] + ftX.sum(0, idx);
		res[i] += ft1.sum(idx + 1, t - 1) * X[i] + ftY.sum(idx + 1, t - 1);
		res[i] -= X[i] + Y[i];
	}
	for (int i = 0; i < M; i++) {
		int v = min(X[A[i]] + Y[B[i]], Y[A[i]] + X[B[i]]);
		res[A[i]] -= v;
		res[B[i]] -= v;
	}
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}