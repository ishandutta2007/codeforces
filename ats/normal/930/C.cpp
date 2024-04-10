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
int INF = (int)1 << 62;
void getLIS(vector<int> &a,vector<int> &v)
{
	int N = a.size();
	vector<int> dp(N, INF);
	v.push_back(0);
	for (int i = 0; i < N; ++i) {
		*upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
		v.push_back(lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin());
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(M + 1, 0);
	int res = 0;
	int l, r;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		l--;
		A[l]++;
		A[r]--;
	}
	for (int i = 0; i < M; i++) {
		A[i + 1] += A[i];
	}
	A.pop_back();
	vector<int> v;
	getLIS(A, v);
	reverse(A.begin(), A.end());
	vector<int> v2;
	getLIS(A, v2);
	reverse(v2.begin(), v2.end());
	for (int i = 0; i < v.size(); i++) {
		res = max(res, v[i] + v2[i]);
	}
	cout << res << endl;
}