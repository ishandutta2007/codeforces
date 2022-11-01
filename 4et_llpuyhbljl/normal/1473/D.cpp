
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
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 1601;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<pair<int, int>>vi(n + 1), vi1(n + 1);
	vector<int>nw(n + 1), sub(n + 1);
	int b = 0;
	for (int i = 1; i <= n; ++i) {
		vi[i] = vi[i - 1];
		if (s[i - 1] == '+')++b;
		else --b;
		sub[i] = b;
		vi[i].first = min(vi[i].first, b);
		vi[i].second = max(vi[i].second, b);
	}
	b = 0;
	nw = sub;
	vi1.back() = { sub.back(),sub.back() };
	for (int i = n - 1; i >= 0; --i) {
		vi1[i] = vi1[i + 1];
		if (s[i] == '+')++b;
		else --b;
		vi1[i].first = min(vi1[i].first, sub[i]);
		vi1[i].second = max(vi1[i].second, sub[i]);
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		--l;
		int mx = max(vi[l].second, sub[l] + vi1[r].second - nw[r]);
		int mn = min(vi[l].first, sub[l] + vi1[r].first - nw[r]);
		cout << mx - mn + 1 << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}