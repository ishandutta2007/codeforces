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

bool f(const string& l, int n, int p, string &ret) {
	for (int i = 1; i < sz(l); i++) {
		if (l[i - 1] == l[i]) return false;
		if (i > 1 && l[i - 2] == l[i]) return false;
	}
	ret = l;
	for (int i = sz(l); i < n; i++) {
		bool ok = false;
		for (char c = 'a'; c < 'a' + p; c++) {
			if (ret[i - 1] == c) continue;
			if (i > 1 && ret[i - 2] == c) continue;
			ok = true;
			ret.push_back(c);
			break;
		}
		if (!ok) return false;
	}
	return true;
}

int main() {
	int n, p; cin >> n >> p;
	string s; cin >> s;

	for (int i = sz(s) - 1; i >= 0; i--) {
		for (char c = s[i] + 1; c < 'a' + p; c++) {
			string sp = s.substr(0, i);
			sp.push_back(c);
			string ret;
			bool b = f(sp, n, p, ret);
			if (b) {
				cout << ret << endl;
				return 0;
			}
		}
	}

	puts("NO");
	return 0;
}