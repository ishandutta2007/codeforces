#pragma comment(linker, "/STACK:2759095000")
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
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ull __builtin_popcount(ull x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const ll INF = 8e18 + 1000;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000010, maxT = 50010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll>f, s;
	vector<ll>a(n);
	for (auto& x : a)cin >> x;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		if (b == 1)f.push_back(a[i]);
		else s.push_back(a[i]);
	}
	sort(f.begin(), f.end());
	sort(s.begin(), s.end());
	reverse(f.begin(), f.end());
	reverse(s.begin(), s.end());
	vector<ll>pf = { 0 }, ps = { 0 };
	for (auto x : f)pf.push_back(pf.back() + x);
	for (auto x : s)ps.push_back(ps.back() + x);
	if (pf.back() + ps.back() < m) {
		cout << "-1\n";
		return;
	}
	int j = ps.size() - 1;
	ll ans = INF;
	for (int i = 0; i < pf.size(); ++i) {
		while (j > 0 && pf[i] + ps[j - 1] >= m)--j;
		if (pf[i] + ps[j] < m)continue;
		ans = min(ans, (ll)i + 2 * j);
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
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