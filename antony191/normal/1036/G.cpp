#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1e9, maxn = 1000000;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<typename T> bool uax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream & out = cerr) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cerr) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

vector<int> g[maxn], g1[maxn], g2[maxn], t1[40];
vector<bool> used;

void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v])
		if (!used[to])
			dfs(to);
}

void dfs1(int v) {
	used[v] = 1;
	for (auto to : t1[v])
		if (!used[to])
			dfs1(to);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u); g[u].push_back(v);
		g1[v].push_back(u);
		a[u]++;
	}
	used.assign(n, false);
	dfs(0);
	forn(i, n) 
		if (!used[i]) {
			return cout << "NO", 0;
		}
	vector<int> v1, v2;
	forn(i, n) {
		if (g1[i].size() == 0)
			v2.push_back(i);
		if (a[i] == 0)
			v1.push_back(i);
	}
	sort(all(v1)); sort(all(v2));
	queue<int> q;
	int cnt = (int)v1.size();
	vector<int> t[20];
	forn(i, v1.size()) {
		used.assign(n, false);
		q.push(v1[i]);
		used[v1[i]] = 1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			used[v] = 1;
			for (auto to : g1[v])
				if (!used[to]) {
					used[to] = 1;
					q.push(to);
				}
		}
		forn(j, cnt)
			if (used[v2[j]]) {
				t[i].push_back(j);
				t1[i].push_back(cnt + j);
				t1[cnt + j].push_back(i);
			}
	}
	used.assign(cnt + cnt, false);
	dfs1(0);
	forn(i, cnt + cnt)
		if (!used[i])
			return cout << "NO", 0;
	used.assign(cnt, false);
	vector<bool> cl(cnt);
	int ee = 1 << cnt;
	for (int i = 1; i < ee - 1; ++i) {
		int tmp = i;
		cl.assign(n, false);
		int sum1 = 0;
		for (int j = 0; j < cnt; ++j) {
			if (tmp & 1) {
				used[j] = 1;
				sum1++;
			}
			else
				used[j] = 0;
			tmp >>= 1;
		}
		forn(j, cnt)
			if (used[j])
			for (auto to : t[j])
				cl[to] = 1;
		int sum = 0;
		forn(j, cnt)
			sum += cl[j];
		if (sum <= sum1)
			return cout << "NO", 0;
	}
	cout << "YES";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}