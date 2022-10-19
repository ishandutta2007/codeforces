#include<cstdio>
#define Mx 55
#define LL long long
int n;LL x,m,res=0;LL pw[56];
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline LL solve(LL x)
{
	LL res=((x&3)==1 || (x&3)==2),y;
	for(int i=1;i<Mx;++i)res^=((max((x%pw[i+1])-pw[i]+1,0)&1)*pw[i]);
	return res;
}
int main()
{
	scanf("%d",&n),pw[0]=1;for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&x,&m),res^=(solve(x-1)^solve(x+m-1));
	return 0&puts(res? "tolik":"bolik");
}