/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-12-07 11:25:13
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// source : KACTL
#pragma once

bool Q = 1;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return Q ? k < o.k : p < o.p; }
};

struct CHT : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 0 ; auto l = *lower_bound({0 , 0 , x}); Q = 1;
		return l.k * x + l.m;
	}
};

ll n , A[MAXN] , B[MAXN] , dp[MAXN];
vector<int> adj[MAXN];
CHT cht[MAXN];

void DFS(int v , int p = -1){
	int leaf = 1;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
		if(SZ(cht[u]) > SZ(cht[v])){
			cht[v].swap(cht[u]);
		}
		for(auto &i : cht[u]){
			cht[v].add(i.k , i.m);
		}
		leaf = 0;
	}
	if(leaf){
		dp[v] = 0;
	}
	else{
		dp[v] = -cht[v].query(A[v]);
	}
	cht[v].add(-B[v] , -dp[v]);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> B[i];
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for(int i = 1 ; i <= n ; i++){
		cout << dp[i] << sep;
	}

    return 0;
}
/*

*/