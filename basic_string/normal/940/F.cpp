#include<bits/stdc++.h>
using namespace std;
enum{N=100009,B=2137};
map<int,int>mp;
struct M{
	int p,x,y;
}o[N];
struct Q{
	int l,r,t,i;
	bool operator<(Q a)const{
		return l/B<a.l/B||(l/B==a.l/B&&(((l/B&1)?r/B<a.r/B:r/B>a.r/B)||(r/B==a.r/B&&((r/B&1)?t<a.t:t>a.t))));
	}
}q[N];
int ct[N*2],id,a[N],ans[N],f[N];
int get(int x){
	if(!mp[x])mp[x]=++id;
	return mp[x];
}
void del(int x){--f[ct[x]],--ct[x],++f[ct[x]];}
void add(int x){--f[ct[x]],++ct[x],++f[ct[x]];}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int t=0,tq=0,n,m,i,j,k,l=1,r=0;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>j,a[i]=get(j);
	while(m--)if(cin>>i>>j>>k,i==1)++tq,q[tq]={j,k,t,tq};else o[++t]={j,get(k),a[j]},a[j]=o[t].x;
	sort(q+1,q+tq+1);
	for(i=1;i<=tq;++i){
		for(;t>q[i].t;--t)if(a[o[t].p]=o[t].y,l<=o[t].p&&o[t].p<=r)del(o[t].x),add(o[t].y);
		for(;t<q[i].t;)if(++t,a[o[t].p]=o[t].x,l<=o[t].p&&o[t].p<=r)del(o[t].y),add(o[t].x);
		while(r<q[i].r)add(a[++r]);
		while(l>q[i].l)add(a[--l]);
		while(r>q[i].r)del(a[r--]);
		while(l<q[i].l)del(a[l++]);
		for(j=1;f[j];++j);
		ans[q[i].i]=j;
	}
	for(i=1;i<=tq;++i)cout<<ans[i]<<'\n';
}