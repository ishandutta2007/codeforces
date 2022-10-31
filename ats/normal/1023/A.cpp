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
	string S, T;
	cin >> S >> T;
	int p = -1;
	for (int i = 0; i < N; i++) {
		if (S[i] == '*')p = i;
	}
	if (p == -1) {
		if (S == T) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		//cerr << p << endl;
		string res = "NO";
		if (N - 1 <= M) {
			if (S.substr(0, p) == T.substr(0, p)) {
				//cerr << S.substr(p + 1, N - 1 - p) << endl;
				//cerr << T.substr(M - (N - 1 - p)) << endl;
				if (S.substr(p + 1, N - 1 - p) == T.substr(M - (N - 1 - p), N - 1 - p)) {
					res = "YES";
				}
			}
		}
		cout << res << endl;
	}

}