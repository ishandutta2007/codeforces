#include<stdio.h>
int n,K,w[2001],i,j;
__int64 O[2001],M=1000000007,P,t,x,R,S;
int main()
{
	P=M-2;
	scanf("%d%d",&n,&K);
	for(i=0;i<n;i++)scanf("%d",&w[i]);
	O[0]=1;
	for(i=1;i<=n-1;i++){
		t=P,R=1,x=i;
		while(t){
			if(t&1)R=(R*x)%M;
			t/=2;
			x=(x*x)%M;}
		O[i]=O[i-1];
		O[i]=(O[i]*(i+K-1))%M;
		O[i]=(O[i]*R)%M;}
	for(i=0;i<n;i++){
		S=0;
		for(j=0;j<=i;j++){
			t=w[j];
			t=(t*O[i-j])%M;
			S+=t;
		}
		S%=M;
		printf("%I64d ",S);
	}
}