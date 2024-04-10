#include "bits/stdc++.h"
using namespace std;


struct FenwickTree {
	typedef int T;
	vector<T> v;
	FenwickTree(int n) : v(n, 0) {}
	void add(int i, T x) {
		for (; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for (-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};

long long inversionNumber(int x[], int n) {
	int *c = new int[n];
	memcpy(c, x, sizeof(*x) * n);
	sort(c, c + n);
	int m = unique(c, c + n) - c;
	FenwickTree ft(m);
	long long res = 0;
	for (int i = n - 1; i >= 0; i --) {
		int idx = lower_bound(c, c + m, x[i]) - c;
		res += ft.sum(idx);
		ft.add(idx, 1);
	}
	delete[] c;
	return res;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> perm(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &perm[i]), -- perm[i];
		int parity = inversionNumber(perm.data(), n) % 2;
		puts(parity == n % 2 ? "Petr" : "Um_nik");
	}
}