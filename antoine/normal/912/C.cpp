#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

struct Event {
	long long t;
	int ennemy = -1;
	int health = -1;

	Event(long long t, int ennemy, int health) : t(t), ennemy(ennemy), health(health) {}

	bool operator<(const Event &other) const {
		if (t != other.t) return t < other.t;
		if ((ennemy == -1) != (other.ennemy == -1)) return ennemy != -1;
		if (health != other.health) return health > other.health;
		return ennemy < other.ennemy;
	}
};

int ceilDiv(int a, int b) {
	return (a + b - 1) / b;
}

int main() { // C from round 456
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, bounty, increase, damage;
	cin >> n >> m >> bounty >> increase >> damage;

	vector<int> maxHealth(n + 1);
	vector<pair<int, int>> currHealth(n + 1, { 0, 0 });
	vector<int> regen(n + 1);

	long long t = 0;
	int killRange = 0;
	set<Event> events;

	for (int i = 1; i <= n; ++i) {
		cin >> maxHealth[i] >> currHealth[i].second >> regen[i];
		if (currHealth[i].second <= damage) {
			++killRange;
			if (regen[i] && maxHealth[i] > damage) {
				auto te = t + ceilDiv(damage + 1 - currHealth[i].second, regen[i]);
				events.insert({ te, i, -1 });
				events.insert({ te, -1, -1 });
				events.insert({ te - 1, -1, -1 });
			}
		}
	}

	while (m-- > 0) {
		int te, ennemy, health;
		cin >> te >> ennemy >> health;
		events.insert({ te, ennemy, health });
		events.insert({ te - 1, -1, -1 });
	}

	long long ans = (long long)killRange * bounty;

	while (!events.empty()) {
		Event e = *events.cbegin();
		events.erase(events.cbegin());
		if (e.t < t) continue;
		t = e.t;
		if (e.ennemy == -1) {
			ans = max(ans, (long long)killRange * (bounty + t * increase));
			continue;
		}
		if (currHealth[e.ennemy].second <= damage)
			--killRange;

		if (e.health != -1)
			currHealth[e.ennemy] = { t, e.health };
		else
			currHealth[e.ennemy] = { t,
				min((long long)maxHealth[e.ennemy], currHealth[e.ennemy].second +
					(long long)regen[e.ennemy] * (t - currHealth[e.ennemy].first)) };

		if (currHealth[e.ennemy].second <= damage) {
			++killRange;
			if (regen[e.ennemy] && maxHealth[e.ennemy] > damage) {
				auto te = t + ceilDiv(damage + 1 - currHealth[e.ennemy].second, regen[e.ennemy]);
				events.insert({ te, e.ennemy, -1 });
				events.insert({ te, -1, -1 });
				events.insert({ te - 1, -1, -1 });
			}
		}
	}
	cout << (killRange && increase ? -1 : ans);
	return 0;
}