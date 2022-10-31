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
	int L, R, D;
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		cin >> L >> R >> D;
		if (D < L) {
			res[i] = D;
		}
		else {
			int t = R / D;
			while (t * D <= R)t++;
			res[i] = t * D;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}