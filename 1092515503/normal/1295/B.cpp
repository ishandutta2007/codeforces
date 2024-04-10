#include<bits/stdc++.h>
using namespace std;
int T,n,x,sum[100100],res;
char s[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x),res=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)if(s[i]=='0')sum[i]=sum[i-1]+1;else sum[i]=sum[i-1]-1;
		if(sum[n]==0){
			for(int i=1;i<=n;i++)if(sum[i]==x)res=-1;
			printf("%d\n",res);
			continue;
		}
		for(int i=0;i<n;i++){
			if(x>sum[i]&&sum[n]<0)continue;
			if(x<sum[i]&&sum[n]>0)continue;
			if(abs(x-sum[i])%abs(sum[n]))continue;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}