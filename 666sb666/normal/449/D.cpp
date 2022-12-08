#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e6+1,mod=1e9+7;
int n,a[N],c[N],pw[N],f[N][20],ans;
inline void update(int&x,int y){x=(x+y)%mod;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);a[x]++;}
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=(pw[i-1]<<1)%mod;
	for(int S=M;S>=0;S--)
	{
		for(int i=0;i<20;i++)
		{
			if(i)f[S][i]=f[S][i-1];
			if(!(S&(1<<i))&&(S^(1<<i))<=M)update(f[S][i],f[S^(1<<i)][i]);
		}
		int tmp=f[S][19];
		for(int i=0;i<20;i++)update(f[S][i],a[S]);
		update(a[S],tmp);
	}
	c[0]=0;ans=pw[a[0]];
	for(int S=1;S<=M;S++)
	{
		c[S]=c[S^(S&-S)]^1;
		if(c[S])update(ans,mod-pw[a[S]]);
		else update(ans,pw[a[S]]);
	}
	printf("%d\n",ans);
	return 0;
}