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

vector<int> e[3000];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	FOR(i, m){
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		e[x].push_back(y);
	}
	ll ans = 0;
	FOR(i, n){
		int cnt[3000] = {};
		for (auto to : e[i]) {
			for (auto to2 : e[to]) cnt[to2]++;
		}
		FOR(j, n){
			if (i == j) continue;
			ans += cnt[j] * (cnt[j] - 1);
		}
	}
	cout << ans / 2 << endl;
}