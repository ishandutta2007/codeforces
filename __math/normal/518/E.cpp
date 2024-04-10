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

const int UK = ten(9) + 10;
int a[ten(5)];
int LW,UP;

ll h(ll x, ll y){
	ll cnt = (abs(y - x) + 1);
	return (x + y) * cnt / 2;
}

ll g(ll start, int len){
	ll end = start + len - 1;
	ll ret1 = 0;
	if (start < 0) ret1 = h(abs(start), abs(min(end, 0LL)) );
	ll ret2 = 0;
	if (end > 0) ret2 = h(abs(max(start, 0LL)), abs(end));

	return ret1 + ret2;
}

int f(ll lower, ll upper, int len){
	lower++;
	upper -= len - 1;
	if (upper <= lower) return UK;
	if (len == 0) return 0;

	ll l = lower, r = upper;
	while (r - l >= 5) {
		ll md1 = (r + l) / 2;
		ll md2 = md1 + 1;
		ll r1 = g(md1, len);
		ll r2 = g(md2, len);
		if (r1 < r2) r = md2;
		else l = md1;
	}

	ll mn_id = -1, mn_val = LLONG_MAX;
	for (ll i = l; i < r; i++) {
		ll val = g(i, len);
		if (val < mn_val) {
			mn_id = i;
			mn_val = val;
		}
	}

	return (int)mn_id;
}

bool solve(int n, int k){
	LW = INT_MIN;
	UP = INT_MAX;

	ll ans = 0;
	FOR(i, k){
		vector<int*> v;
		v.push_back(&LW);

		for (int j = i; j < n; j += k) {
			v.push_back(a + j);
			if(*(v.back()) != UK) {
				int rt = f(*(v.front()),*(v.back()), sz(v) - 2);
				if (rt == UK) return false;
				for (int idx = 1; idx < sz(v) - 1; idx++) {
					*(v[idx]) = rt + idx - 1;
				}
				v.clear();
				v.push_back(a + j);
			}
		}
		v.push_back(&UP);
		if (sz(v) != 2) {
			int rt = f(*(v.front()), *(v.back()), sz(v) - 2);
			if (rt == UK) return false;
			for (int idx = 1; idx < sz(v) - 1; idx++) {
				*(v[idx]) = rt + idx - 1;
			}
		}
	}

	return true;
}

int main(){
	int n, k; scanf("%d%d", &n, &k);
	FOR(i, n){
		char s[100]; scanf("%s", s);
		if (s[0] == '?') a[i] = UK;
		else a[i] = atoi(s);
	}

	bool b = solve(n, k);
	if (b) {
		FOR(i, n) printf("%d ", a[i]);
		puts("");
	} else {
		puts("Incorrect sequence");
	}

}