#include<bits/stdc++.h>
using namespace std;

struct Rec {
	int x, y, xx, yy;
};

Rec giao(Rec x, Rec y) {
	Rec res;
	res.x = max(x.x, y.x);
	res.xx = min(x.xx, y.xx);
	res.y = max(x.y, y.y);
	res.yy = min(x.yy, y.yy);
	if ((res.xx > res.x) && (res.yy > res.y)) {
		return res;
	} else {
		res.x = 0; res.y = 0; res.xx = 0; res.yy = 0;
		return res;
	}
}

long long s(Rec x) {
	return 1LL * (x.xx - x.x) * (x.yy - x.y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Rec a, b, c;
	cin >> a.x >> a.y >> a.xx >> a.yy;
	cin >> b.x >> b.y >> b.xx >> b.yy;
	cin >> c.x >> c.y >> c.xx >> c.yy;
	Rec u = giao(a, b);
	Rec v = giao(a, c);
	if (s(u) + s(v) - s(giao(u, v)) == s(a)) {
		cout << "NO";
	} else {
		cout << "YES";
	}
	return 0;
}