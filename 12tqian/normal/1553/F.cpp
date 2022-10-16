// test

#include <bits/stdc++.h>

using namespace std; 

template <class T> struct FenwickTree {
	vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.assign(n, 0);
	}

	void init(vector<T>& a) {
		n = (int)a.size();
		fwt.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) 
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		if (l > r) {
			return 0;
		}
		return sum(r) - sum(l - 1);
	}
	
	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1)) 
			fwt[idx] += delta;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int A = 3e5 + 5;
	const int B = 1100;
	int n; 
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<long long> ans(n);
	long long run = 0;
	for (int i = 0; i < n; ++i) {
		run += a[i];
		ans[i] += run * (i + 1);
	}
	vector<long long> sub(n);
	FenwickTree<int> cnt;
	cnt.init(A);
	for (int i = 0; i < n; ++i) {
		cnt.add(a[i], 1);
		for (int d = 1; d * a[i] < A; ++d) {
			sub[i] += a[i] * cnt.query(a[i] * d, A - 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] <= B) {
			for (int j = i; j < n; ++j) {
				if (a[i] < a[j]) {
					sub[j] += a[j] / a[i] * a[i];
				}
			}
		}
	}
	FenwickTree<long long> sum;
	sum.init(A);
	for (int i = 0; i < n; ++i) {
		for (int d = 1; d <= A; ++d) {
			int lb = B + 1;
			int rb = a[i] / d;
			if (lb > rb) {
				break;
			}
			sub[i] += sum.query(lb, rb);
		}
		sum.add(a[i], a[i]);
	}
	for (int i = 1; i < n; ++i) {
		sub[i] += sub[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		ans[i] -= sub[i];
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}