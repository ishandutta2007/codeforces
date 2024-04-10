#include<stdio.h>
int gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
int main()
{
	long long N,M,X,Y,A,B,G,x1,y1,x2,y2;
	scanf("%lld%lld%lld%lld%lld%lld",&N,&M,&X,&Y,&A,&B);
	G=gcd(A,B);
	A/=G,B/=G;
	if(N*B>M*A)G=M/B;
	else G=N/A;
	B*=G,A*=G;
	x1=X-(A+1)/2,x2=X+A/2;
	y1=Y-(B+1)/2,y2=Y+B/2;
	if(x1<0){
		G=0-x1;
		x1+=G,x2+=G;
	}
	if(y1<0){
		G=0-y1;
		y1+=G,y2+=G;
	}
	if(x2>N){
		G=N-x2;
		x1+=G,x2+=G;
	}
	if(y2>M){
		G=M-y2;
		y1+=G,y2+=G;
	}
	printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
}