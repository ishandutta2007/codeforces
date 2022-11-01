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


int main() {
	int n, k, q; cin >> n >> k >> q;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];

	vector<int> even,odd;
	FOR(i, n) if (a[i] % 2 == 0) even.push_back(a[i]); else odd.push_back(a[i]);

	int k_q = k - q;
	if ((k_q - sz(odd)) % 2 != 0) {
		puts("NO");
		return 0;
	}

	vector<vector<int> > ans_odd;
	vector<vector<int> > rem;

	FOR(i, min(k_q,sz(odd)) ) ans_odd.push_back(vector<int>(1,odd[i]));
	for (int i = k_q; i < sz(odd); i += 2) {
		rem.push_back(vector<int>());
		rem.back().push_back(odd[i]);
		rem.back().push_back(odd[i + 1]);
	}

	FOR(i, sz(even)) {
		rem.push_back(vector<int>());
		rem.back().push_back(even[i]);
	}
	vector<vector<int> > ans_even;
	FOR(i, min(q,sz(rem))) {
		ans_even.push_back(rem[i]);
	}
	for (int i = q; i < sz(rem); i++) {
		FOR(j, sz(rem[i])) {
			if (sz(ans_odd)) ans_odd[0].push_back(rem[i][j]);
			else ans_even[0].push_back(rem[i][j]);
		} 
	}

	if (k_q == sz(ans_odd) && q == sz(ans_even)) {

		puts("YES");
		FOR(i, sz(ans_odd)) {
			printf("%d ", sz(ans_odd[i]));
			FOR(j, sz(ans_odd[i])) printf("%d%c", ans_odd[i][j], j == sz(ans_odd[i]) - 1 ? '\n' : ' ');
		}
		FOR(i, sz(ans_even)) {
			printf("%d ", sz(ans_even[i]));
			FOR(j, sz(ans_even[i])) printf("%d%c", ans_even[i][j], j == sz(ans_even[i]) - 1 ? '\n' : ' ');
		}
	} else {
		puts("NO");
	}
}