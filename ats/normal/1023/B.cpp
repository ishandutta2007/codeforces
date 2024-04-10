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
	int mn = max((int)1, M - N);
	int mx = min(N, (M - 1) / 2);
	//cerr << mn << " " << mx << endl;
	cout << max((int)0, mx - mn + 1) << endl;
}