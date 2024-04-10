#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int p[N],pos[N],pr[N],nx[N],stk[N],u,v,w;
vector<tuple<int,int,int>>o[N],vc[N]; 
using ll=long long;
ll ans[N*5]; 
struct T{
	int mn,t,c,h,l;
	ll w;
}s[N*4];
auto ad=[](T&k,int v){
	k.mn+=v,k.t+=v;
};
auto wk=[](T&k,int v){k.h+=v,k.w+=k.c*1ll*v;};
auto dn=[](T&k,T&a,T&b){
	if(k.t)ad(a,k.t),ad(b,k.t),k.t=0;
	if(k.h){
		if(a.mn==k.mn)wk(a,k.h);
		if(b.mn==k.mn)wk(b,k.h);
		k.h=0;
	}
};
auto up=[](T&k,T&a,T&b){
if(a.mn<b.mn)k.mn=a.mn,k.c=a.c;
else if(a.mn>b.mn)k.mn=b.mn,k.c=b.c;
else k.mn=a.mn,k.c=a.c+b.c;	
};
void bd(int k,int l,int r){
	s[k].l=s[k].c=r-l+1;
	if(l==r)return;
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return ad(s[k],w);
	int m=l+r>>1;
	dn(s[k],s[k*2],s[k*2+1]);
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
	up(s[k],s[k*2],s[k*2+1]);
}
ll qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k].w;
	int m=l+r>>1;
	ll z=0;dn(s[k],s[k*2],s[k*2+1]);
	if(u<=m)z=qry(k*2,l,m);
	if(m<v)z+=qry(k*2+1,m+1,r);
	return z;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,q,i,j,x,y,k,l,r,tp=0,u2,v2;
	cin>>n>>q;
	for(i=1;i<=n;++i)cin>>p[i],pos[p[i]]=i;
	stk[0]=0;
	for(i=1;i<=n;++i){
		while(tp&&p[stk[tp]]<p[i])--tp;
		pr[i]=stk[tp];
		stk[++tp]=i;
	}
	stk[tp=0]=n+1;
	for(i=n;i;--i){
		while(tp&&p[stk[tp]]<p[i])--tp;
		nx[i]=stk[tp];stk[++tp]=i;
	}
	bd(1,1,n);
	for(i=1;i<=n;++i)for(j=1;i*j<=n;++j){
		x=pos[i],y=pos[j];
		if(x>=y)continue;
		w=pos[i*j];
		u=pr[w]+1,v=nx[w]-1;
		u2=min(min(x,y),w);
		v2=max(max(x,y),w);
		if(u<=u2&&v2<=v){
			vc[u].push_back(make_tuple(v2,v,1));
			vc[u2+1].push_back(make_tuple(v2,v,-1));
		}
	}
	for(i=1;i<=q;++i){
		cin>>l>>r;
	o[l-1].push_back(make_tuple(r,i,-1));	
	o[r].push_back(make_tuple(r,i,1));
	
	}
	for(i=1;i<=n;++i){
		for(auto oo:vc[i]){
			tie(u,v,w)=oo;
			upd(1,1,n);
		}
	wk(s[1],1);
//	if(i==2)u=1,v=3,cout<<qry(1,1,n)<<'!'<<'\n';
		for(auto oo:o[i]){
			tie(r,j,x)=oo;
			u=1,v=r;
			ans[j]+=(i*1ll*r-qry(1,1,n))*x;
		}
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
}
/*
pipj
max pl...pr = pi*pj
l<=i j<=r
wpi*pj upw  vpw
l>u r<v
u<l<=min(i,w,j)<=max(i,w,j)<=r<v
nloglog+qlog 
 
ans[r][r]-ans[l-1][r] 
*/