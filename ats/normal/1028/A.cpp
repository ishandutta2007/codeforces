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
	vector<string> S(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int x = 0;
	int y = 0;
	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'B') {
				x += i + 1;
				y += j + 1;
				c++;
			}
		}
	}
	x /= c;
	y /= c;
	cout << x << " " << y << endl;
}