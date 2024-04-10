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
int sum(vector<int> &v, int l, int r) {
	l = max((int)0, l);
	r = min((int)v.size() - 1, r);
	l--;

	int res = v[r];
	if (l >= 0)res -= v[l];
	return res;
}
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
	int N, D, b;
	cin >> N >> D >> b;
	//vector<int> B(N);
	int res = 0;
	fenwick_tree<int> A(N);
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.add(i, a);
	}

	fenwick_tree<int> B = A;
	
	int ok = (N / 2) + 2;
	int ng = -1;
	int m = 0;
	int l, r;
	while(ok - ng>1){
		m = (ok + ng) / 2;
		bool f = true;
		int s;
		int k;
		B = A;
		l = 0;
		r = N - 1;
		int rest;
		//cerr << "m=" << m << endl;
		for (int i = m; i < N / 2; i++) {
			s = B.sum(max((int)0,i - D*(i + 1)), min(N - 1,i + D*(i + 1)));
			//cerr << max((int)0, i - D*(i + 1)) <<" "<< min(N - 1, i + D*(i + 1)) << endl;
			//cerr << "s1 "<<s << endl;
			if (s < b) {
				f = false;
				break;
			}
			rest = b;
			while (rest > 0) {
				k = B.sum(l, l);
				if (k == 0)l++;
				if (rest > k) {
					B.add(l, -k);
					rest -= k;
				}
				else {
					B.add(l, -rest);
					rest = 0;
				}
				
			}
			s = B.sum(max((int)0, N - 1 - i - D*(i + 1)), min(N - 1, N - 1 - i + D*(i + 1)));
			//cerr << "s2 " << s << endl;
			if (s < b) {
				f = false;
				break;
			}
			rest = b;
			while (rest > 0) {
				k = B.sum(r, r);
				if (k == 0)r--;
				if (rest > k) {
					B.add(r, -k);
					rest -= k;
				}
				else {
					B.add(r, -rest);
					rest = 0;
				}

			}
		}

		if (f) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	cout << ok << endl;
}