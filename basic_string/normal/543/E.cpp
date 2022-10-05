#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct T{
	unsigned long long x:18,l:23,r:23;
}s[N*40];
pair<int,int>a[N];
int rt[N],id,u,v;
#define lx l==m?s[k].l:s[s[k].l].x
#define rx m+1==r?s[k].r:s[s[k].r].x
int upd(int t,int l,int r){
	if(l==r)return t+1;
	int k=++id;
	if(s[k]=s[t],u<=l&&r<=v)return ++s[k].x,k;
	int m=l+r>>1,w=s[k].x-max(lx,rx);
	if(u<=m)s[k].l=upd(s[t].l,l,m);
	if(m<v)s[k].r=upd(s[t].r,m+1,r);
	return s[k].x=max(lx,rx)+w,k;
}
int qry(int k,int l,int r){
	if(l==r)return k;
	if(u<=l&&r<=v)return s[k].x;
	int m=l+r>>1,z=0;
	if(u<=m)z=qry(s[k].l,l,m);
	if(m<v)z=max(z,qry(s[k].r,m+1,r));
	return z+s[k].x-max(lx,rx);
}
int main(){
	int n,m,p,q,i,j,l=0;
	scanf("%d%d",&n,&m),p=n-m+1;
	for(i=1;i<=n;++i)scanf("%d",&j),a[i].first=-j,a[i].second=i;
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)j=a[i].second,u=max(1,j-m+1),v=min(p,j),rt[i]=upd(rt[i-1],1,p);
	scanf("%d",&q);
	while(q--)scanf("%d%d%d",&u,&v,&i),i^=l,printf("%d\n",l=m-qry(rt[upper_bound(a+1,a+n+1,make_pair(-i,N))-a-1],1,p));
	return 0;
}