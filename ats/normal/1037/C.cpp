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
	string T;
	cin >> S;
	cin >> T;
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (i < N - 1) {
			if (S[i] != T[i] && S[i + 1] != T[i + 1]) {
				if (S[i] == T[i + 1] && S[i + 1] == T[i]) {
					swap(S[i], S[i + 1]);
					res++;
				}
			}
		}
		if (S[i] != T[i]) {
			S[i] = '1' - S[i] + '0';
			res++;
		}
	}
	cout << res << endl;
}