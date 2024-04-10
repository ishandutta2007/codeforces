//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int mod=1e6+3;
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
const int N=2e3+9;
int n,k,ans,res;
int x[N],y[N],inv[N][N],h[N];
inline int query(int u)
{
	int x;
	printf("? %d\n",u);fflush(stdout);
	cin>>x;return x;
}
signed main()
{
	n=11;
	for(int i=0;i<n;i++)
	{
		x[i]=i,y[i]=query(i);
		if(y[i]==0)
		{
			printf("! %d\n",i);return 0;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			inv[i][j]=Pow(x[i]-x[j],mod-2)%mod;
	for(int i=0;i<n;i++)
	{
		h[i]=1;
		for(int j=0;j<n;j++)
			if(i!=j)h[i]=h[i]*inv[i][j]%mod;
	}
	for(int k=n;k<mod;k++)
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			res=h[i];
			for(int j=0;j<n;j++)
				if(i!=j)res=res*(k-x[j])%mod;
			res=res%mod;
			ans=(ans+res*y[i]%mod)%mod;
		}
		ans=(ans%mod+mod)%mod;
		if(ans==0)
		{
			printf("! %d\n",k);return 0;
		}
	}
	puts("! -1");
	return 0;
}