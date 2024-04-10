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
const int maxN = 500100, maxT = 1601;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>>G(n), GG(n), cost(2, vector<ll>(n, INF));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].push_back(b);
		GG[b].push_back(a);
	}
	cost[0][0] = 0;
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		int b = q.front();
		q.pop();
		for (auto x : G[b]) {
			if (cost[0][x] == INF) {
				cost[0][x] = cost[0][b] + 1;
				q.push(x);
			}
		}
	}
	priority_queue<pair<ll, int>>qq;
	vector<int>used(n);
	for (int i = 0; i < n; ++i) {
		cost[1][i] = cost[0][i];
		qq.push({ -cost[0][i],i });
	}
	while (!qq.empty()) {
		int b = qq.top().second;
		qq.pop();
		if (used[b])continue;
		used[b] = 1;
		for (auto x : GG[b]) {
			ll np = INF;
			if (cost[0][b] <= cost[0][x]) {
				np = cost[0][b];
			}
			else {
				np = cost[1][b];
			}
			if (np < cost[1][x]) {
				cost[1][x] = np;
				qq.push({ -np,x });
			}
		}
	}
	for (auto x : cost[1])cout << x << " "; cout << "\n";
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