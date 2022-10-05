#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=200009};
struct T{
	int l,r;
	ll a,b;
}s[N*24];
int c[N],r[N],rt[N],id,u,v,x,st[N],tim[N],nc[N],p;
ll now,h,ans;
basic_string<int>bs[N];
void bd(int&k,int l,int r){
	if(k=++id,l==r){s[k].a=::r[l];return;}
	int m=l+r>>1;
	bd(s[k].l,l,m),bd(s[k].r,m+1,r),s[k].a=s[s[k].l].a+s[s[k].r].a;
}
void upd(int&k,int l,int r){
	if(s[++id]=s[k],k=id,l==r){s[k].a=0,s[k].b=c[l];return;}
	int m=l+r>>1;
	u>m?upd(s[k].r,m+1,r):upd(s[k].l,l,m),s[k].a=s[s[k].l].a+s[s[k].r].a,s[k].b=s[s[k].l].b+s[s[k].r].b;
}
void qry(int k,int l,int r){
	if(u<=l&&r<=v){now+=s[k].a*x+s[k].b;return;}
	int m=l+r>>1;
	if(u<=m)qry(s[k].l,l,m);
	if(m<v)qry(s[k].r,m+1,r);
}
void erf(int k,int l,int r){
	ll w=s[k].a*x+s[k].b;
	int m=l+r>>1;
	if(l>=u){
		if(now+w<=h)now+=w,p=r;
		else if(l<r){
			if(w=s[s[k].l].a*x+s[s[k].l].b,now+w<=h)now+=w,p=m,erf(s[k].r,m+1,r);else erf(s[k].l,l,m);
		}
	}else if(m<u)erf(s[k].r,m+1,r);else if(erf(s[k].l,l,m),p==m)erf(s[k].r,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,j,t,o=0;
	for(cin>>n,i=1;i<=n;++i)if(cin>>c[i]>>r[i],j=c[i]/r[i]+1,j<N)bs[j]+=i;
	for(bd(rt[0],1,n),i=1;i<N;++i){
		rt[i]=rt[i-1];
		for(int o:bs[i])u=o,upd(rt[i],1,n);
	}
	for(st[0]=n+1,i=n;i;--i)st[++o]=i,nc[o]=c[i];
	for(cin>>m;m--;){
		cin>>t>>h;
		while(o){
			if(st[o-1]-(i=st[o])==1){
				j=min((ll)c[i],r[i]*1ll*(t-tim[o])+nc[o]);
				if(j>h){
					nc[o]=j-h,tim[o]=t;
					break;
				}
				h-=j,--o;
				continue;
			}
			x=t-tim[o],u=i,v=st[o-1]-1;
			now=0,qry(rt[x],1,n);
			if(now>h){
				now=0,p=u-1,erf(rt[x],1,n),++p;
				if(p==v)--o;else st[o]=p+1;
				st[++o]=p,j=min((ll)c[p],r[p]*1ll*x),h-=now,j-=h,nc[o]=j,tim[o]=t;
				break;
			}
			h-=now,--o;
		}
		if(!o)ans+=h;
		if(st[o]!=1)st[++o]=1,tim[o]=t,nc[o]=0;
	}
	cout<<ans;
}