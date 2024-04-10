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

int n;
vector<int> a;

void read(istream& cin) {
	cin >> n;
	a.resize(n);
	for (auto& x : a) {
		cin >> x;
	}
}

int msb(int x) {
	for (int i = 30; ; i--) {
		if (x >> i & 1) {
			return i;
		}
	}
}

void solve(ostream& cout) {
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = msb(a[i]);
	}
	bool ad = true;
	for (int i = 1; i < n; i++) {
		ad &= (b[i - 1] != b[i]);
	}
	if (ad) {
		cout << -1 << endl;
		return;
	}
	for (int i = 2; i < n; i++) {
		if (b[i - 2] == b[i - 1] && b[i - 1] == b[i]) {
			cout << 1 << endl;
			return;
		}
	}
	vector<int> p(n);
	p[0] = a[0];
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] ^ a[i];
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int x = p[j] ^ (i ? p[i - 1] : 0);
				int y = p[k] ^ p[j];
				if (x > y) {
					int cur = k - i - 1;
					if (ans == -1 || cur < ans) {
						ans = cur;
					}
				}
			}
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