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
vector<int>prefix_function(string s) {
	int n = s.length();
	vector<int>pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])++j;
		pi[i] = j;
	}
	return pi;
}
void solve() {
	string s;
	cin >> s;
	map<char, int>mp;
	int mx = 0;
	for (auto x : s)
		mx = max(mx, ++mp[x]);
	sort(s.begin(), s.end());
	char mn = s[0];
	for (auto x : mp) {
		if (x.second == 1) {
			string ans;
			ans.push_back(x.first);
			for (auto y : mp) {
				if (y.first == x.first)
					continue;
				for (int j = 0; j < y.second; ++j)
					ans.push_back(y.first);
			}
			cout << ans << "\n";
			return;
		}
	}
	if (mp[mn] <= 2 || mx == 1 || mp.size() == 1) {
		cout << s << "\n";
		return;
	}
	string ans;
	multiset<char>stt;
	for (auto x : mp) {
		if (x.first == mn)
			continue;
		for (int j = 0; j < x.second; ++j) {
			stt.insert(x.first);
		}
	}
	if (mp[mn] * 2 <= s.length() + 2) {
		for (int j = 0; j < 2; ++j) {
			if (mp[mn]) {
				ans.push_back(mn);
				--mp[mn];
			}
		}
		for (auto x : stt) {
			ans.push_back(x);
			if (mp[mn]) {
				ans.push_back(mn);
				--mp[mn];
			}
		}
	}
	else {
		if (mp.size() == 2) {
			ans.push_back(mn);
			--mp[mn];
			for (auto x : stt)ans.push_back(x);
			while (mp[mn]) {
				ans.push_back(mn);
				--mp[mn];
			}
		}
		else {
			ans.push_back(mn);
			--mp[mn];
			ans.push_back(*stt.begin());
			stt.erase(stt.begin());
			while (mp[mn]) {
				ans.push_back(mn);
				--mp[mn];
			}
			if (!stt.empty()) {
				auto it = stt.upper_bound(ans[1]);
				ans.push_back(*it);
				stt.erase(it);
				for (auto x : stt) {
					ans.push_back(x);
				}
			}
		}
	}
	cout << ans << "\n";
	vector<int> p = prefix_function(ans);
	mx = 0;
	for (auto x : p)
		mx = max(mx, x);
	if (mx > 1) {
		exit(1234);
	}
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