#include<bits/stdc++.h>
using namespace std;
enum{N=100009,M=N*3};
struct E{int u,v,w,i;}e[M];
struct F{int f,s;}f[N];
int gf(int x){return f[x].f==x?x:gf(f[x].f);}
int id[M],st[N],t,ans[M],c;
void bk(int t2,int c2){
	int x,y;
	for(c=c2;t>t2;--t)x=st[t],y=f[x].f,f[x].f=x,f[y].s-=f[x].s;
}
void mg(int x,int y){
	if(x==y)return;
	if(f[x].s>f[y].s)swap(x,y);
	st[++t]=x,f[x].f=y,c-=f[x].s&1,c-=f[y].s&1,f[y].s+=f[x].s,c+=f[y].s&1;
}
void ad(int i){mg(gf(e[i].u),gf(e[i].v));}
void wk(int l,int r,int x,int y){
	if(l>r)return;
	int t2=t,c2=c,i,m=l+r>>1;
	for(i=l;i<=m;++i)if(id[i]<x)ad(id[i]);
	for(i=x;i<=y;++i)if(e[i].i<=m)if(ad(i),!c){ans[m]=i;break;}
	for(bk(t2,c2),i=l;i<=m;++i)if(id[i]<x)ad(id[i]);
	if(wk(m+1,r,x,ans[m]?ans[m]:y),bk(t2,c2),ans[m]){
		for(i=x;i<ans[m];++i)if(e[i].i<l)ad(i);
		wk(l,m-1,ans[m],y),bk(t2,c2);
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i;
	for(cin>>n>>m,i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w,e[i].i=i;
	for(sort(e+1,e+m+1,[](E a,E b){return a.w<b.w;}),i=1;i<=m;++i)id[e[i].i]=i;
	for(i=1;i<=n;++i)f[i]={i,1};
	for(i=1,c=n,wk(1,m,1,m);i<=m;++i)cout<<(ans[i]?e[ans[i]].w:-1)<<'\n';
	return 0;
}