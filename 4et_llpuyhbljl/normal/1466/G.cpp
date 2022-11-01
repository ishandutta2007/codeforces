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
typedef long double ld;
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
const int INF = 1e8;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 512;
vector<ll>pw;
ll ans;
vector<ll>dp;
string t;
int max_lvl;
string s;
void m_rec(string ss, int lvl, vector<ll>mn = vector<ll>(26, 0)) {
	if (lvl > max_lvl)return;
	if (ss.length() == 1) {
		ans = (ans + dp[ss[0] - 'a'] - mn[ss[0] - 'a'] + mod) % mod;
		return;
	}
	string s1, s2;
	int n = ss.length();
	mn[t[lvl - 1] - 'a'] = (mn[t[lvl - 1] - 'a'] + pw[max_lvl - lvl]) % mod;
	for (int i = 0; i < n; i += 2) {
		if (ss[i] != t[lvl - 1])s1 = "-1";
	}
	if (s1 != "-1") {
		for (int i = 1; i < n; i += 2) {
			s1.push_back(ss[i]);
		}
		m_rec(s1, lvl + 1, mn);
	}
	for (int i = 1; i < n; i += 2) {
		if (ss[i] != t[lvl - 1])s2 = "-1";
	}
	if (s2 != "-1") {
		for (int i = 0; i < n; i += 2) {
			s2.push_back(ss[i]);
		}
		m_rec(s2, lvl + 1, mn);
	}
}
void my_del(string w, int p) {
	int st_ps = abs(p);
	string dd;
	int n = s.length();
	for (int i = 0; i < w.length(); ++i) {
		if (st_ps == n) {
			dd.push_back(w[i]);
			st_ps = 0;
		}
		else {
			if (w[i] != s[st_ps])return;
			++st_ps;
		}
	}
	if (dd.empty()) {
		ans = (ans + pw[max_lvl] + mod) % mod;
		return;
	}
	m_rec(dd, 1);
}
void solve() {
	int n, q;
	cin >> n >> q;
	pw.assign(n + 1, 1);
	for (int i = 1; i <= n; ++i)pw[i] = pw[i - 1] * 2 % mod;
	dp.assign(26, 0);
	cin >> s;
	cin >> t;
	vector<ll>aa(q);
	vector<vector<pair<string, int>>>qw(n + 1);
	for (int i = 0; i < q; ++i) {
		int m;
		string dd;
		cin >> m >> dd;
		qw[m].push_back({ dd,i });
	}
	int ln = s.length();
	for (int i = 0; i <= n; ++i) {
		max_lvl = i;
		for (auto& x : dp)x = (x * 2) % mod;
		if(i!=0){
		dp[t[i - 1] - 'a']++;
		dp[t[i - 1] - 'a'] %= mod;}
		for (auto p : qw[i]) {
			string w = p.first;
			int j = p.second;
			ans = 0;
			for (int i = -ln; i < 1; ++i)
				my_del(w, i);
			aa[j] = ans;
		}
	}
	for (int i = 0; i < q; ++i)cout << aa[i] << "\n";
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}