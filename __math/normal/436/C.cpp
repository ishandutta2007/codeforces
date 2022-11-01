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

int n, m, k, w;

char s[1001][101];
int cost[1000][1000];

int cur[1000];
int from[1000];


int main() {
	cin >> n >> m >> k >> w;
	FOR(i, k) {
		FOR(j, n) {
			cin >> (s[i] + j * m);
		}
	}

	int nm = n * m;
	FOR(i, k) {
		for (int j = i + 1; j < k; j++) {
			int diff = 0;
			FOR(a, nm) {
				if (s[i][a] != s[j][a]) diff++;
			}
			cost[i][j] = cost[j][i] = diff * w;
		}
	}

	bool used[1000] = {};
	vector<Pii> anses;
	anses.emplace_back(1, 0);
	ll ans = nm;
	FOR(i, k) cur[i] = nm;
	used[0] = true;
	FOR(i, k - 1) {
		int p = anses.back().first - 1;
		int min_id = -1,min_cost = nm + 1;
		FOR(j, k) if (!used[j]) {
			int c = cost[p][j];
			if (cur[j] > c) {
				cur[j] = c;
				from[j] = p + 1;
			}
			if (min_cost > cur[j]) {
				min_cost = cur[j];
				min_id = j;
			}
		}
		anses.emplace_back(min_id + 1, from[min_id]);
		used[min_id] = true;
		ans += min_cost;
	}

	cout << ans << endl;
	FOR(i, sz(anses)) {
		cout << anses[i].first << " " << anses[i].second << endl;
	}
}