#include<bits/stdc++.h>
using namespace std;
const int N=200009,P=800009;
int n,u,v,p[N];
long long mn[P],tg[P],a[N],b[N],sm[N],w;
void build(int k,int l,int r){
	if(l==r){
		mn[k]=sm[l];
		return;
	}
	register int m=l+r>>1,a=k<<1,b=a|1;
	build(a,l,m),build(b,m+1,r);
	mn[k]=mn[a]<mn[b]?mn[a]:mn[b];
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		mn[k]+=w,tg[k]+=w;
		return;
	}
	register int m=l+r>>1,a=k<<1,b=a|1;
	if(tg[k]){
		mn[a]+=tg[k],mn[b]+=tg[k];
		tg[a]+=tg[k],tg[b]+=tg[k];
		tg[k]=0;
	}
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	mn[k]=mn[a]<mn[b]?mn[a]:mn[b];
}
int main(){
	register int i,j;
	register long long ans;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",p+i);
	for(i=1;i<=n;++i)scanf("%lld",a+i),b[p[i]]=a[i];
	ans=1e18;
	for(i=1;i<=n;++i)sm[i]=b[i]+sm[i-1];
	build(1,0,n);
	for(i=1;i<n;++i){
		u=0,v=p[i]-1,w=a[i],upd(1,0,n);
		u=p[i],v=n,w=-a[i],upd(1,0,n);
		ans=ans<mn[1]?ans:mn[1];
	}
	printf("%lld",ans);
	return 0;
}//srhearhsrjs5rjresj