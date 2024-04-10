#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int treeSize = 1 << 19;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int tab[N];
int mn[2 * N];
int sum[2 * N];
PII tree[2 * N];
bool vis[2 * N];

LL res = 0LL;
priority_queue <PII> Q;

PII findMin(int cur, int p, int k, int a, int b){
	if(p <= a && b <= k)
		return tree[cur];
	
	int m = (a + b) / 2;
	if(k <= m)
		return findMin(2 * cur, p, k, a, m);
	if(m < p)
		return findMin(2 * cur + 1, p, k, m + 1, b);
	return min(findMin(2 * cur, p, k, a, m), findMin(2 * cur + 1, p, k, m + 1, b));
}

void change(int a){
	a += treeSize - 1;
	tree[a].st = INF;
	
	while(a > 1){
		a /= 2;
		tree[a] = min(tree[a + a], tree[a + a + 1]);
	}
}

int findZero(int cur, int x, int a, int b, int up){
	up += sum[cur];
	if(x <= a && mn[cur] + up < 0)
		return n + 1;

	if(a == b)
		return a;
	
	int m = (a + b) / 2;
	if(x <= a){
		if(mn[cur + cur] + sum[cur + cur] + up == 0)
			return findZero(cur + cur, x, a, m, up);
		return findZero(cur + cur + 1, x, m + 1, b, up);
	}
	
	int ret = findZero(cur + cur + 1, x, m + 1, b, up);
	if(x <= m)
		ret = min(ret, findZero(cur + cur, x, a, m, up));
	return ret;
}

void add(int cur, int p, int k, int val, int a, int b){
	if(p <= a && b <= k){
		sum[cur] += val;
		return;
	}

	int m = (a + b) / 2;
	if(p <= m)
		add(cur + cur, p, k, val, a, m);
	if(m < k)
		add(cur + cur + 1, p, k, val, m + 1, b);
	
	mn[cur] = max(mn[cur + cur] + sum[cur + cur], mn[cur + cur + 1] + sum[cur + cur + 1]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		Q.push({tab[i], i});
	}
	
	for(int i = 1; i <= n; ++i)
		tree[treeSize + i - 1] = {tab[i], i};
	
	for(int i = treeSize - 1; i >= 1; --i)
		tree[i] = min(tree[i + i], tree[i + i + 1]);
	
	while(!Q.empty()){
		int cur = Q.top().nd;
		Q.pop();

		if(vis[cur])
			continue;
		vis[cur] = true;

		change(cur);
		int to = min(findZero(1, cur, 1, treeSize, 0), n + 1);
		
		if(to == 1)
			continue;
		
		int place = findMin(1, 1, to - 1, 1, treeSize).nd;
		if(vis[place])
			continue;
		
		vis[place] = true;
		res += tab[cur] - tab[place];
		
		change(place);
		add(1, cur, n, 1, 1, treeSize);
		add(1, place, n, -1, 1, treeSize);
	}
	
	printf("%lld\n", res);
	return 0;
}