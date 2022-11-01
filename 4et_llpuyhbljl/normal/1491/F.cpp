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
const ll INF = 1e9;
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
	cout << "0\n";
	exit(0);
}
void solve() {
	int n;
	cin >> n;
	set<int>ans;
	for (int i = 1; i <= n; ++i)ans.insert(i);
	int idx;
	for (int i = n - 1; i >= 1; --i) {
		int l1 = i, r1 = i, l2 = i + 1, r2 = n;
		cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
		for (int j = l1; j <= r1; ++j)cout << j << " "; cout << endl;
		for (int j = l2; j <= r2; ++j)cout << j << " "; cout << endl;
		ll f;
		cin >> f;
		if (f != 0) {
			idx = i;
			break;
		}
	}
	ans.erase(idx);
	for (int i = idx - 1; i >= 1; --i) {
		cout << "? 1 1" << endl;
		cout << i << endl;
		cout << idx << endl;
		ll f;
		cin >> f;
		if (f != 0) {
			ans.erase(i);
		}
	}
	int b = idx, e = n;
	while (b + 1 != e) {
		int m = (b + e) / 2;
		int l1 = idx, r1 = idx, l2 = idx + 1, r2 = m;
		cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
		for (int j = l1; j <= r1; ++j)cout << j << " "; cout << endl;
		for (int j = l2; j <= r2; ++j)cout << j << " "; cout << endl;
		ll f;
		cin >> f;
		if (f != 0)e = m;
		else b = m;
	}
	ans.erase(e);
	cout << "! ";
	cout << ans.size() << " ";
	for (auto x : ans)cout << x << " ";
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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