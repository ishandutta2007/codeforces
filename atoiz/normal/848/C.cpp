/*input
7 6
1 2 3 1 3 2 1
2 3 7
2 1 3
1 7 2
1 3 2
2 1 6
2 5 7

*/

// https://codeforces.com/contest/848/submission/69647559

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <tuple>

using namespace std;
using Event = tuple<bool, int, int, int>;

const int MAXN = 100007;
int N, M, A[MAXN];
int64_t answers[MAXN];
set<int> app[MAXN];
vector<Event> events;

vector<pair<int, int>> updates[MAXN], queries[MAXN];
int64_t bit[MAXN];

void upd(int i, int64_t x)
{	for (; i <= N; i += i & (-i)) bit[i] += x; }

int64_t get(int i)
{
	int64_t ans = 0;
	for (; i > 0; i -= i & (-i)) ans += bit[i];
	return ans;
}

void solve(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);

	vector<int> vec;

	// find updates & queries
	for (int i = l; i <= r; ++i) {
		bool t;
		int x, y, z;
		tie(t, x, y, z) = events[i];

		if (i <= mid && t) {
			vec.push_back(x);
			updates[x].emplace_back(y, z);
		}
		if (i > mid && not t) {
			vec.push_back(x);
			queries[x].emplace_back(y, z);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	reverse(vec.begin(), vec.end());

	// process
	for (int idx : vec) {
		for (auto p : updates[idx]) upd(p.first, p.second);
		for (auto p : queries[idx]) answers[p.second] += get(p.first);
	}

	for (int idx : vec) {
		for (auto p : updates[idx]) upd(p.first, -p.second);
		updates[idx].clear();
		queries[idx].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		if (!app[A[i]].empty()) {
			events.emplace_back(true, *app[A[i]].rbegin(), i, i - *app[A[i]].rbegin());
		}
		app[A[i]].insert(app[A[i]].end(), i);
	}

	int nAnswers = 0;
	events.reserve(6 * M);
	for (int m = 0; m < M; ++m) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			auto it = app[A[x]].find(x);
			if (it != app[A[x]].begin()) events.emplace_back(true, *prev(it), *it, *prev(it) - *it);
			if (next(it) != app[A[x]].end()) events.emplace_back(true, *it, *next(it), *it - *next(it));
			if (it != app[A[x]].begin() && next(it) != app[A[x]].end()) events.emplace_back(true, *prev(it), *next(it), *next(it) - *prev(it));
			app[A[x]].erase(it);

			A[x] = y;

			app[A[x]].insert(x);
			it = app[A[x]].find(x);
			if (it != app[A[x]].begin()) events.emplace_back(true, *prev(it), *it, *it - *prev(it)); // can be optimized
			if (next(it) != app[A[x]].end()) events.emplace_back(true, *it, *next(it), *next(it) - *it);
			if (it != app[A[x]].begin() && next(it) != app[A[x]].end()) events.emplace_back(true, *prev(it), *next(it), *prev(it) - *next(it));
		} else {
			events.emplace_back(false, x, y, nAnswers++);
		}
	}

	for (auto ev : events) {
		bool t;
		int x, y, z;
		tie(t, x, y, z) = ev;
	}

	solve(0, (int) events.size() - 1);
	for (int i = 0; i < nAnswers; ++i) {
		cout << answers[i] << '\n';
	}
}