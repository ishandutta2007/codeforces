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

#ifdef _WIN32
typedef ll i128;
#else 
typedef __int128 i128;
#endif

ll c;
ll f1(Pll a, Pll b){
	ll ret = 0;
	for (ll i = 0; i * a.second <= c; i++) {
		ll rem = c - i * a.second;
		if (rem < 0) continue;
		ll ans = (rem / b.second) * b.first + i * a.first;
		ret = max(ret, ans);
	}
	return ret;
}

template<class T> T extgcd(T a, T b, T& x, T& y){
	for (T u = y = 1, v = x = 0; a;) {
		T q = b / a;
		swap(x -= q * u, u);
		swap(y -= q * v, v);
		swap(b -= q * a, a);
	}
	return b;
}

ll f2(Pll a, Pll b){
	ll l = a.second * b.second;
	ll lcm_par_hi = max(b.second * a.first, a.second * b.first);
	ll lp = max(c / l - 3, 0LL);
	ll add = lp * lcm_par_hi;
	c -= l * lp;
	ll ret = f1(a, b);
	return ret + add;
}

int main(){
	Pll a, b; 
	cin >> c >> a.first >> b.first >> a.second >> b.second;
	if (a.second < b.second) swap(a, b);
	ll g = gcd(a.second, b.second);
	c /= g;
	a.second /= g;
	b.second /= g;

	ll ans = 0;
	if (a.second > ten(5)) {
		ans = f1(a, b);
	} else {
		ans = f2(a, b);
	}
	cout << ans << endl;
}