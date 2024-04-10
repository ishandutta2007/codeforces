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
	int N;
	cin >> N;
	int res = 0;
	int t;
	while (N > 0) {
		
		t = N;
		for (int k = 2; k*k <= N; k++) {
			if (N%k == 0) {
				if (k == 2) {
					res += N / 2;
					N = 0;
				}
				else {
					res++;
					N -= k;
				}
				break;
			}
			
		}
		if (t == N) {
			N = 0;
			res++;
		}
	}
	cout << res << endl;
}