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
int n, m;
ll k, a[25][25];
map<ll, int> f[25][25], g[25][25];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%lld", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) scanf("%lld", &a[i][j]);
	f[1][1][a[1][1]] = 1;
	g[n][m][a[n][m]] = 1;
	rep(i, 1, n) rep(j, 1, m) {
		if(i == 1 && j == 1) continue;
		if(i + j > 20) continue;
		for(auto x : f[i - 1][j]) f[i][j][x.fi ^ a[i][j]] += x.se;
		for(auto x : f[i][j - 1]) f[i][j][x.fi ^ a[i][j]] += x.se;
	}
	per(i, 1, n) per(j, 1, m) {
		if(i == n && j == m) continue;
		if(i + j <= 20) continue;
		for(auto x : g[i + 1][j]) g[i][j][x.fi ^ a[i][j]] += x.se;
		for(auto x : g[i][j + 1]) g[i][j][x.fi ^ a[i][j]] += x.se;
	}
	ll ans = 0;
	if(n + m <= 20) {
		ans = f[n][m][k];
	} else {
		rep(i, 1, n) rep(j, 1, m) {
			if(i + j != 20) continue;
			for(auto x : f[i][j]) {
				ans += (ll) x.se * g[i + 1][j][x.fi ^ k];
				ans += (ll) x.se * g[i][j + 1][x.fi ^ k];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*
1 20 1048575
1 2 4 8 
*/