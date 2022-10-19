#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
ll b[MAXN];
vector <int> adj[MAXN];
vector <pii> gps[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", b + i);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

inline ll gcd(ll x, ll y) {
	return x ? __gcd(x, y) : y;
}

int dfs(int x, int p) {
	vector <pii> tmp = gps[p];
	tmp.push_back({b[x], 1});
	ll last = -1;
	int cnt = 0;
	for (auto &it : tmp) {
		it.first = gcd(it.first, b[x]);
		if (it.first != last) {
			if (last != -1)
				gps[x].push_back({last, cnt});
			last = it.first;
			cnt = 0;
		}
		cnt += it.second;
	}
	gps[x].push_back({last, cnt});
	
	int res = 0;
	for (auto it : gps[x])
		res = add(res, mul(it.first % MOD, it.second));
		
	for (auto it : adj[x])
		if (it != p)
			res = add(res, dfs(it, x));
			
	return res;
}

int main() {
	load();
	printf("%d\n", dfs(1, 0));
	return 0;
}