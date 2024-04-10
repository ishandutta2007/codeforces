#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int a[N],s[N*4],t[N*4],u,pr[N],nx[N],lp[N],rp[N];
void bd(int k,int l,int r){
	if(s[k]=l,t[k]=0,l==r)return;
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r);
}
void upd(int k,int l,int r){
	if(u<=l)return--s[k],void(--t[k]);
	int m=l+r>>1;
	if(t[k])t[k*2]+=t[k],t[k*2+1]+=t[k],s[k*2]+=t[k],s[k*2+1]+=t[k],t[k]=0;
	if(u<=m)upd(k*2,l,m);
	upd(k*2+1,m+1,r),s[k]=min(s[k*2],s[k*2+1]);
}
int main(){
	int T,n,i,l,w,o,c;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n),c=nx[n+1]=0,memset(lp,0,n*4+4),memset(rp,0,n*4+4);
		for(i=1;i<=n;++i)scanf("%d",a+i),pr[i]=pr[i-1]+!a[i];
		if(!(o=w=pr[n]/2)){puts("0");continue;}
		for(i=n;i;--i)if(nx[i]=nx[i+1]+!a[i],nx[i]<=o)l=i;
		for(i=1;i<l;++i)lp[a[i]]=i;
		for(i=n;i>=l;--i)rp[a[i]]=i;
		for(i=1;i<=n;++i)if(lp[i]||rp[i])++c;
		bd(1,0,o);
		for(i=1;i<=n;++i)if(!lp[i]&&rp[i])u=nx[rp[i]],upd(1,0,o);
		for(i=1,w=min(w,c+s[1]);i<l;++i)if(a[i]&&lp[a[i]]==i){
			if(rp[a[i]])u=nx[rp[a[i]]],upd(1,0,o);else --c;
			w=min(w,c+s[1]+pr[i]);
		}
		printf("%d\n",w);
	}
	return 0;
}