#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,num[1010],C[1010][1010],f[1010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
//	for(int i=0;i<=n;i++){for(int j=0;j<=n;j++)printf("%d ",C[i][j]);puts("");}
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	num[n+1]=1;
	for(int i=1;i<=n+1;i++){
		if(num[i]<=0)continue;
		f[i]=1;
		for(int j=i-1;j;j--)if(num[j]>0&&num[j]<=n)f[i]=(1ll*f[j]*C[i-j-1][num[j]]+f[i])%mod;
	}
//	for(int i=1;i<=n+1;i++)printf("%d ",f[i]);puts("");
	printf("%d\n",f[n+1]-1);
	return 0;
}