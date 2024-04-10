#include<bits/stdc++.h>
#define Mx 20000000
#define LL long long
using namespace std;
int Test_num,c,d,x,sq,p_t=0;LL ans;
int n[20000002],mn[20000002]={},p[20000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!mn[i])p[++p_t]=i,mn[i]=i,n[i]=1;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)mn[p[j]*i]=p[j],n[p[j]*i]=n[i]+(mn[p[j]*i]!=mn[i]);
	}
	read(Test_num);
	while(Test_num--)
	{
		read(c),read(d),read(x),sq=sqrt(x),ans=0;
		for(int i=1;i<=sq;++i)
			if(!(x%i))
			{
				if(!((x/i+d)%c))ans+=(1LL<<(n[(x/i+d)/c]));
				if(i!=x/i && !((i+d)%c))ans+=(1LL<<(n[(i+d)/c]));
			}
		printf("%lld\n",ans);
	}
	return 0;
}