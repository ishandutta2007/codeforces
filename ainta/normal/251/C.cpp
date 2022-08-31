#include<stdio.h>
__int64 n,m,Res,A,B,L;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
bool o[360360][15];
int i,j,t,tp,D[360362],O,D2[360362];
int main()
{
	scanf("%I64d%I64d%d",&m,&n,&t);
	L=1;
	for(i=2;i<=t;i++){
		tp=gcd(L,i);
		L=L*i/tp;
	}
	A=(n-1)/L+1,B=m/L;
	if(A>B){
		m%=L,n%=L;
		D[n]=0;
		for(i=n+1;i<=m;i++){
			D[i]=D[i-1]+1;
			for(j=2;j<=t;j++){
				if(i-i%j<n)continue;
				if(i%j>0&&D[i]>D[i-(i%j)]+1)D[i]=D[i-(i%j)]+1;
			}
		}
		printf("%d\n",D[m]);
		return 0;
	}
	for(i=0;i<L;i++){
		D[i]=i;
		D2[i]=L-i;
		for(j=2;j<=t;j++){
			o[i][i%j]=1;
		}
		o[i][1]=1;
		for(j=1;j<t&&j<=i;j++){
			if(o[i][j]&&D[i]>D[i-j]+1)D[i]=D[i-j]+1;
		}
	}
	for(i=L-1;i>=0;i--){
		for(j=1;j<t&&j<=i;j++){
			if(o[i][j]&&D2[i-j]>D2[i]+1)D2[i-j]=D2[i]+1;
		}
	}
	O=D[L-1]+1;
	Res=O*(B-A);
	Res+=D[m%L];
	Res+=D2[n-(A-1)*L];
	printf("%I64d\n",Res);
}