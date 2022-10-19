#include <bits/stdc++.h>

using namespace std;

const long M = 200200;

#define SEG 0
#define DOT 1
#define long long long

struct Event{
	long l, r;
	long type;
	long id;

	Event(long l, long r, long type, long id): l(l), r(r), type(type), id(id) {}

	bool operator < (const Event &to) const {
		return l < to.l || (l == to.l && type == SEG && to.type == DOT);
	}
};

Event Segment(long l, long r, long id) {
	return Event(l, r, SEG, id);
}

Event Dot(long p, long id) {
	return Event(p, -1, DOT, id);
}


long n, m, l[M], r[M], a[M], ans[M];
vector<Event> events;

void read() {
	cin >> n >> m;
	for (long i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		r[i]++;
	}
	for (long i = 0; i < m; ++i) {
		long p;
		cin >> p;
		events.push_back(Dot(p, i + 1));
	}
}

void build() {
	for (long i = 0; i + 1 < n; ++i) {
		long min = l[i + 1] - r[i] + 1;
		long max = r[i + 1] - l[i] - 1 + 1;
		//cerr << min << " " << max << "!!\n";
		events.push_back(Segment(min, max, i));
	}
	sort(events.begin(), events.end());
}

void kill() {
	set<pair<long, long>> ends;
	bool good = true;
	for (auto e : events) {
		if (e.type == SEG) {
			ends.insert(make_pair(e.r, e.id));
		} else if (!ends.empty()) {
			auto it = ends.begin();
			if (it->first > e.l) {
				ans[it->second] = e.id;
				ends.erase(it);
			} else {
				good = false;
				break;
			}
		}
	}

	if (good && ends.empty()) {
		cout << "Yes\n";
		for (long i = 0; i + 1 < n; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	build();
	kill();
	return 0;
}