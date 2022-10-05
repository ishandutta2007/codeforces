#include<bits/stdc++.h>
using namespace std;
#define _ s[k],s[k*2],s[k*2+1]
#define I int k,int l,int r
#define W(F) int m=(l+r)>>1;if(dn(_),u<=m)F(k*2,l,m);if(m<v)F(k*2+1,m+1,r);
enum{N=300009};
int a[N],u,v,w,mx[N],mn[N],tmx,tmn;
struct T{
	int i,c,t;
}s[1048599];
void bd(I){
	if(s[k].c=r-l+1,l==r)return;
	int m=(l+r)>>1;bd(k*2,l,m),bd(k*2+1,m+1,r);
}
auto ad=[](T&k,int v){k.i+=v,k.t+=v;};
auto dn=[](T&k,T&a,T&b){if(k.t)ad(a,k.t),ad(b,k.t),k.t=0;};
auto up=[](T&k,T&a,T&b){
	if(a.i<b.i)k.i=a.i,k.c=a.c;
	else if(a.i>b.i)k.i=b.i,k.c=b.c;
	else k.i=a.i,k.c=a.c+b.c;
};
void upd(I){
	if(u<=l&&r<=v)return ad(s[k],w);
	W(upd) up(_);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k;
	long long ans=0;
	cin>>n,bd(1,1,n);
	for(i=1;i<=n;++i)cin>>j>>k,a[j]=k;
	for(i=1;i<=n;++i){
		u=1,v=i,w=-1,upd(1,1,n);
		while(tmx&&a[mx[tmx]]<a[i])u=mx[tmx-1]+1,v=mx[tmx],w=-a[mx[tmx]],upd(1,1,n),--tmx;
		while(tmn&&a[mn[tmn]]>a[i])u=mn[tmn-1]+1,v=mn[tmn],w=a[mn[tmn]],upd(1,1,n),--tmn;
		u=mx[tmx]+1,v=i,w=a[i],upd(1,1,n),mx[++tmx]=i;
		u=mn[tmn]+1,v=i,w=-a[i],upd(1,1,n),mn[++tmn]=i;
		ans+=s[1].c;
	}
	cout<<ans;
}