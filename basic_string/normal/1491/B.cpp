#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	int T,n,u,v,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&u,&v),k=0;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<n;++i)if(abs(a[i]-a[i+1])>1)goto gg;
		for(i=1;i<n;++i)if(abs(a[i]-a[i+1])>0){k=min(u,v);goto gg;}
		k=min(v+v,u+v);
		gg:;
		printf("%d\n",k);
	}
	return 0;
}