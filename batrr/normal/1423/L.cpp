#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = 1123, mod = (int)1e9 + 7, inf = (int)1e9, bl = 63, K = 18, M = (1 << 18) * 18;
const ll INF = (ll)1e18;

int n, s, m, bn, d, na, ans[M], sz[(1 << K)];
ll c[40][32 * N], b[N], cur[N], a[30][N];
unordered_map <ll, int> bor[M];

void dfs(int mask, int i) {
	if(i == m){
		int x = 0;
		for(int j = 0; j < na; ++j){
			if(!bor[x].count(cur[j])){
				bor[x][cur[j]] = ++bn;
				ans[bn] = inf;
			}
			x = bor[x][cur[j]];
		}
		ans[x] = min(ans[x], sz[mask]);
		return;
	}
	dfs(mask, i + 1);
	for(int j = 0; j < na; ++j)
		cur[j] ^= a[i][j];
	dfs((mask ^ (1 << i)), i + 1);
	for(int j = 0; j < na; ++j)
		cur[j] ^= a[i][j];
}

int main(){
	scanf("%d%d%d", &n, &s, &d);
	for(int i = 0, x, y; i < s; ++i){
		scanf("%d", &x);
		for(int j = 0; j < x; ++j){
			scanf("%d", &y);
			y--;
			a[i][y / bl] ^= (1LL << (y % bl));
		}
	}
	na = (n - 1) / bl + 1;

	m = min(s, K);
	for(int i = 1; i < (1 << m); ++i)
	for(int j = 0; j < m; ++j)
		if(((i >> j) & 1))
			sz[i] = 1 + sz[(i ^ (1 << j))];
	dfs(0, 0);
	for(int mask = 0; mask < (1 << (s - m)); ++mask){
		for(int i = 0; i < s - m; ++i){
			if(!((mask >> i) & 1))
				continue;
			for(int j = 0; j < na; ++j)
				c[j][mask] ^= a[i + m][j];
		}
	}

	while(d--){
		memset(b, 0, sizeof b);
		{
			int x;
			scanf("%d", &x);
			for(int i = 0; i < x; ++i){
				int y;
				scanf("%d", &y);
				y--;
				b[y / bl] ^= (1LL << (y % bl));
			}        
		}
		int Ans = 50;
		for(int mask = 0; mask < (1 << (s - m)); ++mask){
			int x = 0;
			for(int i = 0; i < na; ++i){
				if(!bor[x].count(c[i][mask] ^ b[i])){
					x = 0;
					break;
				}                                                      	
				x = bor[x][(c[i][mask] ^ b[i])];
			}
			if(x != 0)
				Ans = min(Ans, sz[mask] + ans[x]); 
		}
		if(Ans == 50)
			Ans = -1;
		printf("%d\n", Ans);
	}

	return 0;
}