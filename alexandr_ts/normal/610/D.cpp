#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <tuple>
#include <sstream>
#include <numeric>
#include <chrono>
#include <utility>
#include <functional>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;

const int N = 1e5 + 10;
pi a[N][2];

map<int, vector<pi>> mhor, mver;

pair<int, vector<pi>> calc(vector<pi> v) {
	vector<pi> newv;
	sort(v.begin(), v.end());
	for (auto p : v) {
		if (newv.empty() || newv.back().second + 1 < p.first) {
			newv.push_back(p);
		}
		else {
			newv.back().second = max(newv.back().second, p.second);
		}
	}

	int sum = 0;
	for (auto el : newv) {
		sum += (el.second - el.first + 1);
	}
	return { sum, newv };
}

int tree[8 * N];

void add(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		//assert(tree[v] + val == 1);
		tree[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		add(2 * v, tl, tm, pos, val);
	}
	else {
		add(2 * v + 1, tm + 1, tr, pos, val);
	}
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int get_sum(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) return 0;
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return get_sum(2 * v, tl, tm, l, r) + get_sum(2 * v + 1, tm + 1, tr, l, r);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> a[i][j].first >> a[i][j].second;
		}
		if (a[i][0].first > a[i][1].first) swap(a[i][0].first, a[i][1].first);
		if (a[i][0].second > a[i][1].second) swap(a[i][0].second, a[i][1].second);
		if (a[i][0].first == a[i][1].first) {
			if (!mhor.count(a[i][0].first)) {
				mhor[a[i][0].first] = {};
			}
			mhor[a[i][0].first].push_back({ a[i][0].second, a[i][1].second });
		}
		else {
			if (!mver.count(a[i][0].second)) {
				mver[a[i][0].second] = {};
			}
			mver[a[i][0].second].push_back({ a[i][0].first, a[i][1].first });
		}
	}

	set<int> xs;

	ll sum_hor = 0;
	ll sum_ver = 0;
	for (auto& [y, vec] : mver) {
		auto tmp = calc(vec);
		sum_ver += tmp.first;
		mver[y] = tmp.second;
		for (auto& el : mver[y]) {
			xs.insert(el.first);
			xs.insert(el.second);
		}
	}
	for (auto& [x, vec] : mhor) {
		auto tmp = calc(vec);
		sum_hor += tmp.first;
		mhor[x] = tmp.second;
		for (int i = 0; i + 1 < tmp.second.size(); ++i) {
			assert(tmp.second[i].second + 1 < tmp.second[i + 1].first);
		}
		xs.insert(x);
	}

	map<int, int> newxs;
	int i = 1;
	for (auto y : xs) {
		newxs[y] = i++;
	}

	vector<tuple<int, int, int>> events;
	for (auto& [x, vec] : mhor) {
		for (int i = 0; i + 1 < (int)vec.size(); ++i) {
			assert(vec[i].second + 1 < vec[i + 1].first);
		}
		for (auto el : vec) {
			events.push_back(make_tuple((int)el.first, (int)newxs[x], 1));
			events.push_back(make_tuple((int)el.second + 1, (int)newxs[x], 0));
		}
	}

	sort(events.begin(), events.end(), [](auto& lhs, auto& rhs) {
		return get<0>(lhs) < get<0>(rhs);
		});
	size_t ptr = 0;

	ll sum_inter = 0;
	set<int> cur_xs;
	for (auto& [y, vec] : mver) {
		while (ptr < events.size() && (get<0>(events[ptr]) <= y)) {
			int newx = get<1>(events[ptr]);
			int ad = get<2>(events[ptr]);
			if (ad == 0) {
				//cur_xs.erase(newx);
			}
			else {
				//assert(!cur_xs.count(newx));
				cur_xs.insert(newx);
			}
			add(1, 0, 2 * N - 1, newx, ad);
			++ptr;
		}
		for (auto& p : vec) {
			sum_inter += get_sum(1, 0, 2 * N - 1, newxs[p.first], newxs[p.second]);
		}
	}
	//cout << sum_hor << " " << sum_ver << " " << sum_inter << endl;
	cout << sum_hor + sum_ver - sum_inter << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);
	solve();
}