#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ll=long long;
struct A{
	int x,p,i;
	bool operator<(A a)const{return x<a.x;}
}a[N];
struct B{
	int x,p,q;
}b[N*3];
ll c[N],pre[N],suf[N];
int w[N];
bool ans[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,t;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i].x>>a[i].p,a[i].i=i;
		sort(a+1,a+n+1);t=0;
		for(i=1;i<=n;++i){
			b[++t]={a[i].x-a[i].p,1,a[i].p-a[i].x};
			b[++t]={a[i].x,-2,a[i].x*2};
			b[++t]={a[i].x+a[i].p,1,-a[i].p-a[i].x}; 
		}
		sort(b+1,b+t+1,[](B u,B v){return u.x<v.x;});
		int t2=1;
		ll sp=0,sq=0;
		pre[0]=suf[n+1]=-1e18;
		for(i=1;i<=n;++i){w[i]=a[i].x;
			while(t2<=t&&b[t2].x<=a[i].x)sp+=b[t2].p,
			sq+=b[t2].q,++t2;
			c[i]=sp*a[i].x+sq;
			pre[i]=max(pre[i-1],c[i]+a[i].x);
			suf[i]=c[i]-a[i].x;
		}
		for(i=n;i;--i)suf[i]=max(suf[i+1],suf[i]);
		int mn=2e9+9,mx=-2e9;
		for(i=1;i<=n;++i)if(c[i]>m)mn=min(mn,a[i].x),
		mx=max(mx,a[i].x);
		memset(ans,0,n+1);
		for(i=1;i<=n;++i)if(a[i].x-a[i].p<=mn&&
		a[i].x+a[i].p>=mx/*&&pre[i]+a[i].x-a[i].p<=m&&
		suf[i]-a[i].p-a[i].x<=m*/){
			j=upper_bound(w+1,w+n+1,a[i].x+a[i].p)-w-1;
			if(pre[j]-a[i].p-a[i].x<=m){
				j=lower_bound(w+1,w+n+1,a[i].x-a[i].p)-w;
				if(suf[j]-a[i].p+a[i].x<=m)ans[a[i].i]=1;
			}
		}
		for(i=1;i<=n;++i)cout<<ans[i];cout<<'\n';
	}
}