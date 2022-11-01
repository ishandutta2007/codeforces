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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")

const int MOD = ten(9) + 7;

// ax+by=gcd(a,b)x,y(|x| <= b , |y| <= a)
template<class T> T extgcd(T a, T b, T& x, T& y){
	for (T u = y = 1, v = x = 0; a;) {
		T q = b / a;
		swap(x -= q * u, u);
		swap(y -= q * v, v);
		swap(b -= q * a, a);
	}
	return b;
}

// aygcd(a,m)(mod m) ---> return y;
template<class T> T md_inverse(T a, T m){
	//mod_pow
	T x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll fact_t[ten(5) + 10],fact_inv[ten(5) + 10];
//n! % MOD \z
void build_fact_table()
{
	fact_t[0] = 1;
	for (int i = 1; i < sizeof(fact_t) / sizeof(ll); i++) {
		fact_t[i] = (fact_t[i - 1] * i) % MOD;
	}
	FOR(i, sizeof(fact_t) / sizeof(ll)) fact_inv[i] = md_inverse<ll>(fact_t[i], MOD);
}

ll combi(int n, int k){
	if (k < 0 || n < k) return 0;
	return fact_t[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
}

ll tn[ten(5) + 10];
ll tbl[ten(5) + 10];

int main(){
	build_fact_table();
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if (k == 0) {
		ll ans = 0;
		FOR(i, n) (ans = ans * 10 + s[i] - '0') %= MOD;
		cout << ans << endl;
		return 0;
	}

	ll p = 1;
	FOR(i, n){
		int u = n - 2 - i;
		ll x = combi(u, k - 1);
		tbl[i] = p * x % MOD;
		tn[i] = p;
		(p *= 10) %= MOD;
	}

	FOR(i, n) (tbl[i + 1] += tbl[i]) %= MOD;
	ll ans = 0;
	FOR(i, n){
		int u = n - 2 - i;
		const int c = s[i] - '0';
		ll add = 0;
		if (u >= 0) {
			add += tbl[u];
		}
		ll add2 = tn[n-1-i] * combi(i, k) % MOD;
		ans += (add + add2) * c % MOD;
	}
	ans %= MOD;
	cout << ans << endl;
}