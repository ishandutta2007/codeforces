#include<bits/stdc++.h>
#define ll long long
#define N 5005
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
int t, n, m, ans[N][N];
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,1,-1,-1};
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&n,&m);
		rep(i, 1, n) {
			rep(j, 1, m) ans[i][j] = 0;
		}
		ans[1][1] = ans[1][m] = ans[n][1] = ans[n][m] = 1;
		rep(i, 1, n) rep(j, 1, m) {
			if(ans[i][j]) continue;
			if(i == 1 || i == n || j == 1 || j == m ){
				bool res = 1;
				rep(d, 0, 7) {
					int ti = i + dx[d], tj = j + dy[d];
					if(1 <= ti && ti <= n && 1 <= tj && tj <= m) {
						res &= ans[ti][tj] == 0;
					}
				}
				if(res) ans[i][j] = 1;
			}
		}
		rep(i, 1, n) {
			rep(j, 1, m) printf("%d", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}