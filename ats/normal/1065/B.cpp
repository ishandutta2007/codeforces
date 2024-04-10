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
	int mn = max((int)0, N - 2 * M);
	int mx;
	for (int i = 0; i <= N; i++) {
		int n = N - i;
		if (n*(n - 1) >= 2 * M) {
			mx = i;
		}
	}
	cout << mn << " " << mx << endl;
}