#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=998244353;
int a[N],b[N],pr[N],ne[N];
bool f[N];
int main(){
	int T,n,m,i,j,k,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),s=1;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<n;++i)ne[a[i]]=a[i+1];
		for(i=2;i<=n;++i)pr[a[i]]=a[i-1];
		ne[a[n]]=pr[a[1]]=0;
		memset(f,0,n+1),f[0]=1;
		for(i=1;i<=m;++i)scanf("%d",b+i),f[b[i]]=1;
		for(i=1;i<=m;++i){
			if(f[pr[b[i]]]&&f[ne[b[i]]]){printf("%d\n",0);goto gg;}
			if(!f[pr[b[i]]]&&!f[ne[b[i]]])s=s*1ll*2%P;
			ne[pr[b[i]]]=ne[b[i]],pr[ne[b[i]]]=pr[b[i]];
		}
		printf("%d\n",s);
		gg:;
	}
	return 0;
}