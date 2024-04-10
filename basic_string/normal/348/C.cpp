#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int he[N],to[N],ne[N],sz[N],f[509][N],id[509],ps[N];
bool b[N];
long long a[N],g[509],h[509];
int main(){
	register int n,m,q,i,j,k,ct=0,t=0;
	register long long w,s;
	register char ch;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	for(i=1;i<=m;++i){
		scanf("%d",sz+i);
		if(sz[i]>200)id[++ct]=i,ps[i]=ct;
		for(j=sz[i];j;--j)scanf("%d",&k),ne[++t]=he[i],to[t]=k,he[i]=t;
	}
	for(i=1;i<=ct;++i){
		memset(b,0,sizeof(b));
		for(j=he[id[i]];j;j=ne[j])b[to[j]]=1,h[i]+=a[to[j]];
		for(k=1;k<=n;++k){
			t=0;
			for(j=he[k];j;j=ne[j])if(b[to[j]])++t;
			f[i][k]=t;
		}
	}
	while(q--){
		scanf(" %c%d",&ch,&i);
		if(ch=='+'){
			scanf("%lld",&w);
			if(ps[i]){
				g[ps[i]]+=w;
			}else{
				for(j=he[i];j;j=ne[j])a[to[j]]+=w;
				for(k=1;k<=ct;++k)h[k]+=w*f[k][i];
			}
		}else{
			if(ps[i]){
				s=h[ps[i]];
			}else{
				for(j=he[i],s=0;j;j=ne[j])s+=a[to[j]];
			}
			for(k=1;k<=ct;++k)s+=g[k]*f[k][i];
			printf("%lld\n",s);
		}
	}
	return 0;
}