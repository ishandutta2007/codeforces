#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
struct Q{
	int xl,xr,yl,yr,z,i;
}q[N];
struct P{
	int x,y,i;
}p[N];
int n,m,ans[N],now,u,pos[N];
struct T{
	int xl,xr,yl,yr,s;
}s[N*4];
void bd(int k,int l,int r,bool d){
	if(l==r){
		s[k].xl=s[k].xr=p[l].x;
		s[k].yl=s[k].yr=p[l].y;
		s[k].s=p[l].i,pos[p[l].i]=l;
		return;
	}
	int m=(l+r)>>1;
	nth_element(p+l,p+m,p+r+1,[=](P a,P b){return d?a.x<b.x:a.y<b.y;});
	bd(k*2,l,m,!d),bd(k*2+1,m+1,r,!d);
	s[k].s=min(s[k*2].s,s[k*2+1].s);
	s[k].xl=min(s[k*2].xl,s[k*2+1].xl),s[k].xr=max(s[k*2].xr,s[k*2+1].xr);
	s[k].yl=min(s[k*2].yl,s[k*2+1].yl),s[k].yr=max(s[k*2].yr,s[k*2+1].yr);
}
void qry(int k){
	if(s[k].s>=now||s[k].xl>q[u].xr||s[k].xr<q[u].xl||s[k].yl>q[u].yr||s[k].yr<q[u].yl)return;
	if(s[k].xl>=q[u].xl&&s[k].xr<=q[u].xr&&s[k].yl>=q[u].yl&&s[k].yr<=q[u].yr){now=s[k].s;return;}
	qry(k*2),qry(k*2+1);
}
void upd(int k,int l,int r){
	if(l==r){s[k].s=N;return;}
	int m=(l+r)>>1;
	if(pos[now]>m)upd(k*2+1,m+1,r);else upd(k*2,l,m);
	s[k].s=min(s[k*2].s,s[k*2+1].s);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n;++i)cin>>q[i].xl>>q[i].xr>>q[i].yl>>q[i].yr>>q[i].z,q[i].i=i;
	cin>>m;
	for(i=1;i<=m;++i)cin>>p[i].x>>p[i].y,p[i].i=i;
	bd(1,1,m,1);
	sort(q+1,q+n+1,[](Q a,Q b){return a.z<b.z;});
	for(i=1;i<=n;++i){
		now=N,u=i,qry(1);
		if(now<N)ans[now]=q[i].i,upd(1,1,m);
	}
	for(i=1;i<=m;++i)cout<<ans[i]<<'\n';
}