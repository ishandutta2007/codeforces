#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main(){
	int t,n,p,i,s;
	register char j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;++i){
			scanf(" %c",&j);
			if(j=='0')a[i]=a[i-1]+1;
			else a[i]=a[i-1]-1;
		}
		if(a[n]==0){
			for(i=1;i<=n;++i)if(a[i]==p){
				puts("-1");
				goto ggg;
			}
			puts("0");
			ggg:;
			continue;
		}
		s=0;
		for(i=0;i<n;++i)if((p-a[i])%a[n]==0&&(p-a[i])/a[n]>=0)++s;
		printf("%d\n",s);
	}
	return 0;
}//srhsrehresjhsrejrsejrsejsrej