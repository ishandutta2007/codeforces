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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int bd[1000][1000];
signed main() {
	int N = 666;
	int X, Y;
	cin >> X >> Y;
	int a, b;
	vector<int> ZX(N);
	vector<int> ZY(N);
	for (int i = 0; i < N; i++) {
		cin >> ZX[i] >> ZY[i];
		bd[ZX[i]][ZY[i]] = 1;
	}
	int nx, ny;
	int k;
	while (X != 500 || Y != 500) {
		if (X < 500) {
			nx = X + 1;
		}
		else if (X > 500) {
			nx = X - 1;
		}
		else {
			nx = X;
		}
		if (Y < 500) {
			ny = Y + 1;
		}
		else if (Y > 500) {
			ny = Y - 1;
		}
		else {
			ny = Y;
		}
		if (bd[nx][ny] > 0) {
			if (nx != X)nx = X;
			else ny = Y;
		}
		X = nx;
		Y = ny;
		cout << X << " " << Y << endl << flush;
		int k;
		cin >> k >> a >> b;
		if (k == -1) {
			return 0;
		}
		else if (k == 0) {
			assert(false);
		}
		k--;
		bd[ZX[k]][ZY[k]] = 0;
		bd[a][b] = 1;
		ZX[k] = a; ZY[k] = b;
		
	}
	int dx;
	int dy;
	int mnx, mxx;
	int mny, mxy;
	int mn = 1000000000;
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			mnx = 1;
			mxx = 499;
		}
		else {
			mnx = 501;
			mxx = 999;
		}
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				mny = 1;
				mxy = 499;
			}
			else {
				mny = 501;
				mxy = 999;
			}
			int c = 0;
			for (int x = mnx; x <= mxx; x++) {
				for (int y = mny; y <= mxy; y++) {
					c += bd[x][y];
				}
			}
			if (mn > c) {
				mn = c;
				dx = 1 - i * 2;
				dy = 1 - j * 2;
			}
		}
	}
	


	while (true) {
		nx = X + dx;
		ny = Y + dy;
		if (bd[nx][ny] > 0) {
			if (nx != X)nx = X;
			else ny = Y;
		}
		X = nx;
		Y = ny;
		cout << X << " " << Y << endl << flush;
		cin >> k >> a >> b;
		if (k == -1) {
			return 0;
		}
		else if (k == 0) {
			assert(false);
		}
		k--;
		bd[ZX[k]][ZY[k]] = 0;
		bd[a][b] = 1;
		ZX[k] = a; ZY[k] = b;
	}
	return 0;
}