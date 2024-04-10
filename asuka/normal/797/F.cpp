#include<bits/stdc++.h>
#define int long long
#define N 5015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
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
int n,m,a[N],c[N],p[N],f[N][N],q[N],pre[N];
pii P[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	memset(f,0x3f,sizeof f); f[0][0] = 0;
 	sort(a+1,a+n+1);
 	rep(i,1,m) scanf("%lld%lld",&P[i].fi,&P[i].se);
 	sort(P+1,P+m+1);
 	rep(i,1,m) p[i] = P[i].fi,c[i] = P[i].se;
 	int Ssum = 0;
 	rep(i,1,m) Ssum += c[i];
 	if(Ssum < n) return puts("-1"),0;
 	rep(j,1,m){
 		int l = 1,r = 0;
 		f[0][j] = q[++r] = 0;
 		rep(i,1,n){
 			// printf("i: %d\n",i);
 			pre[i] = pre[i-1] + abs(a[i] - p[j]);
 			// printf("%d\n",pre[i]);
 			while(i - c[j] > q[l]) l++;
 			// rep(_,l,r) printf("%d ",q[_]); printf("\n");
 			f[i][j] = min(f[i][j-1] , f[q[l]][j-1] - pre[q[l]] + pre[i]);
 			// printf("ans: %d\n",f[i][j]);
 			while(l <= r && f[i][j-1] - pre[i] <= f[q[r]][j-1] - pre[q[r]]) r--;
 			q[++r] = i;
 		}
 	}
 	printf("%lld\n",f[n][m]);
	return 0;
}