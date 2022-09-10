#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int ans[N];

LL in[N];
LL sub[T + T + 7];
LL tree[T + T + 7];

void propagate(int u){
	if(sub[u] == 0)
		return;
	
	sub[u + u] += sub[u];
	tree[u + u] += sub[u];
	
	sub[u + u + 1] += sub[u];
	tree[u + u + 1] += sub[u];
	sub[u] = 0;
}

int get(int u){
	while(u < T){
		propagate(u);
		u *= 2;

		if(tree[u + 1] == 0)
			++u;
	}
	
	return u - T;
}

void update(int from, int to, LL val, int s = 0, int e = T - 1, int cur = 1){
	if(from <= s && e <= to){
		sub[cur] += val;
		tree[cur] += val;
		return;
	}
	
	propagate(cur);
	int mid = (s + e) / 2;
	if(from <= mid)
		update(from, to, val, s, mid, cur + cur);
	if(mid < to)
		update(from, to, val, mid + 1, e, cur + cur + 1);
	tree[cur] = min(tree[cur + cur], tree[cur + cur + 1]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < T + T; ++i)
		tree[i] = INF;

	for(int i = 1; i <= n; ++i){
		scanf("%lld", &in[i]);
		tree[T + i] = in[i];
	}
		
	for(int i = T - 1; i >= 1; --i)
		tree[i] = min(tree[i + i], tree[i + i + 1]);
	
	for(int i = 1; i <= n; ++i){
		int p = get(1);
		ans[p] = i;

		update(p, p, INF);
		if(p < n)
			update(p + 1, n, -i);
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}