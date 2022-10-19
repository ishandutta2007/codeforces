#include<bits/stdc++.h>
#define int long long
#define N 300015
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
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
int n,m,pd[N],tot,ans;
char s[N];
VI g[N];
int get(int x){
	x--;
	if(x < 0) return 0;
	return ((((3*x+1)*pd[x]-((x&1)?-1:1))%mod)*443664157)%mod;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	pd[0] = 1;
 	rep(i,1,n*m) pd[i] = (pd[i-1]*2)%mod;
 	rep(i,1,n){
 		g[i].resize(m+5);
 		scanf("%s",s+1);
 		// printf("%s\n",s+1);
 		rep(j,1,m){
 			if(s[j]=='*') g[i][j] = 0;
 			else g[i][j] = 1,tot++;
 		}
 	}
 	// printf("%d\n",get(4));
 	g[n+1].resize(m+5);
 	rep(i,1,n) g[i][m+1] = 0;
 	rep(j,1,m) g[n+1][j] = 0;
 	rep(i,1,n){
 		int cnt = 0;
 		rep(j,1,m+1) {
 			if(g[i][j] == 0){

 				// printf("i: %d %d\n",i,cnt);
 				// printf("%d %d\n",get(cnt),pd[tot-cnt]);
 				ans = (ans+pd[tot-cnt]*get(cnt))%mod;
 				cnt = 0;
 			}else cnt++;
 		}
 	}
 	rep(j,1,m){
 		int cnt = 0;
 		rep(i,1,n+1) {
 			if(g[i][j] == 0){
 				ans = (ans+pd[tot-cnt]*get(cnt))%mod;
 				cnt = 0;
 			}else cnt++;
 		}
 	}
 	printf("%lld\n",ans);
	return 0;
}