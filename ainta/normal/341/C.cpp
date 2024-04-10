#include<stdio.h>
long long D[2001][2001],Mod=1000000007;
int n,in[2001],out[2001];
int main()
{
	int i,j,a,C1=0,C2=0;
	scanf("%d",&n);
	D[1][0]=0,D[2][0]=1;
	for(i=3;i<=n;i++){
		D[i][0]=(long long)(i-1)*(D[i-1][0]+D[i-2][0])%Mod;
	}
	D[0][1]=1;
	for(i=2;i<=n;i++){
		D[0][i]=D[0][i-1]*i%Mod;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			D[i][j]=(D[i-1][j]*i+D[i][j-1]*j)%Mod;
		}
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a==-1)continue;
		out[i]=1;
		in[a]=1;
	}
	for(i=1;i<=n;i++){
		if(!in[i] && !out[i]){
			C1++;
		}
		if(in[i]&&!out[i]){
			C2++;
		}
	}
	printf("%lld\n",D[C1][C2]);
	return 0;
}