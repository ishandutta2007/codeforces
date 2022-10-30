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
	int k, d, t;
	cin >> k >> d >> t;
	int x = k / d;
	if (x*d < k) {
		x++;
	}
	int l = x*d - k;
	double a = k + (l / 2.0);
	int s = ((double)t / a);
	double res = 0;
	res = s*(k + l);
	double r = t - a*s;
	if (r < k) {
		res += r;
	}
	else {
		res += k;
		res += (r - k) * 2.0;
	}
	cout << setprecision(15) <<  res << endl;
}