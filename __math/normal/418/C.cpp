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

ll ans[100][100];

void S() {
	int t[100][100];
	FOR(i, 100) FOR(j, 100) t[i][j] = ans[j][i];
	FOR(i, 100) FOR(j, 100) ans[i][j] = t[i][j];
}

bool is_sq(ll x) {
	ll a = (ll)sqrt(x);
	while (a * a < x) {
		a++;
	}

	if (a*a == x) {
		return true;
	}

	return false;
}

vector<int> get(int n) {
	vector<int> a;
	if (n == 1) {
		a.push_back(1);
	} else if (n == 2) {
		a.push_back(3);
		a.push_back(4);
	} else {
		ll val = 0;
		FOR(i, n - 1) {
			a.push_back(2);
		}
		val = (n - 1) * 4;
		for (ll i = 1; i < 100000; i++) {
			if (is_sq(i*i + val)) {
				a.push_back(i);
				return a;
			}
		}
	}
	return a;
}

void solve(int n, int m) {
	auto a = get(n);
	auto b = get(m);
	FOR(i, n) FOR(j, m) ans[i][j] = a[i] * b[j];
}

int main() {

	int n, m; cin >> n >> m;
	bool swaped = false;
	if (n < m) {
		swap(n, m);
		swaped = true;
	}

	solve(n, m);

	if (swaped) {
		S();
		swap(n, m);
	}

	FOR(i, n) FOR(j, m) {
		printf("%d%c", (int)ans[i][j], j == m - 1 ? '\n' : ' ');
	}

	return 0;
}