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
	int N, B;
	cin >> N >> B;


	int res = (int)1 << 60;
	
	int A = B;

	for (int i = 2; i <= A; i++) {
		if (i * i > A)i = A;
		if (A % i == 0) {

			int c = 1;
			A /= i;
			while (A % i == 0) {
				A /= i;
				c++;
			}

			int ans = 0;

			int X = i;
			while (true) {
				ans += N / X;
				double x = (double)X * (double)i;
				if (x > N + 3)break;

				X *= i;
			}

			res = min(res, ans / c);
		}
	}

	cout << res << endl;
}