#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000009; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#include <unordered_map>

const int MAX_N = 100000;
vector<int> G[MAX_N];
int match[MAX_N];
bool used[MAX_N];

bool dfs(int v) {
	used[v] = true;
	for (auto u : G[v]) {
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(int N) {
	int ret = 0;
	memset(match, -1, sizeof(match));
	FOR(v, N) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v)) ret++;
		}
	}
	return ret;
}


bool solve(vector<int> num,int a,int b,map<int,int>& anses) {
	const int n = sz(num);
	if (n % 2 != 0) return false;
	FOR(i, MAX_N) G[i].clear();
	map<int, int> mp;
	FOR(i, n) {
		mp[num[i]] = i;
	}
	FOR(i, n) {
		if (mp.count(a - num[i])) {
			if (a != num[i] * 2) G[i].push_back(mp[a - num[i]]);
		}
		if (mp.count(b - num[i])) {
			if (b != num[i] * 2) G[i].push_back(mp[b - num[i]]);
		}
	}

	int matches = bipartite_matching(n);
	if (matches != n / 2) return false;
	FOR(i, n) {
		int val = (b == num[i] + num[match[i]]);
		anses[num[i]] = val;
	}
	return true;
}

int p[ten(5)];
void pans(map<int, int>& anses) {
	puts("YES");
	FOR(i, sz(anses)) {
		printf("%d%c", anses[p[i]], i == sz(anses) - 1 ? '\n' : ' ');
	}
}

int main() {
	int n, a, b; cin >> n >> a >> b;
	FOR(i, n) cin >> p[i];

	map<int, int> mp;
	int eq_a = -1, eq_b = -1;
	FOR(i, n) {
		if (p[i] * 2 == a) eq_a = i;
		else if (p[i] * 2 == b) eq_b = i;
	}
	
	map<int, int> anses;
	{
		vector<int> num;
		FOR(i, n) {
			if (i != eq_a && i != eq_b) num.push_back(p[i]);
		}
		bool t = solve(num, a, b, anses);
		if (t) {
			if (eq_a != -1) anses[p[eq_a]] = 0;
			if (eq_b != -1) anses[p[eq_b]] = 1;
			pans(anses);
			return 0;
		}
	}

	if(eq_a != -1){
		vector<int> num(sz(mp));
		FOR(i, n) {
			if (i != eq_a && i != eq_b) num.push_back(p[i]);
		}
		num.push_back(p[eq_a]);
		bool t = solve(num, a, b, anses);
		if (t) {
			if (eq_b != -1) anses[p[eq_b]] = 1;
			pans(anses);
			return 0;
		}
	}

	if (eq_b != -1) {
		vector<int> num(sz(mp));
		FOR(i, n) {
			if (i != eq_a && i != eq_b) num.push_back(p[i]);
		}
		num.push_back(p[eq_b]);
		bool t = solve(num, a, b, anses);
		if (t) {
			if (eq_a != -1) anses[p[eq_a]] = 0;
			pans(anses);
			return 0;
		}
	}

	if (eq_a != -1 && eq_b != -1) {
		vector<int> num(sz(mp));
		FOR(i, n) {
			if (i != eq_a && i != eq_b) num.push_back(p[i]);
		}
		num.push_back(p[eq_b]);
		if (eq_a != eq_b) num.push_back(p[eq_a]);
		bool t = solve(num, a, b, anses);
		if (t) {
			pans(anses);
			return 0;
		}
	}

	puts("NO");

	return 0;
}