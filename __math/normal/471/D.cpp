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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int match(vector<int>& s, vector<int>& t) {
	int m = sz(t);
	vector<int> fail(m + 1);
	int j = fail[0] = -1;
	for (int i = 1; i <= m; i++) {
		while (j >= 0 && t[j] != t[i - 1]) j = fail[j];
		fail[i] = ++j;
	}
	int n = sz(s);
	int ret = 0;
	for (int i = 0, k = 0; i < n; i++) {
		while (k >= 0 && t[k] != s[i]) k = fail[k];
		if (++k >= m) {
			ret++;
			k = fail[k];
		}
	}
	return ret;
}

int a[ten(5) * 2], b[ten(5) * 2];
int main() {
	int n, w;
	cin >> n >> w;
	FOR(i, n) cin >> a[i];
	FOR(i, w) cin >> b[i];

	if (w == 1) {
		cout << n << endl;
	} else if (w > n) {
		cout << 0 << endl;
	} else {
		vector<int> adiff;
		FOR(i, n - 1) adiff.push_back(a[i + 1] - a[i]);
		vector<int> bdiff;
		FOR(i, w - 1) bdiff.push_back(b[i + 1] - b[i]);

		int ans = match(adiff, bdiff);
		cout << ans << endl;
	}

}