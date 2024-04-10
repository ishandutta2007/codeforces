#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int k,pa,pb,A,B,C;
LL f[1002][1002];
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline LL calc(int a,int b)
{
	if(a+b>=k)return (a+b+C)%mod;
	if(~f[a][b])return f[a][b];
	return f[a][b]=(A*calc(a+1,b)+B*calc(a,a+b))%mod;
}
int main()
{
	scanf("%d%d%d",&k,&pa,&pb),A=(pa*Pow(pa+pb,mod-2))%mod,B=(pb*Pow(pa+pb,mod-2))%mod,C=((1-B+mod)*Pow(B,mod-2))%mod;
	for(int i=0;i<=k;++i)for(int j=0;j<=k;++j)f[i][j]=-1;
	return 0&printf("%lld",calc(1,0));
}