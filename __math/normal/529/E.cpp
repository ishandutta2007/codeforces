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

int a[5000];

int main() {
	int n, k; cin >> n >> k;
	FOR(i, n) cin >> a[i];
	int q; cin >> q;
	map<int, int> mp;

	FOR(i, n){
		int x = a[i];
		FOR(j, k + 1) {
			if (mp.count(x*j)) chmin(mp[x*j], j);
			else mp[x*j] = j;
		}
	}
	mp[0] = 0;

	FOR(i, q){
		int x; cin >> x;
		int ans = k + 1;
		for (auto kv : mp) {
			if (x < kv.first) break;
			auto it = mp.find(x - kv.first);
			if (it != mp.end()) ans = min(ans, kv.second + it->second);
		}
		if(ans <= k) cout << ans << endl;
		else cout << -1 << endl;
	}
}