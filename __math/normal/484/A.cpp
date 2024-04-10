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

vector<int> f(ll x){
	vector<int> ret;
	FOR(i, 63){
		ret.push_back(x % 2);
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

ll solve(ll l, ll r){
	auto L = f(l);
	auto R = f(r);
	int i = 0;
	ll ret = 0;
	while (i < sz(L) && L[i] == R[i]) {
		ret = ret * 2 + L[i];
		i++;
	}
	bool b = true;
	for (int j = i; j < sz(L); j++) if (R[j] == 0) b = false;
	ll add = 0;
	for (int j = i; j < sz(L); j++) ret *= 2, add = add * 2 + 1;
	if (b) ret += add;
	else ret += add / 2;
	return ret;

}

int main() {
	int n; cin >> n;
	while (n--) {
		ll l, r; cin >> l >> r;
		cout << solve(l, r) << endl;
	}
}