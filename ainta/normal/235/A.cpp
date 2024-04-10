#include<stdio.h>
__int64 n,i,j,k,R,t;
__int64 gcd(__int64 a,__int64 b){
	return b?gcd(b,a%b):a;}
int main()
{
	scanf("%I64d",&n);
	if(n<3){printf("%I64d\n",n);return 0;}
	if(n&1){
		printf("%I64d\n",n*(n-1)*(n-2));
		return 0;
	}
	if(n<=30){
		for(i=n;i>=1;i--){
			for(j=i-1;j>=1;j--){
				for(k=j-1;k>=1;k--){
					t=gcd(i,j);
					if(R<i*j*k/t/gcd(i*j/t,k))R=i*j*k/t/gcd(i*j/t,k);
				}
			}
		}
		printf("%I64d\n",R);
		return 0;
	}
	for(i=n-1;i>=1;i--){
		for(j=i-1;j>=1;j--){
			if(i*j*n<(n-1)*(n-2)*(n-3))break;
			t=gcd(i,j);
			t=i*j*n/t/gcd(i*j/t,n);
			if(R<t)R=t;
		}
	}
	if(R<(n-1)*(n-2)*(n-3))R=(n-1)*(n-2)*(n-3);
	printf("%I64d\n",R);
}