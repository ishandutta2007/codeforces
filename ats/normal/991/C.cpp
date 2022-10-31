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
int cnt(int n, int k) {
	int res = 0;
	while (n > 0) {
		if (n > k) {
			n -= k;
			res += k;
		}
		else {
			res += n;
			n = 0;
		}
		n -= n / 10;
	}
	return res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int u = (int)1e17;
	int d = 0;
	int m;
	while(u-d > 1){
		m = ((u - d) / 2) + d;
		if (cnt(N, m) * 2 >= N) {
			u = m;
		}
		else {
			d = m;
		}
	}
	//cerr << cnt(N, u) << endl;
	//cerr << cnt(N, u - 1) << endl;
	cout << u << endl;
}