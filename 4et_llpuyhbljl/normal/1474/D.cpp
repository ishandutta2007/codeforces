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
bool good(vector<ll>a) {
	for (int i = 1; i < a.size(); ++i) {
		a[i] -= a[i - 1];
		if (a[i] < 0)return false;
	}
	return a.back() == 0;
}
bool get_ans(vector<ll>a) {
	int n = a.size();
	vector<ll>p = a, s = a, b = a;
	if (good(a))return true;
	swap(a[0], a[1]);
	if (good(a))return true;
	swap(a[0], a[1]);
	swap(a.back(), a[a.size() - 2]);
	if (good(a))return true;
	swap(a.back(), a[a.size() - 2]);
	for (int i = 1; i < n; ++i) {
		if (p[i - 1] == -1 || b[i] < b[i - 1]) {
			p[i] = -1;
		}
		else {
			b[i] -= b[i - 1];
			b[i - 1] = 0;
			p[i] = b[i];
		}
	}
	b = a;
	for (int i = n - 2; i >= 0; --i) {
		if (s[i + 1] == -1 || b[i] < b[i + 1]) {
			s[i] = -1;
		}
		else {
			b[i] -= b[i + 1];
			b[i + 1] = 0;
			s[i] = b[i];
		}
	}
	for (int i = 1; i + 2 < n; ++i) {
		if (min(p[i - 1], s[i + 2]) == -1)continue;
		vector<ll>c = { p[i - 1],a[i + 1],a[i],s[i + 2] };
		if (good(c))return true;
	}
	return false;
}
void solve() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (auto& x : a)cin >> x;
	bool tmp = get_ans(a);
	reverse(a.begin(), a.end());
	tmp |= get_ans(a);
	if (tmp) {
		cout << "YES\n";
	}
	else cout << "NO\n";
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