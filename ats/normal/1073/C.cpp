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
	string S;
	cin >> S;
	int X, Y;
	cin >> X >> Y;
	int curX = 0;
	int curY = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			curX++;
		}
		else if (S[i] == 'L') {
			curX--;
		}
		else if (S[i] == 'U') {
			curY++;
		}
		else if (S[i] == 'D') {
			curY--;
		}
	}
	//L->R
	//D->U
	if ((curX + X + curY + Y) % 2 != 0) {
		cout << -1 << endl;
		return 0;
	}

	if (curX > X) {
		curX = -curX;
		X = -X;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'L')S[i] = 'R';
			else if (S[i] == 'R')S[i] = 'L';
		}
	}
	if (curY > Y) {
		curY = -curY;
		Y = -Y;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'D')S[i] = 'U';
			else if (S[i] == 'U')S[i] = 'D';
		}
	}
	int r = 0;
	int res = (int)1e18;
	int d = 0;
	for (int i = 0; i < N; i++) {
		while (r < N && (d < 0 || abs(curX - X) + abs(curY - Y) > d)) {
			d++;
			if (S[r] == 'R') {
				curX--;
			}
			else if (S[r] == 'L') {
				curX++;
			}
			else if (S[r] == 'U') {
				curY--;
			}
			else if (S[r] == 'D') {
				curY++;
			}
			r++;
		}
		if (abs(curX - X) + abs(curY - Y) <= d) {
			//cerr << i << " " << r << endl;
			res = min(res, r - i);
		}
		if (S[i] == 'R') {
			curX++;
		}
		else if (S[i] == 'L') {
			curX--;
		}
		else if (S[i] == 'U') {
			curY++;
		}
		else if (S[i] == 'D') {
			curY--;
		}
		d--;
	}
	if (res == (int)1e18)res = -1;
	cout << res << endl;
}