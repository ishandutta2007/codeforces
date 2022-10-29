#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1100005,md=1000000007;
int n,i,j,k,f[N],ans;
inline int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
inline void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
int main()
{
	Read(n);
	for(i=1;i<=n;++i)
	{
		Read(j);
		++f[j];
	}
	for(i=0;i<20;++i)
		for(j=0;j<(1<<20);++j)
			if(!((1<<i)&j))
				f[j]=(f[j]+f[j|(1<<i)])%(md-1);
	for(i=0;i<(1<<20);++i)
	{
		for(j=k=0;j<20;++j)
			if((1<<j)&i)
				++k;
		ans=(ans+1ll*pw(2,f[i])*(k&1?md-1:1)%md)%md;
	}
	printf("%d",ans);
	return 0;
}