#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct V {
	int x, y1, y2;
	bool operator<(const V &other) const {
		return x < other.x;
	}
};

struct H {
	int x1, x2, y;

	bool crosses(const V &x) const {
		return x1 <= x.x && x.x <= x2 && x.y1 <= y && y <= x.y2;
	}
	bool operator<(const H &other) const {
		return x2 < other.x2;
	}
};

const int Mx = (int) 1e4 + 9;
int vals[Mx + 99];

struct FT {
	int n;
	FT(const int n) :
			n(n) {
		memset(vals, 0, sizeof vals);
	}

	void update(int i, const int x) {
		for (++i; i <= n; i += i & -i)
			vals[i] += x;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<V> vert;
	vector<H> hori;

	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5000;
		x2 += 5000;
		y1 += 5000;
		y2 += 5000;

		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		if (x1 == x2)
			vert.push_back( { x1, y1, y2 });
		else {
			assert(y1 == y2);
			hori.push_back( { x1, x2, y1 });
		}
	}

	sort(vert.begin(), vert.end());

	ll ans = 0;
	for (int i = (int) vert.size() - 1; i >= 0; --i) {
		vector<H> v;
		for (const H &x : hori)
			if (x.crosses(vert[i]))
				v.push_back(x);
		sort(v.begin(), v.end());

		FT ft(Mx);
		for (int j = (int) vert.size() - 1; i < j; --j) {
			while (!v.empty() && v.back().x2 >= vert[j].x) {
				ft.update(v.back().y, 1);
				v.pop_back();
			}

			const int y1 = max(vert[i].y1, vert[j].y1);
			const int y2 = min(vert[i].y2, vert[j].y2);
			if (y1 < y2) {
				const ll c = ft.query(y1, y2);
				ans += c * (c - 1) / 2;
			}
		}
	}
	cout << ans;
	return 0;
}