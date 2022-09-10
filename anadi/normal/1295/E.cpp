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
int p[N];

LL w[N];
LL add[N];
LL tree[N];

void update(int from, int to, LL val, int s = 1, int e = T, int cur = 1){
	if(from <= s && e <= to){
		add[cur] += val;
		tree[cur] += val;
		return;
	}
	
	int mid = (s + e) >> 1;
	if(from <= mid)
		update(from, to, val, s, mid, cur + cur);
	if(mid < to)
		update(from, to, val, mid + 1, e, cur + cur + 1);
	
	tree[cur] = min(tree[cur + cur], tree[cur + cur + 1]) + add[cur];
//	printf("query %d %d -> %lld\n", from, to, val);
//	printf("%d %d :: %d -> %lld %lld\n", s, e, cur, tree[cur], add[cur]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);

	for(int i = 1; i <= n; ++i)
		scanf("%lld", &w[i]);
	
	LL ans = min(w[1], w[n]);
	for(int i = 1; i <= n; ++i)
		update(p[i], n, w[i]);
	update(n + 1, T, INF);
	
	for(int i = 1; i < n; ++i){
		update(p[i], n, -w[i]);
		if(1 < p[i])
			update(1, p[i] - 1, w[i]);
		ans = min(ans, tree[1]);
	}
	
	printf("%lld\n", ans);
	return 0;
}