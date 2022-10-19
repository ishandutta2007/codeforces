#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		int foo = abs(xx - x) + abs(yy - y);
		if (xx != x && yy != y)
			foo += 2;
		cout << foo << '\n';
	}

	return 0;
}