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
int cnt0 = 0, cnt1 = 0;
map<pair<int, int>, char>mp;
vector<set<int>>g;
void add(int a, int b, char c) {
	mp[{a, b}] = c;
	if (g[b].count(a)) {
		++cnt0;
		if (mp[{b, a}] == c)++cnt1;
	}
	g[a].insert(b);
}
void del(int a, int b) {
	char c = mp[{a, b}];
	mp.erase({ a,b });
	if (g[b].count(a)) {
		--cnt0;
		if (mp[{b, a}] == c)--cnt1;
	}
	g[a].erase(b);
}
void solve() {
	int n, q;
	cin >> n >> q;
	g.resize(n);
	while(q--) {
		char b;
		cin >> b;
		if (b == '+') {
			int a, b;
			char c;
			cin >> a >> b >> c;
			add(--a, --b, c);
		}
		else {
			if (b == '-') {
				int a, b;
				cin >> a >> b;
				del(--a, --b);
			}
			else {
				int k;
				cin >> k;
				if ((k % 2 == 1 && cnt0 != 0) || (k % 2 == 0 && cnt1 != 0)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}

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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}