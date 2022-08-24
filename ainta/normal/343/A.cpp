#include<stdio.h>
long long a,b,Res,t;
int main()
{
	scanf("%lld%lld",&a,&b);
	while(1){
		Res+=a/b;
		a=a%b;
		if(a==0)break;
		t=a;
		a=b;
		b=t;
	}
	printf("%lld\n",Res);
}