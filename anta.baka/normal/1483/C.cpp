#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 998244353;
const int INF = 1e5;
const int MaXN = 150;
const int N = 5e5 + 11;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0, (ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
	a += b;
	if (a < 0LL) a += MOD;
	if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;

}
int to_i(char c)
{
	return c - 'a';
}
ll mult(ll a, ll b) {
	ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
	if (val < 0) {
		val += MOD;
	}
	if (val >= MOD) {
		val -= MOD;
	}
	return val;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0LL; y = 1LL;
		return b;
	}
	ll x1, y1;
	ll d = gcd_eu(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long poww(long long a, long long b)
{
	long long val = 1;
	a %= MOD;
	while (b > 0)
	{
		if (b % 2) val = mult(a, val);
		a = mult(a, a);
		b >>= 1;
	}
	return val % MOD;
}
ll inv(ll a)
{
	return poww(a, MOD - 2);
}
#define int ll

const int inf = 1e18 + 228;

struct ST {
	int n;
	vector<int> t;

	ST(int n) : n(n), t(2 * n, -inf) {}

	void upd(int v, int x) {
		t[v += n] = x;
		for (v >>= 1; v; v >>= 1) {
			t[v] = max(t[v << 1], t[v << 1 | 1]);
		}
	}

	int get(int l, int r) {
		int ret = -inf;
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				ret = max(ret, t[l]);
			}
			if (!(r & 1)) {
				ret = max(ret, t[r]);
			}
		}
		return ret;
	}
};

int n;
vector<int> h;
vector<int> b;

void read(istream& cin) {
	cin >> n;
	h.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
}

void solve(ostream& cout) {
	vector<int> suf(n + 1);
	suf[n] = inf;
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], h[i]);
	}

	vector<int> st;
	vector<int> pred(n, -1);
	for (int i = 0; i < n; i++) {
		while (!st.empty() && h[st.back()] > h[i]) {
			st.pop_back();
		}
		if (!st.empty()) {
			pred[i] = st.back();
		}
		st.push_back(i);
	}

	vector<int> dp(n, -inf);
	st.clear();
	multiset<int> val;
	ST t(n);

	for (int i = 0; i < n; i++) {
		{
			int j = pred[i] + 1;
			if (i != j) {
				dp[i] = max(dp[i], t.get(j, i - 1) + b[i]);
			}
		}

		{
			while (!st.empty() && h[st.back()] > h[i]) {
				val.erase(val.find(dp[st.back()]));
				st.pop_back();
			}

			if (!st.empty()) {
				dp[i] = max(dp[i], *(--val.end()) + b[i]);
			}
		}

		{
			if (pred[i] == -1) {
				dp[i] = max(dp[i], b[i]);
			}
		}

		{
			st.push_back(i);
			val.insert(dp[i]);
			t.upd(i, dp[i]);
		}
	}

	int ans = -inf;
	for (int i = 0; i < n; i++) {
		if (h[i] == suf[i]) {
			ans = max(ans, dp[i]);
		}
	}
	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		read(cin);
		solve(cout);
	}
}