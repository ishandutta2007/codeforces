#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=300009};
struct Q{
	int k,i;
}q[N];
struct O{
	int x,y,l,r=-1;
}o[N];
int ido[N],u,v;
ll ans[N],now;
struct P{
	int x,y;
	P operator-(P a)const{return{x-a.x,y-a.y};}
	ll operator*(P a)const{return x*1ll*a.y-y*1ll*a.x;}
}p;
struct C{
	vector<P>a;
	int x;
	void ins(){
		while(a.size()>1&&(a.back()-a[a.size()-2])*(p-a.back())<=0)a.pop_back();
		a.push_back(p);
	}
	void qry(){
		if(a.empty())return;
		while(x+1<(int)a.size()&&a[x].y-a[x+1].y<v*1ll*(a[x].x-a[x+1].x))++x;
		now=max(now,a[x].y-a[x].x*1ll*v);
	}
}c[1048579];
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return c[k].ins();
	int m=(l+r)/2;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void qry(int k,int l,int r){
	if(c[k].qry(),l==r)return;
	int m=(l+r)/2;
	u>m?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,tq=0,i,j,k,to=0;
	for(cin>>n,i=1;i<=n;++i)if(cin>>j>>k,j==1)++to,cin>>o[to].y,o[to].x=k,o[to].l=tq+1,ido[i]=to;
	else if(j==2)o[ido[k]].r=tq;else if(j==3)++tq,q[tq]={k,tq};
	for(i=1;i<=to;++i)if(o[i].r==-1)o[i].r=tq;
	sort(o+1,o+to+1,[](O a,O b){return a.x>b.x||(a.x==b.x&&a.y>b.y);});
	for(i=1;i<=to;++i)if(o[i].l<=o[i].r)u=o[i].l,v=o[i].r,p={o[i].x,o[i].y},upd(1,1,tq);
	sort(q+1,q+tq+1,[](Q a,Q b){return a.k>b.k;});
	for(i=1;i<=tq;++i)now=-4e18,u=q[i].i,v=-q[i].k,qry(1,1,tq),ans[u]=now;
	for(i=1;i<=tq;++i)if(ans[i]>-3e18)cout<<ans[i]<<'\n';else cout<<"EMPTY SET\n";
}