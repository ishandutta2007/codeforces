#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	int T,n,k,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k),j=0,--k;
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=2;i<=n;++i)if(a[i]!=a[i-1])++j;
		if(k==0){
			if(j>0)puts("-1");else printf("%d\n",1);
		}else printf("%d\n",max(1,j%k==0?(j/k):(j/k+1)));
	}
	return 0;
}