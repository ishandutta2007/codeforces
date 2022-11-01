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

typedef pair<char, int> P;

int app[ten(5)];
bool ans[ten(5)];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<P> v;
	memset(app, -1, sizeof(app));
	FOR(i, m) {
		char c; int x;
		scanf(" %c %d", &c, &x);
		x--;
		v.emplace_back(c, x);
		if (app[x] == -1) {
			app[x] = c == '+' ? 0 : 1;
		}
	}
	FOR(i, n) ans[i] = true;
	int num = 0;
	FOR(i, n) if (app[i] == 1) num++;
	set<int> s;
	FOR(i, m) {
		if (v[i].first == '-') {
			num--;
			if (num != 0) ans[v[i].second] = false;
			else s.insert(v[i].second);
		} else {
			if (num != 0) ans[v[i].second] = false;
			else s.insert(v[i].second);
			num++;
		}
	}
	if (sz(s) > 1) {
		for (auto i : s) ans[i] = false;
	}

	vector<int> disp;
	FOR(i, n) if (ans[i]) disp.push_back(i);
	printf("%d\n", sz(disp));
	FOR(i, sz(disp)) printf("%d%c", disp[i] + 1, i == sz(disp) - 1 ? '\n' : ' ');

	return 0;
}