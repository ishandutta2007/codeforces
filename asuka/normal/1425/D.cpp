#include<bits/stdc++.h>
#define int long long
#define N 2005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define x1 wtf
#define y1 ccflovesmoney
#define x2 yyy
#define y2 jfkefw
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
const int mod = 1e9+7;
int n,m,r,s[N][N],x[N],y[N],b[N],C[N][N],ans;
int getsum(int x0,int y0,int x1,int y1){
	x0 = max(1ll,x0);y0 = max(1ll,y0);
	x1 = min(x1,1000ll);y1 = min(y1,1000ll);
	if(x0 > x1 || y0 > y1) return 0;
	return s[x1][y1]-s[x1][y0-1]-s[x0-1][y1]+s[x0-1][y0-1];
}
int getsum(int a,int b){
	return getsum(a-r,b-r,a+r,b+r);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&r);
	rep(i,1,n){
		C[i][0] = C[i][i] = 1;
		rep(j,1,i-1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
	}
	rep(i,1,n) scanf("%lld%lld%lld",&x[i],&y[i],&b[i]),s[x[i]][y[i]]++;
	rep(i,1,1000) rep(j,1,1000) s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	rep(i,1,n){
		rep(j,i,n){
			int x1 = x[i],y1 = y[i],x2 = x[j],y2 = y[j];
			int w = getsum(max(x1,x2)-r,max(y1,y2)-r,min(x1,x2)+r,min(y1,y2)+r);
			int cnt = (C[n][m]-C[n-w][m]+mod)%mod;
			int u = getsum(x1,y1),v = getsum(x2,y2);
			u -= w;v -= w;
			int nn = n-w;
			cnt = (cnt + C[nn][m] - C[nn-u][m] - C[nn-v][m] + C[nn-u-v][m])%mod;
			while(cnt < 0) cnt = (cnt+mod)%mod;
			if(i == j) ans = (ans+(1ll*cnt*b[i])%mod*b[j])%mod;
			else ans = (ans+(2ll*cnt*b[i])%mod*b[j])%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}