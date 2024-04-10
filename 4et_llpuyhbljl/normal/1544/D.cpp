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
typedef unsigned short us;
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
const ll INF = 1e18 + 100;
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 250010, maxT = 4010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1), u1(n + 1), u2(n + 1), ans(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!u2[a[i]]) {
			u2[a[i]] = 1;
			u1[i] = 1;
			ans[i] = a[i];
			++cnt;
		}
	}
	set<int>s1, s2, s3;
	for (int i = 1; i <= n; ++i) {
		if (u1[i] && u2[i])
			continue;
		if (u1[i] && !u2[i]) {
			s1.insert(i);
			continue;
		}
		if (!u1[i] && u2[i]) {
			s2.insert(i);
			continue;
		}
		s3.insert(i);
	}
	if (s1.empty() && s3.size() == 1) {
		int id = *s3.begin();
		ans[id] = a[id];
		u1[id] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i == id)
				continue;
			if (ans[i] == ans[id]) {
				u1[i] = 0;
				ans[i] = 0;
			}
		}
		s1.clear();
		s2.clear();
		s3.clear();
		for (int i = 1; i <= n; ++i) {
			if (u1[i] && u2[i])
				continue;
			if (u1[i] && !u2[i]) {
				s1.insert(i);
				continue;
			}
			if (!u1[i] && u2[i]) {
				s2.insert(i);
				continue;
			}
			s3.insert(i);
		}
	}
	if (s3.size() == 1) {
		int id = *s2.begin();
		ans[id] = *s3.begin();
		s2.erase(s2.begin());
		s2.insert(ans[id]);
		s3.clear();
	}
	while (!s1.empty()) {
		ans[*s2.begin()] = *s1.begin();
		s2.erase(s2.begin());
		s1.erase(s1.begin());
	}
	vector<int>bb;
	for (auto x : s3)bb.push_back(x);
	for (int i = 0; i < bb.size(); ++i) {
		ans[bb[i]] = bb[(i + 1) % bb.size()];
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}