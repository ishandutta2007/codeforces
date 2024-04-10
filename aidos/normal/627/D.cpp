#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;


vector < int > g[200200], gg[200200];
int a[200200];
int cnt[200200];
int dp[200200];
int used[200200];
int nused[200200];
int k;
int n;

queue < int > q;
vector < int> ord;
int dis1[200200], dis2[200200];
int curd;
void dfs(int v, int p){
	nused[v] = 1;
	int &mx1 = dis1[v];
	int &mx2 = dis2[v];
	mx1 = 0;
	mx2 = 0;
	for(int i = 0; i < gg[v].size(); i++){
		int to = gg[v][i];
		if(to == p) continue;
		dfs(to, v);
		if(dis1[to]+dp[to] > mx1){
			mx2 = mx1;
			mx1 = dis1[to]+dp[to];
		}
		else if(dis1[to]+dp[to] > mx2){
			mx2 = dis1[to]+dp[to];
		}
	}
}

void dfs2(int  v, int p, int cc){
	int &mx1 = dis1[v];
	int &mx2 = dis2[v];
	curd = max(curd, mx1+cc+dp[v]);
	for(int i = 0; i < gg[v].size(); i++){
		int to = gg[v][i];
		if(to == p) continue;
		if(dis1[to]+dp[to] == mx1){
			dfs2(to, v, max(cc, mx2) + dp[v]);
		}
		else {
			dfs2(to, v, max(cc, mx1) + dp[v]);
		}
	}
}

int calc(int v){
	ord.clear();
	curd = 0;
	dfs(v, -1);
	dfs2(v, -1, 0);
	return curd;
}
int check(int x){
	for(int i = 0; i < n; i++){
		cnt[i] = 0;
		dp[i] = 1;
		used[i] = 0;
		nused[i] = 0;
	}
	while(q.size() > 0) q.pop();
	for(int i = 0; i < n; i++){
		gg[i].clear();
		if(a[i] >= x){
			for(int j = 0; j < g[i].size(); j++){
				int to = g[i][j];
				if(a[to] >= x) gg[i].pb(to);
			}
			if(g[i].size() == 1) {
				q.push(i);
				used[i] = 1;
			}
		}
		else nused[i] = 1;
	}
	int mx = 0;
	while(q.size() > 0){
		int v = q.front();
		q.pop();
		int ind = -1;
		for(int i = 0; i < gg[v].size(); i++){
			int to = gg[v][i];
			if(nused[to]) continue;
			ind = to;
		}
		if(ind == -1){
			mx = max(mx, dp[v]);
		}else {
			dp[ind] += dp[v];
			cnt[ind]++;
			if(cnt[ind]+1 == g[ind].size()) {
				q.push(ind);
			}
		}
		nused[v] = 1;
	}
	for(int i = 0; i < n; i++){
		gg[i].clear();
		if(nused[i]) continue;
		for(int j = 0; j < g[i].size(); j++){
			int to = g[i][j];
			if(nused[to]) continue;
			gg[i].pb(to);
		}
	}
	for(int i = 0; i < n; i++){
		if(nused[i]) continue;
		mx = max(mx, calc(i));
	}
	return mx;
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    for(int i = 1, x, y; i < n; i++){
    	scanf("%d %d", &x, &y);
    	g[x-1].pb( y - 1);
    	g[y - 1].pb(x - 1);
    }
    int l = 0, r = 1000100, ans = 0;
    while(l <= r){
    	int mid = (l + r) / 2;
    	if( check(mid) >= k) {
    		ans = mid;
    		l = mid+1;
    	}
    	else {
    		r = mid-1;
    	}
    }
    cout << ans << endl;


    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}