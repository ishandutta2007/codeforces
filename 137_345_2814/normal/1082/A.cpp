#include<cstdio>
using namespace std;
long long T,a,b,c,d;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if((b-c)%d==0)
		{
			long long tmp=(b-c)/d;
			if(tmp<0)tmp=-tmp;
			printf("%lld\n",tmp);
		}
		else
		{
			long long tmp1=1e11,tmp2=1e11;
			if((c-1)%d==0)
			tmp1=(c-1)/d+(b-2)/d+1;
			if((a-c)%d==0)
			tmp2=(a-c)/d+(a-b-1)/d+1;
			if(tmp1>tmp2)tmp1=tmp2;
			if(tmp1>1e10)
			printf("-1\n");
			else
			printf("%lld\n",tmp1);
		}
	}
}