#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 55;
const int T = 1 << 15;
const int M = 20 * 1000 + 7;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k;
int tree[T + T], add[T + T];

int dp[N][M];
int pref[N][M];

int get(int d, int s){
	return pref[d][s + k - 1] - pref[d][s - 1];
}

void update(int cur, int s, int e, int v, int from = 1, int to = T){
	if(s <= from && to <= e){
		add[cur] += v;
		tree[cur] += v;
		return;
	}
	
	int mid = (from + to) / 2;
	if(s <= mid)
		update(cur + cur, s, e, v, from, mid);
	if(mid < e)
		update(cur + cur + 1, s, e, v, mid + 1, to);
	tree[cur] = max(tree[cur + cur], tree[cur + cur + 1]) + add[cur];
}

void upd(int p, int v){
	int s = max(p - k + 1, 1);
	int e = min(p, m - k + 1);
	update(1, s, e, v);
}

void write(int u){
	printf("tree[%d] = %d, add[%d] = %d\n", u, tree[u], u, add[u]);
	if(u < T){
		write(u + u);
		write(u + u + 1);
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%d", &pref[i][j]);
			pref[i][j] += pref[i][j - 1];
		}
	
	for(int i = 1; i <= m - k + 1; ++i){
		dp[1][i] = get(1, i) + get(2, i);
//		printf("dp[%d][%d] = %d\n", 1, i, dp[1][i]);
	}

	for(int i = 2; i <= n; ++i){
		for(int j = 1; j < T + T; ++j)
			tree[j] = add[j] = 0;
		
		for(int j = 1; j <= m - k + 1; ++j){
			int val = dp[i - 1][j];
			if(j <= k)
				val -= pref[i][k] - pref[i][j - 1];
			
//			printf("ini %d %d -> %d\n", i, j, val);
			update(1, j, j, val);
		}
		
		for(int j = 1; j <= m - k + 1; ++j){
			dp[i][j] = tree[1] + get(i, j) + get(i + 1, j);
			upd(j, (pref[i][j] - pref[i][j - 1]));
			upd(j + k, -(pref[i][j + k] - pref[i][j + k - 1]));
			
//			write(1);
//			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= m - k + 1; ++i)
		ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}