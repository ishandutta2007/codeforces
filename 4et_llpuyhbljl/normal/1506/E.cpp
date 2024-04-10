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
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 100100, maxT = 301, A = 179, mid = 150;
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
	vector<int>a(n);
	for (auto& x : a)cin >> x;
	vector<int>ans(n, -1);
	set<int>s;
	for (int i = 1; i <= n; ++i)s.insert(i);
	ans[0] = a[0];
	s.erase(a[0]);
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			ans[i] = a[i];
			s.erase(a[i]);
		}
	}
	vector<int>cop_ans = ans;
	set<int>cop_s = s;
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			ans[i] = *s.begin();
			s.erase(*s.begin());
		}
	}
	for (auto x : ans)cout << x << " "; cout << "\n";
	s = cop_s;
	ans = cop_ans;
	int mx = ans[0];
	for (int i = 0; i < n; ++i) {
		mx = max(mx, ans[i]);
		if (ans[i] == -1) {
			auto it = s.lower_bound(mx);
			--it;
			ans[i] = *it;
			s.erase(it);
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
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}