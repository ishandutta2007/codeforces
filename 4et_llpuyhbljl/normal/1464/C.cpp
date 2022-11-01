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
ll d(char b) {
	return (1LL << (b - 'a'));
}
void solve() {
	ll n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	t += d(s[n - 2]) - d(s.back());
	t = abs(t);
	int sz = 70;
	vector<ll>dig(sz);
	for (int i = 0; i < n - 2; ++i) {
		++dig[s[i] - 'a'];
		t -= d(s[i]);
	}
	bool ans = t <= 0 && t % 2 == 0;
	t = abs(t/2);
	for (int i = 26; i >= 0; --i) {
		while (dig[i] && t >= (1<<i)) {
			t -= 1 << i;
			--dig[i];
		}
	}
	ans &= t==0;
	if (ans)cout << "Yes\n";
	else cout << "No\n";
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