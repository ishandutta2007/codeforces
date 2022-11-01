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
#include <numeric>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
//#define ll long long
using ll = long long;
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
//const int N = 5e5 + 11;
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

int nxt(int i) {
	if (i < n - 1) {
		return i + 1;
	}
	return 0;
}

set<int>::iterator nxt(set<int>::iterator it, const set<int>& setik) {
	auto kek = next(it);
	if (kek == setik.end()) {
		return setik.begin();
	}
	return kek;
}

void solve(ostream& cout) {
	//cout << "BLYAT ";

	if (n == 1) {
		if (a[0] == 1) {
			cout << "1 1\n";
		}
		else {
			cout << 0 << '\n';
		}
		return;
	}
	set<int> pos;
	set<int> keks;
	for (int i = 0; i < n; i++) {
		pos.insert(i);
		if (gcd(a[i], a[nxt(i)]) == 1) {
			keks.insert(i);
		}
	}

	vector<int> ord;
	auto it = keks.begin();
	while (!keks.empty()) {
		int i = *it;
		int j = *nxt(pos.lower_bound(i), pos);
		ord.push_back(j);
		keks.erase(j);
		pos.erase(j);

		if (pos.size() == 1) {
			break;
		}
		j = *nxt(pos.lower_bound(i), pos);

		auto koks = nxt(it, keks);
		if (gcd(a[i], a[j]) == 1) {
			// ignore
		}
		else {
			keks.erase(it);
		}
		it = koks;
	}

	if (pos.size() == 1 && a[*pos.begin()] == 1) {
		ord.push_back(*pos.begin());
	}

	cout << ord.size() << ' ';
	for (auto x : ord) {
		cout << x + 1 << ' ';
	}
	cout << '\n';

	//cout << "BLYAT\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		read(cin);
		solve(cout);
	}
}