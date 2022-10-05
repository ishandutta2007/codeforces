#include<bits/stdc++.h>
using namespace std;
enum{N=100003};
int n,o,a[N],t[N];
long long ans;
struct P{int x,l,r,q;}p[N],q[N];
int get(int x){return lower_bound(a+1,a+n+1,x)-a;}
void add(int x,int y){for(;x<=n;x+=x&-x)t[x]+=y;}
int sum(int x){int r=0;for(;x;x&=x-1)r+=t[x];return r;}
void cdq(int l,int r){
	if(l==r)return;
	int m=l+r>>1,j=m+1,k=j,i=l;
	for(cdq(l,m),cdq(j,r);i<=m;++i){
		while(j<=r&&p[j].q>=p[i].q-o)add(p[j].x,1),++j;
		while(k<=r&&p[k].q>p[i].q+o)add(p[k].x,-1),++k;
		ans+=sum(p[i].r)-sum(p[i].l-1);
	}
	while(k<j)add(p[k].x,-1),++k;
	merge(p+l,p+m+1,p+m+1,p+r+1,q,[](P a,P b){return a.q>b.q;}),memcpy(p+l,q,sizeof(P)*(r-l+1));
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i;
	for(cin>>n>>o,i=1;i<=n;++i)cin>>p[i].x>>p[i].r>>p[i].q,a[i]=p[i].x;
    sort(p+1,p+n+1,[](P a,P b){return a.r<b.r;}),sort(a+1,a+n+1);
    for(i=1;i<=n;++i)p[i].l=get(p[i].x-p[i].r),p[i].r=get(p[i].x+p[i].r+1)-1,p[i].x=get(p[i].x);
    cdq(1,n),cout<<ans;
	return 0;
}