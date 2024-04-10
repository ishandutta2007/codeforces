#include<stdio.h>
int i,K,j,k,l;
__int64 D[101][10001],Mod=1000000007,C[101][101],m,x,y,n,T;
__int64 P(__int64 a,__int64 b){
	x=1,y=a;
	while(b){
		if(b&1){
			x*=y;x%=Mod;
		}
		b/=2;
		y=y*y;y%=Mod;
	}
	return x;
}
int main()
{
	C[0][0]=1;
	for(i=1;i<=100;i++){
		C[i][0]=1;
		for(j=1;j<=100;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>Mod)C[i][j]-=Mod;
		}
	}
	scanf("%I64d%I64d%d",&n,&m,&K);
	D[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=n&&j<=K;j++){
			T=P(C[n][j],(m-i)/n+1);
			for(k=0;k<=K-j&&k<=n*(i-1);k++){
				D[i][j+k]+=D[i-1][k]*T;
				D[i][j+k]%=Mod;
			}
		}
	}
	printf("%I64d\n",D[n][K]);
}