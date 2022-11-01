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

#include <unordered_map>

int main(){
	int n; cin >> n;
	vector<Pii> v(n);
	FOR(i, n) cin >> v[i].first;
	FOR(i, n) cin >> v[i].second;
	unordered_map<int, int> pv, nt;

	for (auto& kv : v) {
		nt = pv;
		if (nt.count(kv.first)) chmin(nt[kv.first], kv.second);
		else nt[kv.first] = kv.second;
		
		for (auto i : pv) {
			int g = gcd(i.first, kv.first);
			if (nt.count(g)) nt[g] = min(nt[g], i.second + kv.second);
			else nt[g] = i.second + kv.second;
		}
		swap(pv, nt);
	}

	int ans = -1;
	if (pv.count(1)) ans = pv[1];
	cout << ans << endl;
}