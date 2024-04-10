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
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	int res = N - (A + B - C);
	if (res <= 0)res = -1;
	if (N == 0)res = -1;
	if (min(A, B) < C)res = -1;
	cout << res << endl;
}