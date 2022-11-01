#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<class T> ll mod_pow(T a, T n, T mod){
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}


const ll h = 617;
const ll MOD = ten(9) + 9;

ll hs[ten(6) + 1];

void calc(string& s){
	hs[0] = 0;
	FOR(i, sz(s)){
		hs[i + 1] =( hs[i] * h + s[i]) % MOD;
	}
}

ll ht[ten(6) + 1];

void init(){
	ht[0] = 1;
	FOR(i, ten(6)) ht[i + 1] = ht[i] * h % MOD;
}

int ans[ten(6) + 10];

int main(){
	init();
	int n, k; cin >> n >> k;
	if (k == 1) {
		FOR(i, n) putchar('1');
		puts("");
		return 0;
	}
	string s; cin >> s;
	calc(s);
	for (int ab = 1; ab * k <= n; ab++) {
		bool ok = true;
		for (int i = 0, j = 0; j < k; j++,i+=ab) {
			ll x = (hs[ab + i] - hs[i] * ht[ab]) % MOD;
			if (x < 0) x += MOD;
			if (hs[ab] != x) ok = false;
		}
		if (!ok) continue;
		int last_start = ab * k;

		int l = 0, r = ab + 1;
		while (r - l != 1) {
			int md = (l + r) / 2;
			bool u = true;
			int last_end = last_start + md;
			if (last_end > n) u = false;
			else {
				ll np = ht[md];
				ll x = (hs[last_end] - hs[last_start] * np) % MOD;
				if (x < 0) x += MOD;
				if (hs[md] != x) u = false;
			}
			if (u) l = md;
			else r = md;
		}

		ans[last_start]++;
		ans[last_start + r]--;
	}
	FOR(i, n) ans[i + 1] += ans[i];

	FOR(i, n) putchar((ans[i + 1] >= 1) + '0');
	puts("");
}