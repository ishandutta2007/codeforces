#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int n, s, a[N], cost[N][N], dir[N][N], pau[N][N], dp[2][N], from[2][N], vis[N]; // 0: start, 1: end
VI vec, pos[N], res;
int dis(int x, int y){ // x -> y or <- x  y <-
	if(x < y) swap(x, y);
	return min(x - y, n - (x - y));
}
int dist(int x, int y){ // x -> y
	if(x <= y) return y - x;
	else return n - (x - y);
}
int tsid(int x, int y){ // <- x  y <-
	if(x < y) return n - (y - x);
	else return x - y;
}
void solve(VI cyc) {
	int sz = SZ(cyc);
	rep(st, 0, sz - 1) rep(ed, 0, sz - 1) {
		if(st == ed) {
			if(sz == 1){
				cost[cyc[st]][cyc[ed]] = 0;
				dir[cyc[st]][cyc[ed]] = 1;
				pau[cyc[st]][cyc[ed]] = cyc[st];
			}
			continue;
		}
		rep(p, -1, 1) {
			if(p == 0) continue;
			int stop = (ed + p + sz) % sz;
			if(p == -1){
				// printf("zhe: %d -> %d -> %d\n",cyc[st], cyc[stop], cyc[ed]);
				if(cost[cyc[st]][cyc[ed]] > dist(cyc[st], cyc[stop]) + tsid(cyc[stop], cyc[ed])) {
					cost[cyc[st]][cyc[ed]] = dist(cyc[st], cyc[stop]) + tsid(cyc[stop], cyc[ed]);
					dir[cyc[st]][cyc[ed]] = 1;
					pau[cyc[st]][cyc[ed]] = cyc[stop];
				}
			}
			if(p == 1) {
				// printf("rev: %d -> %d -> %d\n", cyc[st], cyc[stop], cyc[ed]);
				// printf("%d %d\n", tsid(cyc[st], cyc[stop]), dist(cyc[stop], cyc[ed]));
				if(cost[cyc[st]][cyc[ed]] > tsid(cyc[st], cyc[stop]) + dist(cyc[stop], cyc[ed])) {
					cost[cyc[st]][cyc[ed]] = tsid(cyc[st], cyc[stop]) + dist(cyc[stop], cyc[ed]);
					dir[cyc[st]][cyc[ed]] = -1;
					pau[cyc[st]][cyc[ed]] = cyc[stop];
				}
			}
		}
	}
}
void go(int x, int y){// x - > y
	if(x < y) {
		int d = y - x;
		if(d < n - d) {
			printf("+%d\n",d);
		} else {
			printf("-%d\n", n - d);
		}
	} else {
		int d = x - y;
		if(d < n - d) {
			printf("-%d\n", d);
		} else {
			printf("+%d\n", n - d);
		}
	}
}
void output(int x) {
	if(!x) return;
	int fx = from[1][x];
	int y = from[0][fx];
	// printf("output(%d) -> %d --%d--> %d \n", y, fx, pau[fx][x], x);
	// printf("%d\n", dir[fx][x]);
	output(y);
	if(y == 0) y = s;
	int stop = pau[fx][x];
	// y -> fx - > stop -> x
	if(dir[fx][x] == 1) {
		for(int i = fx; i != stop; i = (i == n ? 1 : (i + 1))) {
			if(vis[i]) continue;
			if(a[i] == a[x]) {
				res.pb(i);
				vis[i] = 1;
			}
		}
		for(int i = stop; i != x; i = (i == 1 ? n : (i - 1))) {
			if(vis[i]) continue;
			if(a[i] == a[x]) {
				res.pb(i);
				vis[i] = 1;
			}
		}
		res.pb(x);
		vis[x] = 1;
	} else {
		for(int i = fx; i != stop; i = (i == 1 ? n : (i - 1))) {
			if(vis[i]) continue;
			if(a[i] == a[x]) {
				res.pb(i);
				vis[i] = 1;
			}
		}
		for(int i = stop; i != x; i = (i == n ? 1 : (i + 1))) {
			if(vis[i]) continue;
			if(a[i] == a[x]) {
				res.pb(i);
				vis[i] = 1;
			}
		}
		res.pb(x);
		vis[x] = 1;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(cost, 0x3f, sizeof cost);
	scanf("%d%d", &n, &s);
	rep(i, 1, n) scanf("%d", &a[i]), vec.pb(a[i]);
	sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
	rep(i, 1, n) a[i] = lower_bound(all(vec), a[i]) - vec.begin() + 1;
	rep(i, 1, n) pos[a[i]].pb(i);
	rep(v, 1, SZ(vec)) {
		solve(pos[v]);
	}
	// rep(v, 1, SZ(vec)) {
	// 	printf("V: %d\n", v);
	// 	for(auto x : pos[v]) 
	// 		for(auto y : pos[v]) {
	// 			printf("%d %d %d\n", x, y, cost[x][y]);
	// 		}
	// } 
	pos[0].pb(s);
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = 0;
	rep(i, 1, SZ(vec)) {
		for(auto x : pos[i - 1]) {
			for(auto y : pos[i]) {
				int tx = i == 1 ? 0 : x;
				if(dp[0][y] > dp[1][tx] + dis(x, y)) {
					dp[0][y] = dp[1][tx] + dis(x, y);
					from[0][y] = tx;
				}
			}
		}
		for(auto x : pos[i]) {
			for(auto y : pos[i]) {
				if(dp[1][y] > dp[0][x] + cost[x][y]) {
					dp[1][y] = dp[0][x] + cost[x][y];
					from[1][y] = x;
				}
			}
		}
	}
	int ans = inf, at = 0;
	for(auto x : pos[SZ(vec)]) {
		if(dp[1][x] < ans) {
			ans = dp[1][x];
			at = x;
		}
	}
	printf("%d\n", ans);
	res.pb(s);
	output(at);
	rep(i, 1, SZ(res) - 1) {
		go(res[i - 1], res[i]);
	}
	return 0;
}
/*
9 1
0 1 2 2 2 1 0 1 1
*/