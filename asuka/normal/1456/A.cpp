#include<bits/stdc++.h>
#define int long long
#define N 300015
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
using namespace std;
int t,n,p,x,y,k,f[N];
char s[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	while(t--){
 		scanf("%lld%lld%lld",&n,&p,&k);
 		scanf("%s",s+1);
 		rep(i,1,n+k+1) f[i] = 0;
 		scanf("%lld%lld",&x,&y);
 		per(i,1,n){
 			f[i] = f[i+k]+(s[i]=='0'?x:0);
 		}
 		// rep(i,1,n) printf("%d ",f[i]);
 		// printf("\n");
 		int ans = inf;
 		rep(i,p,n) ans = min(ans,(i-p)*y+f[i]);
 		printf("%lld\n",ans);
 	}
	return 0;
}