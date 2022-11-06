//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e6+9,mod=998244353;
int n,tot[N];
inline int Pow(int x,int y)
{
	int res=1,base=x;
	while(y)
	{
		if(y&1)res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
int pr[N],cnt,vis[N*2];
inline void init()
{
	for(int i=2;i<=N-9;i++)
		if(!vis[i])
		{
			vis[i]=1;pr[++cnt]=i;
			for(int j=i;j<=N/i;j++)
				if(i*j<=N)vis[i*j]=1;
		}
	for(int i=2;i<=N-9;i++)
	{
		int now=1,nowcnt=0,qwq=i;
		for(int j=1;j<=cnt&&pr[j]*pr[j]<=qwq;j++)
			if(qwq%pr[j]==0)
			{
				nowcnt=1;
				while(qwq%pr[j]==0)nowcnt++,qwq/=pr[j];
				now=(now*nowcnt)%mod;
			}
		if(qwq!=1)now=(now*2)%mod;
		tot[i]=now;
	}
}
int dp[N],sum;
signed main()
{
	tot[1]=1;
	n=read();init();
	for(int i=1;i<=n;i++)
	{
		dp[i]=(sum+tot[i])%mod;
		sum=(sum+dp[i])%mod;
	}
	cout<<dp[n]<<endl;
	return 0;
}