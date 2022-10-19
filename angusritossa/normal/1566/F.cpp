#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define IS_POINT 2000000000
int t, n, m, upto;
vector<ll> points;
vector<pair<ll, ll> > segments;
vector<pair<ll, ll> > events;

int done[MAXN*2][3][2];
ll memo[MAXN*2][3][2];
ll get_start(int event) {
	return events[event].first;
}
ll get_end(int event) {
	if (events[event].second == IS_POINT) return events[event].first;
	else return events[event].second;
}
ll dp(int a, int type, int is_doubling) {
	// type == 0 -> point going fowards
	// type == 1 -> point going back
	// type == 2 -> no point
	if (done[a][type][is_doubling] == upto) return memo[a][type][is_doubling];
	done[a][type][is_doubling] = upto;

	if (type == 2 && events[a].second != IS_POINT) {
		return memo[a][type][is_doubling] = 1e15;
	}

	if (a+1 == events.size()) {
		if (events[a].second == IS_POINT) return memo[a][type][is_doubling] = 0;
		else {
			if (type == 0) return memo[a][type][is_doubling] = 0;
			else return memo[a][type][is_doubling] = 1e15;
		}
	}

	ll multiplier = is_doubling+1;
	ll ans = 1e15;

	if (events[a].second != IS_POINT) {
		if (type == 0) {
			// keep going forward
			ll dis = (get_start(a+1) - get_start(a))*multiplier;
			ans = min(ans, dp(a+1, 0, is_doubling)+dis);

			// start going backwards
			ans = min(ans, dp(a+1, 1, 0));
			ans = min(ans, dp(a+1, 1, 1));

			// start having none
			ans = min(ans, dp(a+1, 2, 0));
		} else {
			// keep going backwards
			ll dis = (get_end(a+1) - get_end(a))*multiplier;
			ans = min(ans, dp(a+1, 1, is_doubling)+dis);
		}
	} else {
		if (type == 2) {
			// can continue type == 2, or start going forwards, or start going backwards
			ans = min(ans, dp(a+1, 2, 0));

			ll dis = (get_start(a+1) - get_start(a));
			ans = min(ans, dp(a+1, 0, 0)+dis);
			ans = min(ans, dp(a+1, 0, 1)+dis*2);

			ans = min(ans, dp(a+1, 1, 0));
			ans = min(ans, dp(a+1, 1, 1));
		} else if (type == 0) {
			// never optimal
			ans = 1e15;
		} else {
			// can absorb and do nothing
			ans = min(ans, dp(a+1, 2, 0));

			// can continue with doubling
			ll dis = (get_start(a+1) - get_start(a));
			ans = min(ans, dp(a+1, 0, 1)+dis*2);

			// can continue without doubling, if we were previously doubling
			if (is_doubling) {
				ans = min(ans, dp(a+1, 0, 0)+dis);
			}

			// can start a new backwards 
			ans = min(ans, dp(a+1, 1, 0));
			ans = min(ans, dp(a+1, 1, 1));

		}
	}
	//D("%lld %lld %lld - %lld\n", a, type, is_doubling, ans);
	return memo[a][type][is_doubling] = ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d%d", &n, &m);
		points.clear();
		segments.clear();
		events.clear();
		for (int i = 0; i < n; i++) {
			int p;
			scanf("%d", &p);
			points.push_back(p);
		}
		sort(points.begin(), points.end());
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			segments.push_back({a, b});
		}
		sort(segments.begin(), segments.end());
		priority_queue<pair<ll, ll> > pq;
		for (auto s : segments) {
			while (pq.size() && pq.top().first >= s.second) { 
				// D("%lld is popping %lld %lld\n", s.second, pq.top().second, pq.top().first);
				pq.pop();
			}
			pq.push({s.second, s.first});
		}
		segments.clear();
		while (pq.size()) {
			segments.push_back({pq.top().second, pq.top().first});
			pq.pop();
		}

		vector<pair<ll, ll> > newSegments;
		for (auto a : segments) {
			auto it = lower_bound(points.begin(), points.end(), a.first);
			if (it == points.end() || *it > a.second) newSegments.push_back(a);
		}
		segments.swap(newSegments);

		sort(segments.begin(), segments.end());

		// for (auto a : segments) D("%lld %lld\n", a.first, a.second);

		for (auto a : segments) events.push_back(a);
		for (auto a : points) events.push_back({a, IS_POINT});
		sort(events.begin(), events.end());

		upto++;

		ll ans = dp(0, 2, 0);
		ans = min(ans, dp(0, 1, 0));
		ans = min(ans, dp(0, 1, 1));

		printf("%lld\n", ans);

		//D("%lld\n", dp(4, 1, 0));
		//D("%lld %lld\n", events[4].first, events[4].second);
		D("\n\n\n");
	}
}