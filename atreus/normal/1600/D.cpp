#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

map<pair<int,int>, int> mp;
int X1, Y1, X2, Y2;

int getManhatan(int x, int y) {
	int difx, dify;
	if (x < X1)
		difx = X1 - x;
	else if (x <= X2)
		difx = 0;
	else
		difx = x - X2;
	if (y < Y1)
		dify = Y1 - y;
	else if (y <= Y2)
		dify = 0;
	else
		dify = y - Y2;
	return difx + dify;
}

int ask(int x, int y) {
	if (mp.count({x,y}))
		return mp[{x,y}];
	cout << "? " << x << " " << y << endl;
	int ret;
	cin >> ret;
	return mp[{x,y}] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
//	cin >> X1 >> Y1 >> X2 >> Y2;	
	int x = ask(1, 1);
	int y = ask(1e9, 1);
	int z = ask(1, 1e9);
	int lo = 2, hi = 1e9;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (ask(mid, 1) + mid == x + 1)
			lo = mid;
		else
			hi = mid;
	}
	int x1 = lo;
	int y1 = ask(lo, 1) + 1;
	int x2 = 1e9 - (y - y1) - 1;
	int y2 = 1e9 - (z - x1) - 1;
	cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}