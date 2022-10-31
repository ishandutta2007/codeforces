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
	int N = S.size();
	int l = 0;
	int r = N - 1;
	string res;
	string res2;
	while (l <= r) {
		if (l == r) {
			res.push_back(S[l]);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int a = i % 2;
			int b = i / 2;
			if (S[l + a] == S[r - b]) {
				res.push_back(S[l + a]);
				if (l + a != r - b)res2.push_back(S[l + a]);
				l = l + a + 1;
				r = r - b - 1;
				break;
			}
		}
	}
	reverse(res2.begin(), res2.end());
	res += res2;
	cout << res << endl;
}