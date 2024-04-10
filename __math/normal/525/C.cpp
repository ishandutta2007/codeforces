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

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

int a[ten(6) + 1];
int main() {
	int n; cin >> n;
	FOR(i, n) {
		int x; cin >> x;
		a[x]++;
	}

	ll p = 0;
	ll ans = 0;
	for (ll i = ten(6); i > 0; i--) {
		if (a[i] + a[i + 1] >= 2) {
			int us = min(2,a[i + 1]);
			a[i + 1] -= us;
			int rem = 2 - us;
			a[i] -= rem;
			if (p == 0) p = i;
			else {
				ans += p * i;
				p = 0;
			}
			i++;
			continue;
		}
	}
	cout << ans << endl;
}