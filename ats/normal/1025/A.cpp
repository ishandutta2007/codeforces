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
	string S;
	cin >> S;
	string res = "No";
	if (N == 1)res = "Yes";
	map<char, int> mp;
	for (int i = 0; i < N; i++) {
		mp[S[i]]++;
	}
	for (auto m : mp) {
		if (m.second >= 2)res = "Yes";
	}
	cout << res << endl;
}