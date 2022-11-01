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

char s[50][30];
char pp_count[1 << 20];
ll g[1 << 20];
double f[1 << 20];

int main() {

	FOR(i, 1 << 20) {
		char cnt = 0;
		FOR(j, 20) if (i&(1 << j))cnt++;
		pp_count[i] = cnt;
	}

	int n; cin >> n;
	FOR(i, n) cin >> s[i];
	const int m = strlen(s[0]);
	double ans_sum = 0;
	FOR(i, n) {
		memset(g, 0, sizeof(g));
		g[0] = (1LL << n) - 1;
		FOR(j, m) {
			ll val = 0;
			FOR(k, n) {
				if (s[i][j] == s[k][j]) val |= (1LL << k);
			}
			g[1 << j] = val;
		}
		for (int j = 1; j < (1 << m); j++) {
			int l = j & -j;
			int r = j ^ l;
			g[j] = g[l] & g[r];
		}


		const int M2 = (1 << m) - 1;
			

		memset(f, 0, sizeof(f));
		f[0] = 1.0;
		for (int j = 0; j < (1 << m) - 1; j++) {
			if (g[j] == (1LL << i)) continue;
			double nxt = f[j] / (m - pp_count[j]);
			// FOR(k, m) if ((j & (1 << k)) == 0) f[j ^ (1 << k)] += nxt;
			for (int t = ~j & (1 << m) - 1; t;) {
				int u = t & -t;
				t ^= u;
				f[j ^ u] += nxt;
			}
		}
		double tmp = 0;
		FOR(j, 1 << m) {
			if (g[j] == (1LL << i)) {
				tmp += pp_count[j] * f[j];
			}
		}
		ans_sum += tmp;
	}

	printf("%.15lf\n", ans_sum / n);
}