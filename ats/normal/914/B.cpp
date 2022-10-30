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
	map<int, int>mp;
	string res = "Agasa";
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		mp[a]++;
	}
	for (auto m : mp) {
		if (m.second % 2 == 1) {
			res = "Conan";
		}
	}
	cout << res << endl;
}