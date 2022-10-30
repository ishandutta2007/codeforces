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
	int N, M, K;
	cin >> N >> M >> K;
	if ((N * M * 2) % K == 0 && K >= 2) {
		int a = gcd(N, (N*M * 2) / K);
		int b = (N*M * 2)/ (K * a);
		if (b > M) {
			b /= 2;
			a *= 2;
		}
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << a << " 0" << endl;
		cout << "0 " << b << endl;

	}
	else {
		cout << "NO" << endl;
	}
}