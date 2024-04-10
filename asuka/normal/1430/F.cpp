#include<bits/stdc++.h>
#define int long long
#define N 2005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,k,l[N],r[N],a[N],f[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	rep(i,1,n) scanf("%lld%lld%lld",&l[i],&r[i],&a[i]);
	memset(f,0x3f,sizeof f);
	f[1] = 0;
	rep(i,1,n){
		int now = k,ans = f[i];
		rep(j,i,n){
			int ti = ((max(0ll,a[j]-now)+k-1)/k);
			if(ti > r[j]-l[j]) break;
			int nxt = (now + k*ti) - a[j];
			ans += a[j];
			if(j+1 <= n){
				if(l[j]+ti < l[j+1]) f[j+1] = min(f[j+1],ans+nxt);
			}else{
				f[j+1] = min(f[j+1],ans);
			}
			now = nxt;
		}
	}
	if(f[n+1] >= inf) puts("-1");
	else printf("%lld\n",f[n+1]);
	return 0;
}