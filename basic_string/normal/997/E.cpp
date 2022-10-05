#include<bits/stdc++.h>
using namespace std;
#define _ s[k],s[k*2],s[k*2+1]
#define I int k,int l,int r
#define W(F) int m=(l+r)>>1;if(dn(_),u<=m)F(k*2,l,m);if(m<v)F(k*2+1,m+1,r);
enum{N=120009};
using ll=long long;
struct T{
	int i,c,t,h;
	ll w;
}s[262199];
int u,v,w,p[N],mx[N],mxt,mn[N],mnt;
ll ans[N],now;
vector<pair<int,int>>g[N];
auto ad=[](T&k,int v){k.i+=v,k.t+=v;};
auto wk=[](T&k,int v){k.h+=v,k.w+=k.c*1ll*v;};
auto dn=[](T&k,T&a,T&b){
	if(k.t)ad(a,k.t),ad(b,k.t),k.t=0;
	if(k.h){
		if(a.i==k.i)wk(a,k.h);
		if(b.i==k.i)wk(b,k.h);
		k.h=0;
	}
};
auto up=[](T&k,T&a,T&b){
	if(a.i<b.i)k.i=a.i,k.c=a.c;
	else if(a.i>b.i)k.i=b.i,k.c=b.c;
	else k.i=a.i,k.c=a.c+b.c;
};
void bd(I){if(s[k].c=r-l+1,l==r)return;int m=(l+r)>>1;bd(k*2,l,m),bd(k*2+1,m+1,r);}
void upd(I){if(u<=l&&r<=v)return ad(s[k],w);W(upd) up(_);}
void qry(I){if(u<=l&&r<=v){now+=s[k].w;return;}W(qry)}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,q,i,j,k;
	cin>>n,bd(1,1,n);
	for(i=1;i<=n;++i)cin>>p[i];
	cin>>q;
	for(i=1;i<=q;++i)cin>>j>>k,g[k].push_back({j,i});
	for(i=1;i<=n;++i){
		while(mxt&&p[mx[mxt]]<p[i])u=mx[mxt-1]+1,v=mx[mxt],w=-p[mx[mxt]],upd(1,1,n),--mxt;
		while(mnt&&p[mn[mnt]]>p[i])u=mn[mnt-1]+1,v=mn[mnt],w=p[mn[mnt]],upd(1,1,n),--mnt;
		u=mx[mxt]+1,v=i,w=p[i],upd(1,1,n),u=mn[mnt]+1,w=-p[i],upd(1,1,n),u=1,w=-1,upd(1,1,n),mx[++mxt]=mn[++mnt]=i,wk(s[1],1);
		for(auto o:g[i])now=0,u=o.first,qry(1,1,n),ans[o.second]=now;
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
}