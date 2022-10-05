#include<bits/stdc++.h>
using namespace std;
struct P{
	int l,r,id;
}p[200009],q[200009];
inline bool cmp1(P a,P b){return a.l<b.l;}
inline bool cmp2(P a,P b){return a.r<b.r;}
int n,m;
long long s;
bool f[200009];
bool check(int x){
	memset(f,0,n+3);
	register int i=1,k=0;
	register long long g=0;
	while(q[i].r<x)g+=q[i].l,f[q[i++].id]=1,++k;
	for(i=1;k<m&&i<=n;++i){
		if(!f[p[i].id]){
			g+=p[i].l,++k;
		}
	}
	for(;i<=n;++i){
		if(!f[p[i].id]){
			g+=max(p[i].l,x);
		}
	}
	return g<=s;
}
int main(){
	int T,i,l,r,mid,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&s),m=n>>1;
		for(i=1;i<=n;++i)scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i,q[i]=p[i];
		sort(p+1,p+n+1,cmp1),l=p[m+1].l;
		sort(q+1,q+n+1,cmp2),r=q[m+1].r;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}