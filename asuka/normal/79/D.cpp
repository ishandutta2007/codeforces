#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, k, l, p[10015], x[25], a[105], dis[25][10015], dp[1 << 20];
queue<int> q;
void bfs(int s) {
	memset(dis[s], 0x3f, sizeof dis[s]);
	dis[s][x[s]] = 0;
	q.push(x[s]);
	while(SZ(q)) {
		int u = q.front();
		q.pop();
		rep(i, 1, l) rep(r, -1, 1) {
			if(r == 0) continue;
			int v = u + a[i] * r;
			if(v < 1 || v > n + 1) continue;
			if(dis[s][v] > dis[s][u] + 1) {
				dis[s][v] = dis[s][u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &k, &l);
	VI vec;
	rep(i, 1, k) {
		scanf("%d", &x[i]);
		p[x[i]] = 1;
	}
	rep(i, 1, l) scanf("%d", &a[i]);
	k = 0;
	rep(i, 1, n + 1) if(p[i] != p[i - 1]) x[++k] = i;
	rep(i, 1, k) bfs(i);
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	rep(mask, 1, (1 << k) - 1) {
		if(__builtin_popcount(mask) == 1) continue;
		int o = -1;
		rep(i, 1, k) {
			if(mask >> (i - 1) & 1) {
				if(o == -1) o = i;
				else {
					dp[mask] = min(dp[mask], dp[mask ^ (1 << (i - 1)) ^ (1 << (o - 1))] + dis[i][x[o]]);
				}
			}
		}
	}
	printf("%d\n", dp[(1 << k) - 1] == inf ? -1 : dp[(1 << k) - 1]);
	return 0;
}