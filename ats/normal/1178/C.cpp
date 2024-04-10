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
int MOD = 998244353;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int W, H;
	cin >> W >> H;
	int res = 1;
	for (int i = 0; i < W + H; i++) {
		res = (res * 2) % MOD;
	}
	cout << res << endl;
}