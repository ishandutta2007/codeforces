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

typedef pair<int, string> P;

struct Q {
	ll len, val, tens;
};

int main() {
	string s; cin >> s;
	int n; cin >> n;
	
	vector<P> vp;

	FOR(i, n) {
		string x; cin >> x;
		int from = x[0] - '0';
		string to = x.substr(3);
		vp.emplace_back(from, to);
	}

	Q memo[10];
	FOR(i, 10) {
		memo[i].len = 1; // len ,mod = (MOD - 1)
		memo[i].val = i; // val ,mod = MOD
		memo[i].tens = 10; //10^len % MOD
	}

	for (int i = n - 1; i >= 0; i--) {
		const P& p = vp[i];
		int from = p.first;
		ll after_len = 0;
		ll val_sum = 0;
		ll cur_tens = 1;
		for(int j = p.second.length() - 1; j >= 0; j--){
			const char c = p.second[j];
			after_len += memo[c - '0'].len;
			ll add_val = memo[c - '0'].val * cur_tens % MOD;
			val_sum += add_val;
			cur_tens = cur_tens * memo[c - '0'].tens % MOD;
		}
		after_len %= (MOD - 1);
		memo[from].len = after_len;
		memo[from].val = val_sum % MOD;
		memo[from].tens = cur_tens;
	}

	ll ans = 0;
	{
		ll after_len = 0;
		ll cur_tens = 1;
		for (int i = sz(s) - 1; i >= 0; i--) {
			char c = s[i];
			after_len += memo[c - '0'].len;
			ll add_val = memo[c - '0'].val * cur_tens % MOD;
			ans += add_val;
			cur_tens = cur_tens * memo[c - '0'].tens % MOD;
		}
	}

	cout << ans % MOD << endl;


	return 0;
}