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
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (i < j)swap(i, j);
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
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>>G(n);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a;
		--b;
		G[a].push_back({ b,w });
		G[b].push_back({ a,w });
	}
	vector<ll>cost(4 * n, INF);
	cost[0] = 0;
	priority_queue<pair<ll, int>>q;
	q.push({ 0,0 });
	vector<int>used(4 * n);
	while (!q.empty()) {
		int b = q.top().second;
		q.pop();
		int cd = b / n;
		if (used[b])continue;
		used[b] = 1;
		for (auto x : G[b % n]) {
			for (int j = 0; j < 4; ++j) {
				if ((cd & j) != cd)continue;
				int tmp = j ^ cd;
				ll cs = cost[b] + x.second;
				if ((tmp & 1) == 1)cs -= x.second;
				if ((tmp & 2) == 2)cs += x.second;
				if (cs < cost[j * n + x.first]) {
					cost[j * n + x.first] = cs;
					q.push({ -cost[j * n + x.first],j * n + x.first });
				}
			}
		}
	}
	for (int i = 1; i < n; ++i)cout << cost[3 * n + i] << " ";
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