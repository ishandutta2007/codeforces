#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Pos {
	int x, y;
	Pos operator+(const Pos &other) const {
		return Pos { x + other.x, y + other.y };
	}
	Pos operator-(const Pos &other) const {
		return Pos { x - other.x, y - other.y };
	}
	Pos normalize() const {
		return Pos { max(-1, min(1, x)), max(-1, min(1, y)) };
	}
	bool operator<(const Pos &other) const {
		int diff = x - other.x;
		if (!diff)
			diff = y - other.y;
		return diff < 0;
	}
	bool operator==(const Pos &other) const {
		return x == other.x && y == other.y;
	}
	bool operator!=(const Pos &other) const {
		return !(*this == other);
	}
};

int dist(Pos p1, Pos p2) {
	return max(abs(p1.x - p2.x), abs(p1.y - p2.y));
}

Pos me;
Pos rooks[700];

bool occupied(const Pos &pos) {
	for (int i = 1; i <= 666; ++i)
		if (rooks[i] == pos)
			return true;
	return pos == me;
}

void Move1(Pos dest) {
	assert(dist(me, dest) == 1);

	if (occupied(dest))
		dest.x = me.x;

	assert(!occupied(dest));
	assert(dist(me, dest) == 1);

	cout << dest.x << ' ' << dest.y << endl;
	me = dest;

	int k, x, y;
	cin >> k >> x >> y;
	if (k <= 0) {
		assert(k == -1 || k == 0);
		assert(x == k && y == k);
		exit(0);
	} else {
		assert(1 <= k && k <= 666);
		assert(1 <= x && x <= 999);
		assert(1 <= y && y <= 999);
		rooks[k] = {x, y};
	}
}

void Move(const Pos dest) {
	while (me != dest)
		Move1(me + (dest - me).normalize());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> me.x >> me.y;
	for (int i = 1; i <= 666; ++i)
		cin >> rooks[i].x >> rooks[i].y;

	Move( { 500, 500 });
	vector<Pos> corners = { { 1, 1 }, { 1, 999 }, { 999, 1 }, { 999, 999 } };
	map<Pos, int> mp;

	for (const Pos &p : corners)
		mp[p];

	for (int i = 1; i <= 666; ++i) {
		const Pos closest = *min_element(corners.begin(), corners.end(), [&](const Pos &p1, const Pos &p2) {
			return dist(rooks[i], p1) < dist(rooks[i], p2);
		});
		++mp[closest];
	}
	assert(mp.size() == 4);

	for (auto &&e : mp)
		if (e.second <= 166) {
			Move( { 1000 - e.first.x, 1000 - e.first.y });
			cout << "AAA" << endl;
			return 0;
		}

	cout << "BBB" << endl;
	return 0;
}