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

ll x[100], k[100];
int vm[100];
int n, m;
ll b;

ll dp[1 << 20];

ll add(ll md) {
	FOR(i, n) {
		if (k[i] != md) continue;
		FOR(j, 1 << m) if(dp[j] != -1) {
			int a = j | vm[i];
			if (dp[a] == -1) dp[a] = dp[j] + x[i];
			else dp[a] = fastMin(dp[a], dp[j] + x[i]);
		}
	}

	return dp[(1 << m) - 1];
}

int main() {

	cin >> n >> m >> b;

	FOR(i, n) {
		int km; cin >> x[i] >> k[i] >> km;
		FOR(j, km) {
			int a; cin >> a;
			vm[i] |= (1 << (a - 1));
		}
	}

	set<ll> s;
	FOR(i, n) s.insert(k[i]);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	ll ans = -1;
	for (auto i : s) {
		ll val = add(i);
		if (val == -1) continue;
		ll cur_ans = i * b + val;
		if (ans == -1) ans = cur_ans;
		else ans = min(ans, cur_ans);
	}

	cout << ans << endl;

	return 0;
}