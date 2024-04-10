#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18;
const int mod = 998244353;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 10010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
ll get(vector<ll>a, vector<ll>b) {
	vector<ll>good(b.size());
	ll y = 0;
	for (int i = 0; i < b.size(); ++i) {
		while (y < (int)a.size() && a[y] < b[i])++y;
		if (y < a.size() && a[y] == b[i])++good[i];
	}
	for (int i = (int)b.size() - 2; i >= 0; --i)good[i] += good[i + 1];
	ll res = 0;
	y = 0;
	for (int i = 0; i < b.size(); ++i) {
		//res = max(res, good[i]);
		while (y < (int)a.size() && a[y] < b[i])++y;
		ll tmp = 0;
		if (i + 1 != b.size()) {
			tmp = good[i + 1];
		}
		int j;
		if (y < a.size() && a[y] == b[i])j = lower_bound(b.begin(), b.end(), b[i] - y) - b.begin();
		else {
			j = lower_bound(b.begin(), b.end(), b[i] - y + 1) - b.begin();
		}
		tmp += i - j + 1;
		res = max(res, tmp);
	}
	return res;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>>a(2), b(2);
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		if (v < 0)a[0].push_back(-v);
		else a[1].push_back(v);
	}
	reverse(a[0].begin(), a[0].end());
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ll v;
		cin >> v;
		if (v < 0)b[0].push_back(-v);
		else b[1].push_back(v);
	}
	reverse(b[0].begin(), b[0].end());
	for (int j = 0; j < 2; ++j)ans += get(a[j], b[j]);
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("labyrinth.in", "r", stdin); freopen("labyrinth.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}