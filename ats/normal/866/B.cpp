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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,S;
	cin >> N >> S;
	vector<pair<int, int> > A;
	vector<pair<int, int> > B;
	int res = 0;
	int a, b, c;
	int k = 0;
	int k2 = 0;
	int al = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		al += a;
		if (b > c) {
			k += a;
		}
		else {
			A.push_back(make_pair(c - b, a));
		}
		if (b < c) {
			k2 += a;
		}
		else {
			B.push_back(make_pair(b - c, a));
		}
		res += a*max(b, c);
	}
	al = S-(al%S);
	if (al == S)al = 0;
	int res2 = res;
	int d = S - (k % S);
	if (d == S)d = 0;
	d = max((int)0, d - al);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		res -= A[i].first*A[i].second;
		d -= A[i].second;
		if (d <= 0) {
			res -= A[i].first*d;
			break;
		}
	}
	
	d = S - (k2 % S);
	if (d == S)d = 0;
	d = max((int)0, d - al);
	for (int i = 0; i < B.size(); i++) {
		res2 -= B[i].first*B[i].second;
		d -= B[i].second;
		if (d <= 0) {
			res2 -= B[i].first*d;
			break;
		}
	}
	cout << max(res, res2) << endl;
}