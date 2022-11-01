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
long long gcd(long long i, long long j) {
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
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 20100, maxT = 100010;
void solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (auto& x : s) {
		if (x == '0')x = '1';
		else x = '0';
	}
	vector<int>used(n + 100);
	ull msk = 0;
	ull tmp = 0;
	for (int i = 0; i < min(k, 25LL); ++i) {
		tmp |= (1 << i);
	}
	int mx = 0;
	for (int i = 0; i < k - 1; ++i) {
		msk <<= 1;
		if (s[i] == '1') {
			msk |= 1;
		}
	}
	for (int i = k - 1; i < n; ++i) {
		msk <<= 1;
		if (s[i] == '1')msk |= 1;
		msk &= tmp;
		while (mx<=i &&(i - mx >= k || s[mx] == '0')) {
			++mx;
		}
		if (i - mx > 25 || msk >= used.size())continue;
		used[msk] = 1;
	}


	ll ans = -1;
	for (int i = 0; i < n + 100; ++i) {
		if (used[i] || i > tmp)continue;
		ans = i;
		break;
	}
	if (ans == -1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	string ss;
	for (int i = 0; i < k; ++i) {
		ss.push_back('0');
	}
	for (int i = 0; i < 25; ++i) {
		if ((ans & (1 << i)) != 0) {
			ss[k - i - 1] = '1';
		}
	}
	cout << ss << '\n';
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