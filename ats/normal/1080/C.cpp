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
int cnt(int X1, int Y1, int X2, int Y2, int col) {
	int dx = (X2 - X1 + 1);
	int dy = (Y2 - Y1 + 1);
	if ((dx*dy) % 2 == 0) {
		return (dx * dy) / 2;
	}
	else {
		if ((X1 + Y1 + col) % 2 == 0) {
			return (dx * dy + 1) / 2;
		}
		else {
			return (dx * dy - 1) / 2;
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin >> Q;
	vector<pair<int, int> > res;
	while (Q--) {
		int M, N;
		cin >> M >> N;
		int X1, Y1, X2, Y2;
		int X3, Y3, X4, Y4;
		cin >> X1 >> Y1 >> X2 >> Y2;
		cin >> X3 >> Y3 >> X4 >> Y4;
		int white = cnt(1, 1, N, M, 0);
		//cerr << white << endl;
		white += cnt(X1, Y1, X2, Y2, 1);
		//cerr << white << endl;
		white -= cnt(X3, Y3, X4, Y4, 0);
		//cerr << white << endl;
		int X5 = max(X1, X3);
		int Y5 = max(Y1, Y3);
		int X6 = min(X2, X4);
		int Y6 = min(Y2, Y4);
		//cerr << X5 << " " << Y5 << " " << X6 << " " << Y6 << endl;
		if (X5 <= X6 && Y5 <= Y6) {
			white -= cnt(X5, Y5, X6, Y6, 1);
			//cerr << white << endl;
		}
		res.emplace_back(white, N*M - white);
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
}