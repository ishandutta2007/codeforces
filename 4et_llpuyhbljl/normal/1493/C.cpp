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
const int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 200010, maxT = 10010, A = 179;
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
void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (k == 1) {
		cout << s << "\n";
		return;
	}
	if (s.length() % k != 0) {
		cout << "-1\n";
		return;
	}
	int need = n / k;
	int now = 0;
	string ans;
	map<char, int>mp;
	for (int i = 0; i < n; ++i) {
		char x = s[i];
		ans.push_back(s[i]);
		++mp[x];
		if (mp[x] % k == 1) {
			++now;
			if (now > need) {
				char lst;
				bool f = 0;
				while (need <= now && f == 0) {
					if (--mp[ans.back()] % k == 0)--now;
					lst = ans.back();
					ans.pop_back();
					if (now < need)break;
					for (auto &x : mp) {
						if (x.second % k != 0 && x.first > lst) {
							f = 1;
							ans.push_back(x.first);
							++mp[x.first];
							break;
						}
					}
				}
				while (lst == 'z') {
					if (--mp[ans.back()] % k == 0)--now;
					lst = ans.back();
					ans.pop_back();
				}
				if (f == 0) {
					ans.push_back(lst + 1);
					if (++mp[lst + 1] % k == 1)++now;
				}
				while (ans.size() < n) {
					if (now < need) {
						ans.push_back('a');
						if (++mp['a'] % k == 1)++now;
					}
					else {
						for (auto &x : mp) {
							if (x.second % k != 0) {
								ans.push_back(x.first);
								++x.second;
								break;
							}
						}
					}
				}
				break;
			}
		}
	}

	cout << ans << "\n";
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
/*
abbbbbbd
3
1 2
7 8
2 7
*/