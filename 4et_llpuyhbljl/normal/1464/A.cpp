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
const long long INF = 2e9;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 20100, maxT = 100010;
vector<vector<int>>G;
vector<int>used;
bool dfs(int v, int& ct) {
	++ct;
	used[v] = 1;
	bool ans = false;
	for (auto x : G[v]) {
		if (used[x]) {
			if (used[x] == 1)ans = true;
			continue;
		}
		ans |= dfs(x, ct);
	}
	used[v] = 2;
	return ans;
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
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>>v(m);
		G.assign(n, vector<int>(0));
		vector<int>li(n);
		for (auto& x : v) {
			cin >> x.first >> x.second;
			--x.first;
			--x.second;
			if (x.first == x.second)continue;
			G[x.first].push_back(x.second);
			++li[x.second];
		}
		used.assign(n, 0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i] || G[i].empty() || li[i])continue;
			int ct = -1;
			if (dfs(i, ct))ans += 2;
			ans += ct;
		}
		for (int i = 0; i < n; ++i) {
			if (used[i] || G[i].empty())continue;
			int ct = -1;
			if (dfs(i, ct))ans += 2;
			ans += ct;
		}
		cout << ans << '\n';
	}
    return 0;
}