#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,num[510],f[510][510];
int main(){
	scanf("%d%d",&n,&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<=n+1;i++)for(int j=0;j<i;j++)f[i][j]=1;
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int l=2;l<=n;l++)for(int i=1,j=i+l-1;j<=n;i++,j++){
		int mp=i;
		for(int k=i;k<=j;k++)if(num[k]<=num[mp])mp=k;
		int A=0,B=0;
		for(int k=mp;k>=i;k--)(A+=(1ll*f[i][k-1]*f[k][mp-1]%mod))%=mod;
		for(int l=mp;l<=j;l++)(B+=(1ll*f[mp+1][l]*f[l+1][j]%mod))%=mod;
		f[i][j]=1ll*A*B%mod;
	}
	printf("%d\n",f[1][n]);
	return 0;
}