#pragma comment(linker, "/STACK:9759095000")
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
//#define double long double
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
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
const int maxN = 500100, maxT = 1601;
void solve() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>>a(n);
	vector<int>ans(n, -1);
	for (int i = 0; i < n; ++i) {
		int b, c;
		cin >> b >> c;
		if (b > c)swap(b, c);
		a[i] = make_tuple(b, c, i);
	}
	sort(a.begin(), a.end());
	ll mn = INF;
	int id = -1;
	for (int i = 0; i < n;) {
		int j = i;
		int v1, v2, v3;
		tie(v1, v2, v3) = a[i];
		while (j < n) {
			int t1, t2, t3;
			tie(t1, t2, t3) = a[j];
			if (t1 == v1)++j;
			else break;
		}
		for (int t = i; t < j; ++t) {
			int t1, t2, t3;
			tie(t1, t2, t3) = a[t];
			if (t2 > mn) {
				ans[t3] = id + 1;
			}
		}
		i = j;
		if (v2 < mn) {
			mn = v2;
			id = v3;
		}
	}

	for (auto x : ans)cout << x << " "; cout << "\n";
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