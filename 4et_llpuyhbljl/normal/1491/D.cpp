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
	ll a, b;
	cin >> a >> b;
	vector<int>va, vb;
	for (int i = 0; i < 30; ++i) {
		if ((a & (1 << i)) != 0)va.push_back(i);
		if ((b & (1 << i)) != 0)vb.push_back(i);
	}
	if (va.size() < vb.size()) {
		cout << "NO\n";
		return;
	}
	vector<int>ct(vb.size()), c1(vb.size());
	bool f = 0;
	int asz = va.size(), bsz = vb.size();
	for (int i = 0; i < bsz; ++i) {
		for (auto x : va) {
			ct[i] += x <= vb[i];
			c1[i] |= x == vb[i];
		}
	}
	if (va.back() > vb.back()) {
		cout << "NO\n";
		return;
	}
	for (int i = bsz - 2; i >= 0; --i) {
		c1[i] &= c1[i + 1];
	}
	for (int i = bsz - 1; i >= 0; --i) {
		if (ct[i] < i + 1) {
			cout << "NO\n";
			return;
		}
		int bf = 0;
		if (i)bf = ct[i - 1];
		if (c1[i] && ct[i] - bf > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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