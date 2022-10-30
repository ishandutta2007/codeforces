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
vector<int> dp(1000005, -1);
int rec(int a) {
	if (dp[a] == -1) {
		int x = 1;
		int b = a;
		while (a > 0) {
			if (a % 10 != 0) {
				x *= (a % 10);
			}
			a /= 10;
		}
		dp[b] = rec(x);
		return dp[b];
	}
	else {
		return dp[a];
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin >> Q;
	int l, r, k;
	
	vector<fenwick_tree<int> > A(10, fenwick_tree<int>(1000005));
	for (int i = 0; i < 10; i++) {
		dp[i] = i;
	}
	for (int i = 0; i <= 1000000; i++) {
		if (dp[i] == -1) {
			rec(i);
		}
	}
	for (int i = 0; i <= 1000000; i++) {
		A[dp[i]].add(i, 1);
	}
	for (int i = 0; i < Q; i++) {
		cin >> l >> r >> k;
		cout << A[k].sum(l, r) << endl;
	}
	//cout << res << endl;
}