#include <bits/stdc++.h>

using namespace std;

#define M 200200
#define L 0
#define R 1
#define ADD 1
#define CLASH 2

struct Line {
	int x, dir, time;

	Line(int x, int dir, int time): x(x), dir(dir), time(time) {}

	bool operator < (const Line &to) const {
		return x < to.x || (x == to.x && time < to.time);
	}
};

struct Event {
	int type;
	int time;
	Line l, r;

	Event(int type, int time, Line l, Line r): type(type), time(time), l(l), r(r) {}

	bool operator < (const Event &to) const {
		return time < to.time || (time == to.time && l.x < to.l.x);
	}
};


Event intersection(Line l, Line r) {
	assert(l.dir == R && r.dir == L);
	return Event(CLASH, (r.x - l.x), l, r);
}

Event Add(Line l) {
	return Event(ADD, l.time, l, l);
}

int n, q, ans[M];
set<int> used;
set<Line> board;
set<Event> events;
bool alive[M];

void workOut(Line l) {
	auto ptr = board.find(l);

	auto prev = ptr;
	auto nxt = ptr;
	nxt++;


	if (ptr != board.begin()) {
		prev--;
		if (ptr->dir == L && prev->dir == R) {
			events.insert(intersection(*prev, *ptr));
		}
	}

	if (nxt != board.end() && ptr->dir == R && nxt->dir == L) {
		//cerr << "Yahho " << ptr->x << " - " << nxt->x << "\n";
		events.insert(intersection(*ptr, *nxt));
	}
}


void read() {
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		if (used.find(x) != used.end()) {
			ans[i] = 0;
			continue;
		}

		used.insert(x);

		auto l = Line(x, dir == 'U' ? R : L, i);
		board.insert(l);
		workOut(l);

		alive[i] = true;
	}

}

void writeBoard() {
	cerr << "Board:\n";
	for (auto l : board) {
		cerr << "  " << l.x << " " << (l.dir == L ? "L" : "R") << "\n";
	}
}

void kill() {
	while (!events.empty()) {
		Event cur = *events.begin();
		events.erase(events.begin());

		//writeBoard();
		//cerr << "Time: " << cur.time << "  ";

		if (cur.type == ADD) {
			//cerr << "ADD " << cur.l.x << " " << (cur.l.dir == L ? 'L' : 'R') << "\n";
			assert(false);
			board.insert(cur.l);
			workOut(cur.l);
		} else {
			//cerr << "CLASH " << cur.l.x << " " << cur.r.x << "\n";
			int lt = cur.l.time, rt = cur.r.time;
			if (!alive[lt] || !alive[rt])
				continue;

			int len = cur.r.x - cur.l.x;
			if (cur.l.time < cur.r.time) {
				ans[rt] = len;
				board.erase(cur.r);
				alive[rt] = false;
				workOut(cur.l);
			} else {
				ans[lt] = len;
				board.erase(cur.l);
				alive[lt] = false;
				workOut(cur.r);
			}
		}
	}

	for (auto l : board) {
		if (l.dir == R) {
			ans[l.time] = n + 1 - l.x;
		} else {
			ans[l.time] = l.x;
		}
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	kill();
	return 0;
}