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
	int N, K;
	cin >> N >> K;
	int mask = (1 << K) - 1;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> pre(N + 1, 0);
	map<int, int> mp;
	vector<int> v;
	v.push_back(0);
	mp[0]++;
	int cur = 0;
	for (int i = 0; i < N; i++) {
		cur ^= A[i];
		mp[cur]++;
		v.push_back(cur);
		//cerr << cur << endl;
	}
	int all = (N*(N + 1)) / 2;
	for (auto s : v) {
		if (mp.count(s) != 0) {
			int num = mp[s] + mp[mask ^ s];
			mp.erase(s);
			mp.erase(mask ^ s);
			int a = num / 2;
			int b = num - a;
			res += a*(a - 1) / 2;
			res += b*(b - 1) / 2;
		}
	}
	cout << all - res << endl;
}