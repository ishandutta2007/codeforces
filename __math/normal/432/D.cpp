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
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct SAComp {
	const int h;
	const vector<int>& g;
	SAComp(int h, vector<int>& g) : h(h), g(g) {}
	bool operator() (int a, int b) {
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h];
	}
};
vector<int> buildSA(string& t) {
	const int n = sz(t);
	vector<int> g(n + 1), b(n + 1), v(n + 1);
	FOR(i, n + 1) v[i] = i, g[i] = t[i];
	b[0] = 0; b[n] = 0;

	sort(v.begin(), v.end(), SAComp(0, g));
	for (int h = 1; b[n] != n; h *= 2) {
		SAComp comp(h, g);
		sort(v.begin(), v.end(), comp);
		FOR(i, n) b[i + 1] = b[i] + comp(v[i], v[i + 1]);
		FOR(i, n + 1) g[v[i]] = b[i];
	}
	return v;
}

// Kasai-Lee-Arimura-Arikawa-Park's simple LCP computation: O(n)
// lcp[i] == (sa[i] , sa[i-1]) prefix
vector<int> buildLCP(string& t,vector<int>& sa) {
	int h = 0;
	const int n = sz(t);
	vector<int> b(n+ 1),lcp(n+1);
	FOR(i, n + 1) b[sa[i]] = i;
	FOR(i, n + 1) {
		if (b[i]) {
			for (int j = sa[b[i] - 1]; j + h<n && i + h<n && t[j + h] == t[i + h]; ++h);
			lcp[b[i]] = h;
		} else lcp[b[i]] = -1;
		if (h > 0) --h;
	}
	return lcp;
}

vector<int> solve(string& t, vector<int>& sa) {
	const int n = sz(t);
	vector<int> rnk(n + 1), lcp(n + 1);
	FOR(i, n + 1) rnk[sa[i]] = i;
	int h = 0;
	lcp[0] = 0;
	FOR(i,n){
		int j = sa[rnk[i] - 1];
		if (h > 0) h--;
		while (j + h < n && i + h < n) {
			if (t[j + h] != t[i + h]) break;
			h++;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

int main() {
	string s;
	cin >> s;
	auto sa = buildSA(s);
	const int n = sz(s);

	vector<Pii> v;
	int l = 1, r = n;
	FOR(i, sz(s)) {
		while (l <= r) {
			int j = sa[l];
			if (i + j < n && s[i + j] == s[i]) break;
			l++;
		}
		while (l <= r) {
			int j = sa[r];
			if (i + j < n && s[i + j] == s[i]) break;
			r--;
		}
		if (n - sa[l] == i + 1) {
			v.emplace_back(i + 1, r - l + 1);
		}
	}

	printf("%d\n", sz(v));
	for (auto kv : v) {
		printf("%d %d\n", kv.first, kv.second);
	}


	return 0;
}