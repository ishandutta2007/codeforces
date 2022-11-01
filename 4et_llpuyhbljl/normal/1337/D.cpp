#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
const int Y = 200100;
const long long m = 998244353;
long long dp[3001];
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
long long pw(long long et, int b) {
	if (b == 0)return 1;
	long long tmp = pw(et, b / 2);
	tmp = (tmp * tmp) % m;
	if (b % 2 == 1)tmp = (tmp * et) % m;
	return tmp;
}
long long val(long long a, long long b, long long c) { return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c); }
long long solve(vector<int>v1, vector<int> v2, vector<int>v3) {
	long long res = val(v1[0], v2[0], v3[0]);
	int i2 = 0, i3 = 0;
	for (auto x : v1) {
		while (i2 + 1 < v2.size() && v2[i2 + 1] <= x)++i2;
		while (i3 + 1 < v3.size() && v3[i3] < x)++i3;
		res = min(res, val(x, v2[i2], v3[i3]));
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int sz1, sz2, sz3;
		cin >> sz1 >> sz2 >> sz3;
		vector<int>v1(sz1);
		vector<int>v2(sz2);
		vector<int>v3(sz3);
		for (auto& x : v1)cin >> x;
		for (auto& x : v2)cin >> x;
		for (auto& x : v3)cin >> x;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());
		long long res = val(v1[0], v2[0], v3[0]);
		res = min(res, solve(v1, v2, v3));
		res = min(res, solve(v1, v3, v2));
		res = min(res, solve(v2, v1, v3));
		res = min(res, solve(v2, v3, v1));
		res = min(res, solve(v3, v2, v1));
		res = min(res, solve(v3, v1, v2));
		cout << res << "\n";
	}

	return 0;
}