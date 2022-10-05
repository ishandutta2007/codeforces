#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+3;
int u,v,rt,id;
struct T{
	int s,l,r;
}s[N*39];
void upd(int&k,int l,int r){
	if(!k)k=++id;
	if(l==r){s[k].s=v;return;}
	int m=l+r>>1;
	if(u<=m)upd(s[k].l,l,m);else upd(s[k].r,m+1,r);
	s[k].s=min(s[s[k].l].s,s[s[k].r].s);
}
int qry(int k,int l,int r){
	if(!k||(u<=l&&r<=v))return s[k].s;
	int m=l+r>>1;
	if(u<=m)return m<v?min(qry(s[k].l,l,m),qry(s[k].r,m+1,r)):qry(s[k].l,l,m);
	return qry(s[k].r,m+1,r);
}
int a[N];
ll w[N],p[N];
int main(){
	int n,g,r,o,i,j,q;
	ll now=0,x;
	scanf("%d%d%d",&n,&g,&r),o=g+r,s[0].s=N;
	for(i=0;i<=n;++i)scanf("%d",a+i);
	auto get=[&](ll x){
		int b=((x-g)%o+o)%o,a=((x+1)%o+o)%o;
		if(a<=b)return u=a,v=b,qry(rt,0,o-1);
		u=a,v=o-1;
		int w=qry(rt,0,o-1);
		return u=0,v=b,min(w,qry(rt,0,o-1));
	};
	for(i=n;i;--i){
		now+=a[i],p[i]=now;
		j=get(now);
		u=(now%o+o)%o,v=i,upd(rt,0,o-1);
		if(j==N)w[i]=now;else w[i]=((now-p[j])/o+1)*o+w[j];
	}
	for(now+=a[0],scanf("%d",&q);q--;){
		scanf("%d",&i),x=now+i;
		j=get(x);
		printf("%lld\n",j==N?x:((x-p[j])/o+1)*o+w[j]);
	}
	return 0;
}