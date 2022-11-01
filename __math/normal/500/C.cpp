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


ll w[500];
int b[1000];

int main(){
	int n, m; cin >> n >> m;
	FOR(i, n) cin >> w[i];
	FOR(i, m) cin >> b[i];
	FOR(i, m) b[i]--;
	ll ans = 0;
	FOR(i, m){
		ll add = 0;
		bool used[1000] = {};
		for (int j = i - 1; j >= 0; j--) {
			if (b[i] == b[j]) break;
			if (used[b[j]]) continue;
			used[b[j]] = true;
			add += w[b[j]];
		}
		ans += add;
	}
	cout << ans << endl;
}