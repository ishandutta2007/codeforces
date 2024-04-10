#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;

int n, m, q;
ll add[510], a[510][510], dp[510][510], gox[510][510], goy[510][510];
vector< pii > vx[510][510], vy[510][510];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < q; i++){
		int x, y, t, d, e;
		scanf("%d%d%d%d%d", &x, &y, &d, &t, &e);
		if(x + y >= t && (x + y - t) % 4 == 0){
			a[x][y] += e;
			if(x + y + d >= t && (x + y + d - t) % 4 == 2)
				vx[x][y].pb({x + d, e});
			else
				vx[x][y].pb({n, e});
			if(x + y + d >= t && (x + y + d - t) % 4 == 3)
				vy[x][y].pb({y + d, e});
			else
				vy[x][y].pb({m, e});
		}
        if(x + y >= t && (x + y - t) % 4 == 1){
			a[x + d][y - d] += e;
			vx[x + d][y - d].pb({n, e});
			if(x + y + d >= t && (x + y + d - t) % 4 == 2)
				vy[x + d][y - d].pb({y, e});
			else
				vy[x + d][y - d].pb({m, e});
		}                    
		if(x + y + d >= t && (x + y + d - t) % 4 == 2){
			a[x + d][y] += e;
			vx[x + d][y].pb({n, e});
			vy[x + d][y].pb({m, e});
		}
		if(x + y + d >= t && (x + y + d - t) % 4 == 3){
			a[x][y + d] += e;
			vx[x][y + d].pb({n, e});
			vy[x][y + d].pb({m, e});
		}
	}
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			dp[x][y] = INF;
			{
				ll cur = 0;
				for(auto it : vx[x][y]){
					cur += it.s;
					add[it.f] += it.s;	
				}
				for(int k = x; k <= n; k++){
					cur -= add[k];
					gox[y][k] += cur;
					add[k] = 0;
				}
			}
			{
				ll cur = 0;
				for(auto it : vy[x][y]){
					cur += it.s;
					add[it.f] += it.s;	
				}
				for(int k = y; k <= m; k++){
					cur -= add[k];
					goy[k][x] += cur;
					add[k] = 0;
				}
			}	
		}
	}
	dp[0][0] = a[0][0];
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			dp[x][y] -= a[x][y];
			for(int k = x + 1; k < n; k++)
				dp[k][y] = min(dp[k][y], dp[x][y] + gox[y][k]);
			for(int k = y + 1; k < m; k++)
				dp[x][k] = min(dp[x][k], dp[x][y] + goy[k][x]);
			{
				ll cur = 0;
				for(auto it : vx[x][y]){
					cur += it.s;
					add[it.f] += it.s;	
				}
				for(int k = x; k <= n; k++){
					cur -= add[k];
					gox[y][k] -= cur;
					add[k] = 0;
				}
			}
			{
				ll cur = 0;
				for(auto it : vy[x][y]){
					cur += it.s;
					add[it.f] += it.s;	
				}
				for(int k = y; k <= m; k++){
					cur -= add[k];
					goy[k][x] -= cur;
					add[k] = 0;
				}
			}	
		}
	}
	printf("%lld", dp[n - 1][m - 1]);
	return 0;
}