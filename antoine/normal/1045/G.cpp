#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct IdGen {
	unordered_map<int, int> mp;
	vector<int> lazy;
	void insert(int x) {
		assert(mp.empty());
		lazy.push_back(x);
	}
	void process() {
		assert(mp.empty());
		mp.reserve((int)1e5);
		mp.max_load_factor(0.25);

		sort(lazy.begin(), lazy.end());
		lazy.erase(unique(lazy.begin(), lazy.end()), lazy.end());
		for (int i = 0; i < (int)lazy.size(); ++i)
			mp[lazy[i]] = i;
		lazy.clear();
	}
	int getId(int x) const {
		assert(lazy.empty());
		return mp.at(x);
	}
	int size() const {
		assert(lazy.empty());
		return mp.size();
	}
};

int ftv[(int)1e5 + 2];

struct FT {
	int v_size;
	vector<int> dirty;
	FT(int n) {
		v_size = n + 1;
	}
	void reset(int i) {
		for (++i; i < v_size; i += i & -i)
			ftv[i] = 0;
	}
	void update(int i, const int a) {
		dirty.push_back(i);
		for (++i; i < v_size; i += i & -i)
			ftv[i] += a;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < v_size - 1);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += ftv[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}

	~FT() {
		for (auto &&x : dirty)
			reset(x);
	}
};

int N;
int x[(int)1e5];
int r[(int)1e5];
int lft[(int)1e5];
int rght[(int)1e5];
int curr[(int)1e5];

inline ll f(const vector<int> &v) {
	ll res = 0;
	FT ft(N);
	for (auto && x : v) {
		res += ft.query(lft[x], rght[x]);
		ft.update(curr[x], 1);
	}
	return res;
}

bool lessRobot(const int i, const int j) {
	return r[i] > r[j];
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int K;
	cin >> N >> K;
	// N = (int)1e5; K = 20;

	map<int, vector<int>> mp;
	
	IdGen idGen;
	set<int> xSet;

	for (int i = 0; i < N; ++i) {
		int q;
		cin >> x[i] >> r[i] >> q;
		// x[i] = 0; r[i] = 1; q = i;

		mp[q].emplace_back(i);
		idGen.insert(x[i]);
		xSet.insert(x[i]);
	}

	idGen.process();


	cerr << "state 1\n";
	for (int i = 0; i < N; ++i) {
		lft[i] = idGen.getId(*(xSet.lower_bound(x[i] - r[i])));
		rght[i] = idGen.getId(*prev(xSet.upper_bound(x[i] + r[i])));
		curr[i] = idGen.getId(x[i]);
	}

	cerr << "state 2\n";
	for (auto &&x : mp)
		sort(x.second.begin(), x.second.end(), lessRobot);

	cerr << "state 3\n";
	ll ans = 0;
	unordered_map<int, ll> sameIqCnt;
	sameIqCnt.reserve((int)2e5);
	sameIqCnt.max_load_factor(0.25);

	cerr << "state 3.1\n";

	for (auto &&x : mp)
		ans += (sameIqCnt[x.first] = f(x.second));

	cerr << "state 3.2\n";
	vector<pair<int, vector<int>>> v(mp.begin(), mp.end());


	cerr << "state 4\n";
	for (int diff = 1; diff <= K; ++diff) {
		for (auto it1 = v.begin(), it2 = v.begin(); it1 != v.end(); ++it1) {
			while (it2 != v.end() && it2->first < it1->first + diff) ++it2;
			if (it2 == v.end() || it2->first != it1->first + diff) continue;

			vector<int> u(it1->second.size() + it2->second.size());
			merge(it1->second.begin(), it1->second.end(), it2->second.begin(), it2->second.end(), u.begin(), lessRobot);
			ans += f(u) - sameIqCnt.at(it1->first) - sameIqCnt.at(it2->first);
		}
	}

	cout << ans << '\n';
	return 0;
}