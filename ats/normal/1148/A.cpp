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
	int A, B, C;
	cin >> A >> B >> C;
	
	int res = 2 * C + 2 * min(A, B);

	if (A != B)res++;

	cout << res << endl;
}