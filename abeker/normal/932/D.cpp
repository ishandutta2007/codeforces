#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 5;
const int LOG = 20;

int Q;
int cost[MAXN];
int depth[MAXN];
ll sum[MAXN];
int anc[MAXN][LOG];
int up[MAXN];
int curr = 1;
int mx[MAXN][LOG];
int dad[MAXN][LOG]; // original tree

void add_node(int x, int w) {
	curr++;
	
	dad[curr][0] = x;
	for (int i = 1; i < LOG; i++)
		dad[curr][i] = dad[dad[curr][i - 1]][i - 1];
	
	mx[curr][0] = w;
	for (int i = 1; i < LOG; i++)
		mx[curr][i] = max(mx[curr][i - 1], mx[dad[curr][i - 1]][i - 1]);
		
	for (int i = LOG - 1; i >= 0; i--)
		if (mx[x][i] < w)
			x = dad[x][i];
		
	cost[curr] = w;
	depth[curr] = depth[x] + 1;
	sum[curr] = sum[x] + w;
	
	anc[curr][0] = x;
	for (int i = 1; i < LOG; i++)
		anc[curr][i] = anc[anc[curr][i - 1]][i - 1];
	
	if (cost[curr] > cost[x])
		up[curr] = depth[curr];
	else
		up[curr] = up[x];
}

int query(int x, ll w) {
	if (cost[x] > w)
		return 0;
		
	int st = x;
	ll limit = sum[x] - w;
	for (int i = LOG - 1; i >= 0; i--)
		if (sum[anc[x][i]] - cost[anc[x][i]] >= limit)
			x = anc[x][i];
	
	return depth[st] - max(depth[x], up[st]) + 1;
}

int main() {
	scanf("%d", &Q);
	ll last = 0;
	while (Q--) {
		int cmd;
		ll p, q;
		scanf("%d%lld%lld", &cmd, &p, &q);
		int r = p ^ last;
		ll w = q ^ last;
		//printf("%d %d %d\n", cmd, r, w);
		if (cmd == 1)
			add_node(r, w);
		else {
			last = query(r, w);
			printf("%lld\n", last);
		}
	}
	
	return 0;
}