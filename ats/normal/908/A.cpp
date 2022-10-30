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
	int res = 0;
	int k;
	for (int i = 0; i < S.size(); i++) {
		k = S[i] - '0';
		if (k >= 0 && k < 10) {
			if (k % 2 == 1) {
				res++;
			}
		}
		else {
			if (S[i] == 'a' || S[i] == 'i' || S[i] == 'u' || S[i] == 'e' || S[i] == 'o') {
				res++;
			}
		}
	}
	cout << res << endl;
}