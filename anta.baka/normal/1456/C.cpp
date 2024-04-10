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
//#define int ll

int n, k;
vector<int> a;

void read(istream& cin) {
	cin >> n >> k;
	a.resize(n);
	for (auto& x : a) {
		cin >> x;
	}
}

mt19937 rng(228);

void gen() {
	n = 10;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] = rng() % 10 - 5;
	}
}

vector<int> b3(int x) {
	vector<int> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = x % 3;
		x /= 3;
	}
	return ret;
}

int f(vector<int>& a) {
	int ret = 0;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		ret += a[i] * (n - i - 1);
	}
	return ret;
}

void solve(ostream& cout) {
	int cpos = 0;
	for (int x : a) { cpos += (x >= 0); }
	sort(a.begin(), a.end(), greater<int>());
	int pw = 1;
	for (int i = 0; i < n; i++) {
		pw *= 3;
	}
	int ans = 0;
	vector<int> d[3];
	for (int m = 0; m < pw; m++) {
		auto m3 = b3(m);
		vector<int> c[3];
		for (int i = 0; i < n; i++) {
			c[m3[i]].push_back(a[i]);
		}
		int cur = f(c[0]) + f(c[1]) + f(c[2]);
		if (cur > ans) {
			ans = cur;
			d[0] = c[0];
			d[1] = c[1];
			d[2] = c[2];
		}
	}
	//cout << ans << endl;
	bool any = false;
	for (int m = 0; m < pw; m++) {
		auto m3 = b3(m);
		vector<int> c[3];
		for (int i = 0; i < n; i++) {
			c[m3[i]].push_back(a[i]);
		}
		int cur = f(c[0]) + f(c[1]) + f(c[2]);
		if (cur == ans) {
			for (int i = 0; i < 3; i++) {
				int cnt = 0;
				for (int x : c[i]) { cnt += (x >= 0); }
				any |= (cnt == cpos);
				/*for (int x : c[i]) {
					cout << x << ' ';
				}
				cout << endl;*/
			}
			//cout << endl;
		}
	}
	assert(any == true);
	return;
	for (int i = 0; i < 3; i++) {
		for (int x : d[i]) {
			cout << x << ' ';
		}
		cout << endl;
	}
}

void solve1(ostream& cout) {
	sort(a.begin(), a.end(), greater<int>());
	ll ans = 0;
	multiset<ll> sums;
	for (int i = 0; i < k + 1; i++) {
		sums.insert(0);
	}
	for (auto x : a) {
		auto y = *--sums.end();
		sums.erase(--sums.end());
		ans += y;
		sums.insert(y + x);
	}
	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	{
		read(cin);
		solve1(cout);
		return 0;
	}
	int tn = 0;
	while (true) {
		gen();
		solve(cout);
		if (++tn % 10 == 0) {
			cout << tn << endl;
		}
	}
	int t = 1;
	// cin >> t;
	while (t--) {
		read(cin);
		solve(cout);
	}
}