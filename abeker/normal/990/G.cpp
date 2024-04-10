#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN], v[MAXN];
int dad[MAXN], rnk[MAXN], sz[MAXN];
bool bio[MAXN];
ll dp[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		v[num].push_back(i);
	}
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

ll join(int x, int y) {
	x = find(x);
	y = find(y);
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	ll res = (ll)sz[x] * sz[y];
	sz[y] += sz[x];
	return res;
}

void solve() {
	for (int i = MAXN - 1; i; i--) {
		vector <int> curr;
		for (int j = i; j < MAXN; j += i)
			for (auto it : v[j])
				curr.push_back(it);
		
		for (auto it : curr) {
			dad[it] = it;
			rnk[it] = 0;
			sz[it] = 1;
		}
		
		dp[i] = curr.size();
		for (auto it : curr) {
			bio[it] = true;
			for (auto nxt : adj[it])
				if (bio[nxt])
					dp[i] += join(it, nxt);
		}
		
		for (int j = 2 * i; j < MAXN; j += i)
			dp[i] -= dp[j];
			
		for (auto it : curr)
			bio[it] = false;
	}
	
	for (int i = 1; i < MAXN; i++)
		if (dp[i])
			printf("%d %lld\n", i, dp[i]);
}

int main() {
	load();
	solve();
	return 0;
}