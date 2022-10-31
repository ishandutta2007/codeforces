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
	string S;
	cin >> S;
	int L = (int)S.size() - 10;
	string res = "NO";
	if ((int)S.size() >= 10) {
		for (int i = 0; i <= 10; i++) {
			string T = S.substr(0, i);
			T += S.substr(i + L, 10 - i);
			if (T == "CODEFORCES")res = "YES";
		}
	}
	cout << res << endl;
}