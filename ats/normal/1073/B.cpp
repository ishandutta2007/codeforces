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
	int N;
	cin >> N;
	vector<int> res(N);
	map<int, int> mp;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		mp[a] = i;
	}
	int mx = -1;
	for (int i = 0; i < N; i++) {
		cin >> a;
		res[i] = max((int)0, mp[a] - mx);
		mx = max(mx, mp[a]);
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}