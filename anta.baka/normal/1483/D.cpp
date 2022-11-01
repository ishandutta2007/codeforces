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

struct E {
	int v, w;
};

const int N = 601;

int n, m;
vector<E> g[N];
int q;
vector<E> tr[N];

void read(istream& cin) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		--u; --v;
		tr[u].push_back({ v, l });
		tr[v].push_back({ u, l });
	}
}

bool yep[N][N];

void ins(int u, int v) {
	if (u > v) {
		swap(u, v);
	}
	yep[u][v] = true;
}

const ll inf = 1e18L;
ll kek[N][N];

ll d[N];
char vis[N];

void solve(ostream& cout) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			kek[i][j] = kek[j][i] = inf;
		}
	}

	for (int u = 0; u < n; u++) {
		for (const auto& e : g[u]) {
			kek[u][e.v] = e.w;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				kek[i][j] = min(kek[i][j], kek[i][k] + kek[k][j]);
			}
		}
	}

	for (int u = 0; u < n; u++) {
		if (tr[u].empty()) {
			continue;
		}

		for (int i = 0; i < n; i++) {
			vis[i] = false;
			d[i] = 0;
		}

		for (const auto& t : tr[u]) {
			d[t.v] = max(d[t.v], (ll)t.w);
		}

		for (int it = 0; it < n; it++) {
			int piv = -1;
			for (int v = 0; v < n; v++) {
				if (vis[v] == false && (piv == -1 || d[v] > d[piv])) {
					piv = v;
				}
			}
			if (piv == -1) {
				break;
			}

			vis[piv] = true;
			for (const auto& e : g[piv]) {
				d[e.v] = max(d[e.v], d[piv] - e.w);
			}
		}

		for (int z = 0; z < n; z++) {
			for (const auto& e : g[z]) {
				ll rem = d[e.v];
				if (rem >= e.w + kek[u][z]) {
					ins(z, e.v);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += yep[i][j];
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--) {
		read(cin);
		solve(cout);
	}
}