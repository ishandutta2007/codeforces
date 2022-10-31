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
	int N, M;
	cin >> N >> M;
	vector<int> A(N, 0);
	map<int, int> mp;
	int a;
	mp[0] = N;
	int cur = 0;
	string res;
	for (int i = 0; i < M; i++) {
		cin >> a; a--;
		mp[A[a]]--;
		A[a]++;
		mp[A[a]]++;
		if (mp[cur] == 0) {
			cur++;
			res.push_back('1');
		}
		else {
			res.push_back('0');
		}
	}
	cout << res << endl;
}