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
struct P {
	int d;
	int u;
	bool operator<(const P& right) const {
		if (right.d*d > 0) {
			return u * right.d < right.u * d;
		}
		else {
			return u * right.d > right.u * d;
		}
	}
	bool operator==(const P& right) const {
		return u * right.d == right.u * d;
	}
	
};
int mergecount(vector<P> &a) {
	int count = 0;
	int n = a.size();
	if (n > 1) {
		vector<P> b(a.begin(), a.begin() + n / 2);
		vector<P> c(a.begin() + n / 2, a.end());
		count += mergecount(b);
		count += mergecount(c);
		for (int i = 0, j = 0, k = 0; i < n; ++i)
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] < c[k])   a[i] = b[j++];
			else { a[i] = c[k++]; count += n / 2 - j; }
	}
	return count;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, W;
	cin >> N >> W;
	vector<pair<P, P> > A;
	int res = 0;
	int x, v;
	for (int i = 0; i < N; i++) {
		cin >> x >> v;
		A.push_back(make_pair(P{ x,v - W },P{ -x,v + W }));
	}
	sort(A.begin(), A.end());
	vector<P> C(N);
	for (int i = 0; i < N; i++) {
		C[i] = A[i].second;
		C[i].d *= -1;
		//cerr << C[i].u << " " << C[i].d << endl;
	}
	
	cout << mergecount(C) << endl;
}