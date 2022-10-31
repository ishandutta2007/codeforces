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
int solve(int A, int B, int C, int L) {
	int res = 0;
	for (int i = 0; i <= L; i++) {
		int a = A + i - B - C;
		int t = min(a, L - i);
		if(t >= 0)res += (t + 2)*(t + 1) / 2;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B, C, L;
	cin >> A >> B >> C >> L;
	int res = 0;
	for (int i = 0; i <= L; i++) {
		res += (L - i + 2) * (L - i + 1) / 2;
	}
	//cerr << res << endl;
	res -= solve(A, B, C, L);
	res -= solve(B, C, A, L);
	res -= solve(C, A, B, L);

	cout << res << endl;
}