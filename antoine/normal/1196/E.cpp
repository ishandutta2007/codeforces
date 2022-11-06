#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {

	int b, w;
	cin >> b >> w;

	int x = (int) 1e8;
	int y = (int) 1e8;
	if (w > b) {
		swap(w, b);
		--x;
	}

	vector<pair<int, int>> res;
	res.push_back( { x - 1, y }), --b;

	for (; w; x += 2) {
		res.push_back( { x, y }), --w;
		if (!b)
			break;
		res.push_back( { x + 1, y }), --b;
		if (b > w)
			res.push_back( { x, y + 1 }), --b;
		if (b > w)
			res.push_back( { x, y - 1 }), --b;
	}
	if (w || b)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (auto p : res)
			cout << p.first << ' ' << p.second << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		f();
	return 0;
}