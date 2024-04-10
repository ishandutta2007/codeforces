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
	int N, K;
	cin >> N >> K;
	int res = 0;
	int a, X;
	int c = 0;
	for (int i = 0; i < K; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> X;
			if (X == j + 1) {
				c++;
			}
		}
	}
	cout << N -c + 1- K + N - c << endl;
}