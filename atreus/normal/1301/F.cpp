#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 50;
const int inf = 2e9;

int adjx[] = {0, -1, 0, +1};
int adjy[] = {+1, 0, -1, 0};
vector<pair<int,bool>> g[maxn];
int r1[maxn], r2[maxn], c1[maxn], c2[maxn];
int ans[maxn], col[maxn];
int h[maxn];
int deq[2*maxn];
bool mark[50];
int last[50], pre[maxn];
int n, m, k;

int adj(int v, int z){
	if (z == 0){
		if (v % m == 1)
			return -1;
		return v - 1;
	}
	if (z == 1){
		if (v % m == 0)
			return -1;
		return v + 1;
	}
	if (z == 2){
		if (v - m < 1)
			return -1;
		return v - m;
	}
	if (v + m > n*m)
		return -1;
	return v + m;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int x;
			scanf("%d", &x);
			int v = (i-1)*m+j;
			col[v] = x;
			pre[v] = last[x];
			last[x] = v;
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		scanf("%d%d%d%d", &r1[i], &c1[i], &r2[i], &c2[i]);
		ans[i] = abs(r1[i] - r2[i]) + abs(c1[i] - c2[i]);
	}
	for (int i = 1; i <= k; i++){
		int head = maxn, tail = maxn;
		memset(h, -1, sizeof h);
		h[n*m+i] = 0;
		deq[head ++] = n*m+i;
		while (tail < head){
			int v = deq[tail ++];
			if (v <= n*m){
				for (int z = 0; z < 4; z++){
					int u = adj(v, z);
					if (u == -1)
						continue;
					if (h[u] == -1 or h[u] > h[v] + 1){
						h[u] = h[v] + 1;
						deq[head ++] = u;
					}
				}
				int x = col[v];
				int u = n*m+x;
				if (h[u] == -1 or h[u] > h[v] + 1){
					h[u] = h[v] + 1;
					deq[head ++] = u;
				}
			}
			else{
				int u = last[v - n*m];
				while (u != 0){
					if (h[u] == -1 or h[u] > h[v]){
						h[u] = h[v];
						deq[-- tail] = u;
					}
					u = pre[u];
				}
			}
		}
		for (int j = 1; j <= q; j++)
			ans[j] = min(ans[j], 1 + h[(r1[j]-1)*m+c1[j]] + h[(r2[j]-1)*m+c2[j]]);
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
}