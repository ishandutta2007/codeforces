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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

int main() {
	int n; scanf("%d",&n);
	vector<string> f(n), s(n);
	FOR(i, n) {
		char tmp[100];
		scanf("%s",tmp);
		f[i] = tmp;
		scanf("%s", tmp);
		s[i] = tmp;
	}
	vector<int> p(n);
	FOR(i, n) scanf("%d", &p[i]);
	FOR(i, n) p[i]--;

	string prev;
	bool ok = true;
	for (auto i : p) {
		string mn = min(f[i], s[i]);
		string mx = max(f[i], s[i]);
		if (prev < mn) prev = mn;
		else if (prev < mx) prev = mx;
		else {
			ok = false;
			break;
		}
	}

	puts(ok ? "YES" : "NO");

	return 0;
}