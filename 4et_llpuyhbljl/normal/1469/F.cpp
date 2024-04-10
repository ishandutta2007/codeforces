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
const int maxN = 500100, maxT = 100010;
void ans(ll res) {
	cout << res << "\n";
	exit(0);
}
void solve() {
	ll n, k;
	ll sum = 1;
	cin >> n >> k;
	vector<ll>l(n);
	for (auto& x : l) {
		cin >> x;
		sum += x;
	}
	sort(l.begin(), l.end());
	reverse(l.begin(), l.end());
	int y = 0;
	if (sum - 2 * n < k) ans(-1);
	vector<int>now(maxN), start(maxN), stop(maxN);
	start[0] = stop[1] = now[0] = sum = 1;
	for (int i = 1; i < maxN; ++i) {
		now[i] = now[i - 1];
		now[i] += start[i] - stop[i];
		sum += now[i];
		if (sum >= k)ans(i);
		for (int j = 0; j < now[i - 1] && y != l.size(); ++j, ++y) {
			--sum;
			int fl = (l[y] - 1) / 2;
			int sl = (l[y] - 1 - fl);
			start[i + 1] += 2;
			++stop[i + 1 + fl];
			++stop[i + 1 + sl];
		}
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}