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
int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	int A, B;
	cin >> A >> B;

	int mn = N * K;
	int mx = 1;
	int g;
	for (int i = 0; i < N; i++) {
		g = gcd(N * K, abs(A + B + i * K));
		mn = min(mn, N * K / g);
		mx = max(mx, N * K / g);
		g = gcd(N * K, abs(-A + B + i * K));
		mn = min(mn, N * K / g);
		mx = max(mx, N * K / g);
		g = gcd(N * K, abs(-A - B + i * K));
		mn = min(mn, N * K / g);
		mx = max(mx, N * K / g);
		g = gcd(N * K, abs(A - B + i * K));
		mn = min(mn, N * K / g);
		mx = max(mx, N * K / g);

	}

	cout << mn << " " << mx << endl;
}