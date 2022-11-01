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

const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1e3 + 10;
const int N = 3e5 + 10;

vector<int> sets[N];

struct Node {
	int cnt0 = 1;
	int cnt1 = 0;
	int current = 0;
	int inv = 0;
	int par = 0;
	bool has_set = false;
	set<int> children;
} nodes[N];

void build(int i) {
	nodes[i].par = i;
}

int findSet(int v) {
	if (v == nodes[v].par) return v;
	int par = nodes[v].par;
	int ret = findSet(par);

	if (par != ret) {
		nodes[par].children.erase(v);
		nodes[ret].children.insert(v);
	}

	nodes[v].par = ret;
	return ret;
}

void dfs(int v) {
	nodes[v].current ^= 1;
	nodes[v].inv ^= 1;
	for (auto u : nodes[v].children) {
		dfs(u);
	}
}

void unionSets(int v, int u) {
	if (nodes[v].cnt0 + nodes[v].cnt1 < nodes[u].cnt0 + nodes[u].cnt1) {
		swap(v, u);
	}
	if (nodes[v].inv != nodes[u].inv) {
		dfs(u);
	}
	nodes[u].par = v;
	nodes[v].has_set |= nodes[u].has_set;
	nodes[v].cnt0 += nodes[u].cnt0;
	nodes[v].cnt1 += nodes[u].cnt1;
	nodes[v].children.insert(u);
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') s[i] = '1'; else s[i] = '0';
	}

	for (int i = 0; i < k; ++i) {
		build(i);
		int sz;
		cin >> sz;
		int v;
		for (int j = 0; j < sz; ++j) {
			cin >> v;
			sets[v - 1].push_back(i);
		}
	}
	
	vector<int> answer;
	int cur_ans = 0;
	for (int i = 0; i < n; ++i) {
		if (sets[i].size() == 0) {
			assert(s[i] == '0');
		}
		else if (sets[i].size() == 1) {
			int par = findSet(sets[i][0]);
			int color = nodes[par].inv ^ nodes[sets[i][0]].current;
			nodes[par].has_set = true;
			if (color != s[i] - '0') {
				cur_ans -= nodes[par].cnt1;
				cur_ans += nodes[par].cnt0;
				swap(nodes[par].cnt0, nodes[par].cnt1);
				nodes[par].inv ^= 1;
			}
		}
		else if (sets[i].size() == 2) {
			int p1 = findSet(sets[i][0]);
			int p2 = findSet(sets[i][1]);
			if (p1 == p2) {
				answer.push_back(cur_ans);
				continue;
			}
			int c1 = nodes[p1].inv ^ nodes[sets[i][0]].current;
			int c2 = nodes[p2].inv ^ nodes[sets[i][1]].current;
			int c1c2 = c1 ^ c2;
			if (c1c2 != s[i] - '0') {
				int to_swap = p1;
				if (nodes[p1].has_set || (!nodes[p2].has_set && 
					nodes[p1].cnt1 - nodes[p1].cnt0 < nodes[p2].cnt1 - nodes[p2].cnt0)) {
					to_swap = p2;
				}
				cur_ans -= nodes[to_swap].cnt1;
				cur_ans += nodes[to_swap].cnt0;
				nodes[to_swap].inv ^= 1;
				swap(nodes[to_swap].cnt0, nodes[to_swap].cnt1);
			}
			int cursum = nodes[p1].cnt1 - nodes[p1].cnt0 + nodes[p2].cnt1 - nodes[p2].cnt0;
			if (cursum > 0 && !nodes[p1].has_set && !nodes[p2].has_set) {
				cur_ans -= cursum;
				nodes[p1].inv ^= 1;
				swap(nodes[p1].cnt0, nodes[p1].cnt1);

				nodes[p2].inv ^= 1;
				swap(nodes[p2].cnt0, nodes[p2].cnt1);
			}
			unionSets(p1, p2);
		}
		else {
			assert(false);
		}
		answer.push_back(cur_ans);
	}
	for (auto el : answer) {
		cout << el << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	FILE* stream;
	//freopen_s(&stream, "a.in", "r", stdin);

	int t = 1;
	while (t--) {
		solve();
	}
}