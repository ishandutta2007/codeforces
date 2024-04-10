#include<cstdio>
#define LL long long
int Test_num,n;
LL u,v,t,fz,fm;
inline bool check(int x)
{
	for(int i=2;i*i<=x;++i)
		if(!(x%i))return 0;
	return 1;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("0");
			continue;
		}
		for(int i=n;;--i)
			if(check(i))
			{
				u=i;
				break;
			}
		for(int i=n+1;;++i)
			if(check(i))
			{
				v=i;
				break;
			}
		t=gcd(fz=u*v-2*v+2*n-2*u+2,fm=2*u*v),fz/=t,fm/=t,printf("%lld",fz);
		if(fm>1)printf("/%lld",fm);puts("");
	}
	return 0;
}