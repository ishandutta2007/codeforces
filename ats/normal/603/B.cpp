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
vector<int> V;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int P, K;
	cin >> P >> K;
	int res = 1;
	V.resize(P, 0);
	for (int i = 1; i < P; i++) {
		if (V[i] == 0) {
			res = (res * P) % MOD;
			int cur = i;
			while (true) {
				if (V[cur] == 1)break;
				V[cur] = 1;
				cur = (cur * K) % P;
			}
		}
	}
	if (K == 1) {
		res = (res * P) % MOD;
	}

	cout << res << endl;
}