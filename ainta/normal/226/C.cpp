#include<stdio.h>
__int64 m,l,r,k,P,a,b,c,d,e,f,t,T,i;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&m,&l,&r,&k);l--;
	while(a*a<r)a++;
	for(i=1;i<=a;i++){t=r/i;if(r/t-l/t>=k&&P<t)P=t;}
	for(i=1;i<=a;i++){t=i;if(r/t-l/t>=k&&P<t)P=t;}
	a=0,b=1,c=1,d=0,e=1;f=1;
	while(P){
		if(P&1){t=b;c=b*e+c*f;b=a*e+b*f;a=a*d+t*e;a%=m,b%=m,c%=m;}
		t=d,T=e;d=d*d+e*e;e=t*e+e*f;f=T*T+f*f;
		d%=m,e%=m,f%=m;
		P/=2;
	}
	printf("%I64d\n",a);
}