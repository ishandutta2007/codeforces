#include<bits/stdc++.h>
using namespace std;
int a[3609];
int main(){
	register int T,n,m,k,p,i,j,ans,g;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k),ans=0;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=m;++i)a[i]=max(a[i],a[i+n-m]);
		if(k>=m)k=m-1;
		++k;
		for(i=1;i<=k;++i){
			g=2e9;
			for(j=i+m-k;j>=i;--j)g=min(a[j],g);
			ans=max(ans,g);
		}
		printf("%d\n",ans);
	}
	return 0;
}//@#