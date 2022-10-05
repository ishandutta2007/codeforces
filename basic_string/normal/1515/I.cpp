#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct T{
	ll w[18],m[18],v[18];
	T(){memset(m,63,sizeof m);}
}s[524299];
enum{N=200009};
struct P{
	ll a;
	int w,v,lg,i;
}a[N];
int x,u,d,p,n,rk[N];
ll c,c2,now,val,ans;
void up(T&k,T&a,T&b){for(int i=0;i<18;++i)k.w[i]=a.w[i]+b.w[i],k.v[i]=a.v[i]+b.v[i],k.m[i]=min(a.m[i],b.m[i]+a.w[i]);}
void bd(int k,int l,int r){
	if(l==r){
		if(a[l].a)s[k].m[a[l].lg]=a[l].w;
		for(int i=17;i>a[l].lg;--i)s[k].w[i]=a[l].a*a[l].w,s[k].v[i]=a[l].a*a[l].v;
		return;
	}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),up(s[k],s[k*2],s[k*2+1]);
}
void upd(int k,int l,int r){
	if(l==r){
		if(a[l].a+=x)s[k].m[a[l].lg]=a[l].w;else s[k].m[a[l].lg]=4e18;
		for(int i=17;i>a[l].lg;--i)s[k].w[i]=a[l].a*a[l].w,s[k].v[i]=a[l].a*a[l].v;
		return;
	}
	int m=l+r>>1;
	u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),up(s[k],s[k*2],s[k*2+1]);
}
void e1(int k,int l,int r){
	if(l>=u){
		if(now+s[k].m[d]>c){
			now+=s[k].w[d],val+=s[k].v[d];
			return;
		}
		if(l==r){now+=a[l].w,val+=a[l].v,p=l;return;}
		int m=l+r>>1;
		if(e1(k*2,l,m),p>n)e1(k*2+1,m+1,r);
		return;
	}
	int m=l+r>>1;
	if(m<u||(e1(k*2,l,m),p>n))e1(k*2+1,m+1,r);
}
void e2(int k,int l,int r){
	if(l>=u){
		if(now+s[k].w[d]<=c2){
			now+=s[k].w[d],val+=s[k].v[d],p=r+1;
			return;
		}
		if(l==r){
			ll x=min(a[l].a,(c-now)/a[l].w);
			now+=a[l].w*x,val+=a[l].v*x,p=l;
			return;
		}
		int m=l+r>>1;
		if(e2(k*2,l,m),p>m)e2(k*2+1,m+1,r);
		return;
	}
	int m=l+r>>1;
	if(m<u||(e2(k*2,l,m),p>m))e2(k*2+1,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i;
	for(cin>>n>>q,i=1;i<=n;++i)cin>>a[i].a>>a[i].w>>a[i].v,a[i].lg=__lg(a[i].w),a[i].i=i;
	sort(a+1,a+n+1,[](P a,P b){return a.v>b.v||(a.v==b.v&&a.w<b.w);});
	for(i=1;i<=n;++i)rk[a[i].i]=i;
	for(bd(1,1,n);q--;)if(cin>>i,i==3){
		cin>>c;
		for(d=17,u=1,ans=0;u<=n&&~d;--d)if(c>>d){
			if(p=n+1,now=val=0,e1(1,1,n),p>n)now=val=0,c2=c-(1<<d),e2(1,1,n);
			ans+=val,c-=now,u=p+1;
		}
		cout<<ans<<'\n';
	}else{
		if(cin>>x>>u,u=rk[u],i==2)x=-x;
		upd(1,1,n);
	}
}