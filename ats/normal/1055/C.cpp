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
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int L[2];
	int R[2];
	int T[2];
	cin >> L[0] >> R[0] >> T[0]; 
	cin >> L[1] >> R[1] >> T[1];
	int k = gcd(T[0], T[1]);
	//L[0] + x*k = L[1];
	int x = (L[1] - L[0]) / k;
	int l = L[0] + (x - 3) * k;
	int r = L[0] + (x + 3) * k;
	int res = 0;
	for (int ll = l; ll <= r; ll += k) {
		//cerr << ll << endl;
		res = max(res, min(R[1], ll + R[0] - L[0]) - max(L[1], ll) + 1);
	}
	cout << res << endl;
}