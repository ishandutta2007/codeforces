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
	map<char, int> mp;
	for (int i = 0; i < N; i++) {
		mp[S[i]]++;
	}
	string res;
	for (char a = 'a'; a <= 'z'; a++) {
		int c = mp[a];
		for (int i = 0; i < c; i++) {
			res.push_back(a);
		}
	}
	cout << res << endl;
}