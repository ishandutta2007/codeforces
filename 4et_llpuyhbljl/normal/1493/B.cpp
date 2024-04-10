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
vector<char>gd = { '0','1','2','5','8' };
bool is_it_good(int tm, int h, int m) {
	string ans;
	while (tm) {
		ans.push_back(tm % 10 + '0');
		tm /= 10;
	}
	while (ans.size() < 4)ans.push_back('0');
	string aa;
	for (auto x : ans) {
		bool f = 0;
		for (auto y : gd) {
			f |= x == y;
		}
		if (!f) {
			return false;
		}
		if (x == '5') {
			aa.push_back('2');
		}
		else {
			if (x == '2') {
				aa.push_back('5');
			}
			else {
				aa.push_back(x);
			}
		}
	}
	//reverse(aa.begin(), aa.end());
	int h1 = (aa[0] - '0') * 10 + aa[1] - '0';
	int m1 = (aa[2] - '0') * 10 + aa[3] - '0';
	if (h1 >= h || m1 >= m)return false;
	return true;
}
void solve() {
	int h, m;
	cin >> h >> m;
	string s;
	cin >> s;
	int tm = 0;
	for (auto x : s) {
		if (x == ':')continue;
		tm = tm * 10 + x - '0';
	}
	while (!is_it_good(tm, h, m)) {
		tm = (tm + 1);
		if (tm == h * 100)tm = 0;
		else {
			if (tm % 100 == m) {
				tm /= 100;
				++tm;
				tm *= 100;
			}
			if (tm == h * 100)tm = 0;
		}
	}
	string ans;
	while (tm) {
		ans.push_back(tm % 10 + '0');
		tm /= 10;
	}
	while (ans.size() < 4)ans.push_back('0');
	reverse(ans.begin(), ans.end());
	cout << ans[0] << ans[1] << ":" << ans[2] << ans[3] << "\n";
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