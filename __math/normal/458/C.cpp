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

// 1-indexed
template<class T>
class BIT {
	T bit[ten(5) * 2];
	int n;

public:
	BIT() {
		clear(ten(5) * 2 - 1);
	}

	void clear(int N) {
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

vector<int> bs[ten(5) + 1];
BIT<ll> bit1,bit2;

ll f(int x) {
	int l = -1, r = ten(4) + 1;
	while (r - l != 1) {
		int md = (l + r) / 2;
		if (bit1.sum(md) >= x) r = md;
		else l = md;
	}
	ll ret = bit2.sum(r) - (bit1.sum(r) - x) * r;
	return ret;
}

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	FOR(i, n) {
		int a, b; cin >> a >> b;
		if (b == 0) a = 0;
		bs[a].push_back(b);
		if (b == 0) continue;
		bit1.add(b, 1);
		bit2.add(b, b);
	}

	vector<Pii> vp;
	FOR(i, ten(5) + 1) {
		if (i == 0) continue;
		if (sz(bs[i]) > 1) sort(bs[i].rbegin(), bs[i].rend());
		FOR(j, sz(bs[i])) {
			vp.push_back(Pii(j + 1, bs[i][j]));
		}
	}
	sort(vp.begin(), vp.end());
	int voted = sz(bs[0]);
	ll needs_sum = 0;

	ll ans = ll(ten(8)) * ten(8);

	for (int p = n; p >= 0; p--) {
		while (sz(vp) > 0 && vp.back().first >= p) {
			Pii top = vp.back();
			vp.pop_back();
			bit1.add(top.second, -1);
			bit2.add(top.second, -top.second);
			needs_sum += top.second;
			voted++;
		}
		int x = max(0, p - voted);
		ll add = f(x);
		ll cur_ans = needs_sum + add;
		ans = min(ans, cur_ans);
	}

	cout << ans << endl;

	return 0;
}