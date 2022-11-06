#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Rect {
	int x1, y1;
	int x2, y2;

	void f(Rect other) {
		x1 = min(x1, other.x1);
		x2 = max(x2, other.x2);
		y1 = min(y1, other.y1);
		y2 = max(y2, other.y2);
	}

	void inter(Rect other) {
		x1 = max(x1, other.x1);
		x2 = min(x2, other.x2);
		y1 = max(y1, other.y1);
		y2 = min(y2, other.y2);
	}
};

void f() {
	int n;
	cin >> n;
	const int Inf = (int) 1e5;
	Rect res { -Inf, -Inf, Inf, Inf };

	while (n--) {
		int x, y;
		cin >> x >> y;
		Rect rect = { x, y, x, y };
		for (int i = 0; i < 4; ++i) {
			int ff;
			cin >> ff;
			assert(ff == 0 || ff == 1);
			if (!ff)
				continue;
			Rect temp = { x, y, x, y };
			if (i == 0)
				temp.x1 = -Inf;
			else if (i == 1)
				temp.y2 = Inf;
			else if (i == 2)
				temp.x2 = Inf;
			else if (i == 3)
				temp.y1 = -Inf;
			else
				assert(false);
			rect.f(temp);
		}
		res.inter(rect);
	}

	if (res.x1 <= res.x2 && res.y1 <= res.y2)
		cout << "1 " << res.x1 << ' ' << res.y1 << '\n';
	else
		cout << "0\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		f();
	}
	return 0;
}