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
const int maxN = 1000100, maxT = 1601;
vector<int>p;
int pr[maxN];
vector<int>f;
vector<int>mn;
vector<int>ct;
int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	mn[a] = gcd(mn[a], mn[b]);
	ct[a] += ct[b];
	f[b] = a;
}
bool is_it_good(int v) {
	for (int i = 2; i * i <= v; ++i) {
		int b = 0;
		while (v % i == 0) {
			v /= i;
			++b;
		}
		if (b % 2 == 1)return false;
	}
	return v == 1;
}
void solve() {
	int n;
	cin >> n;
	vector<ll>ans(3);
	map<int, vector<int>>mp;
	f.assign(n, 0);
	mn.assign(n, 0);
	ct.assign(n, 0);
	vector<int>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (auto j1 : p) {
			int j = j1 * j1;
			if (j > a[i])break;
			while (a[i] % j == 0)a[i] /= j;
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		f[i] = i;
		mn[i] = a[i];
		ct[i] = 1;
		mp[a[i]].push_back(i);
	}
	int ct_good = 0;
	for (int i = 0; i < n; ++i) {
		for (int j1 = 1; j1 * j1 <= 1; ++j1) {
			int j = j1 * j1;
			if (a[i] % j == 0 && mp.count(a[i] / j) && mp[a[i] / j][0] < i) {
				uni(mp[a[i] / j][0], i);
			}
		}
	}
	vector<int>used(n);
	for (int i = 0; i < n; ++i) {
		int j = find(i);
		if (used[j])continue;
		used[j] = 1;
		ans[0] = max(ans[0], (ll)ct[j]);
		if (ct[j] % 2 == 0 || is_it_good(mn[j])) {
			ct_good += ct[j];
		}
	}
	ans[1] = max(ans[0],(ll)ct_good);
	int q;
	cin >> q;
	while (q--) {
		ll w;
		cin >> w;
		cout << ans[min(1LL, w)] << "\n";
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
	for (int i = 2; i < maxN; ++i) {
		if (pr[i] == 0) {
			p.push_back(i);
			for (int j = i; j < maxN; j += i)pr[j] = 1;
		}
	}
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}