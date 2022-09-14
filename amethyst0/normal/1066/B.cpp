#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1010;

int v[maxn];

int dp[maxn]; //  pos -    .

// :  pos = n -     ,   0.

//   n,  -   0  pos.
//    pos  n - 1.

int main() {
	int n, r;
	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[n] = 0;

	for (int pos = n - 1; pos >= 0; pos--) {
		//pos -   ,   

		int ans = (int)1e9;

		for (int i = 0; i < n; i++) {
			if (v[i] == 1 && i - r + 1 <= pos && pos <= i + r - 1) {
				int rm = i + r;

				if (rm > n) {
					rm = n;
				}

				ans = min(ans, 1 + dp[rm]);//   rm  n - 1.
			}
		}

		dp[pos] = ans;
	}

	if (dp[0] == (int)1e9) {
		cout << -1 << endl;
	}
	else {
		cout << dp[0] << endl;
	}

	//system("pause");
}