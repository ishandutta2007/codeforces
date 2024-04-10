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
	int N, M;
	cin >> N >> M;

	int md = N % M;
	int dv = N / M;
	int res = 0;
	int k = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (((i + 1) * (i + 1) + (j + 1) * (j + 1)) % M == 0) {
				k = 1;
				k *= dv + (i < md ? 1 : 0);
				k *= dv + (j < md ? 1 : 0);
				res += k;
			}
		}
	}
	cout << res << endl;
}