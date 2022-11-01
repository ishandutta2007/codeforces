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

int d[1 << 16], s[1 << 16];
vector<Pii> anses;

void dfs(int from){
	if (d[from] == 0) return;
	int to = s[from];
	d[from]--; d[to]--;
	s[to] ^= from; s[from] ^= to;
	anses.push_back(Pii(to, from));
	if (d[to] == 1) {
		dfs(to);
	}
}

int main(){
	int n; scanf("%d", &n);
	FOR(i, n)  cin >> d[i] >> s[i];

	int m = accumulate(d, d + n, 0) / 2;

	FOR(i, n) if (d[i] == 1) dfs(i);

	cout << sz(anses) << endl;
	for (auto kv : anses) {
		cout << kv.first << " " << kv.second << endl;
	}
}