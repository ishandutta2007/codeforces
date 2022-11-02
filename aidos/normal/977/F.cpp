#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

//#include<bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define For (i, x, y)  for (ll i = x; i <= y; i ++) 
#define FOr (i, x, y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

using namespace std;

bool isvowel (char c) {
	c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u') return 1;
    return 0;
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 3e5 + 123;                                          
const int PRI = 555557;
const int pri = 997;
const int Magic = 2101;

//const int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
//const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};


int n, m, k;
int a[N];
int Sz = 1;
int p[N];
unordered_map < int, pair < int, int > > dp;

inline void Solve () {
	cin >> n;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int mx, pos;
	mx = pos = 0;
	dp.reserve(n * 4);
	for (int i = 1; i <= n; i ++) {
		pair < int, int > cur = dp[a[i] - 1];
		p[i] = cur.S;
		cur.F ++;
	//	cout << cur.F << ' ' << cur.S
		dp[a[i]] = mp(cur.F, i);
		if (cur.F > mx)
			pos = i, mx = cur.F;
		 
	}
	vector < int > ans;
	while (pos) {
		ans.pb(pos);
		pos = p[pos];
	}	

	reverse(all(ans));

	cout << ans.size() << '\n';
	for (auto it : ans)
		cout << it << ' ';

}

int main () {
	int tests = 1;
	SpeedForce;
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	
	//cin >> tests;
	while(tests --) {
		Solve ();
		// TooSimple ? True : False
	}
	// Accepted ? True : True
	return Accepted; 
}