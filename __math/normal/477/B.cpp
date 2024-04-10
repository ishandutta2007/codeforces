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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

vector<vector<int> > anses;

void solve(int n) {
	deque<int> two, three;
	set<int> s;
	FOR(i, ten(5)) {
		if (i % 6 == 0) continue;
		if (i % 2 == 0) two.push_back(i);
		else if (i % 3 == 0) three.push_back(i);
		else s.insert(i);
	}
	FOR(i, n) {
		vector<int> cur;
		cur.push_back(two.front());
		two.pop_front();
		cur.push_back(three.front());
		three.pop_front();
		FOR(j, 2) {
			int use = -1;
			for (auto v : s) {
				bool ok = true;
				if (sz(cur) == 4) break;
				for (auto u : cur) {
					if (gcd(v, u) != 1) {
						ok = false;
						break;
					}
				}
				if (ok) {
					use = v;
					break;
				}
			}
			s.erase(use);
			cur.push_back(use);
		}
		anses.push_back(cur);
	}
}

int main() {
	int n, k; cin >> n >> k;

	solve(n);
	int mx = 0;
	FOR(i, n) FOR(j, 4) mx = max(mx, anses[i][j]);
	printf("%I64d\n", mx * ll(k));
	FOR(i, n) FOR(j, 4) printf("%I64d%c", anses[i][j] * ll(k), j == 3 ? '\n' : ' ');

	return 0;
}