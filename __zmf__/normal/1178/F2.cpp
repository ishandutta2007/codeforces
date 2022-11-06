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
const int mod=998244353;
int n,m,M,c[1000009],cc[1000009],L[509],R[509];
int l,r,dp[1009][1009],sum;
signed main()
{
	n=read(),M=read();
	for(int i=1;i<=M;i++)cc[i]=read();
	for(int i=1;i<=M;i++)if(cc[i]!=c[m])c[++m]=cc[i];
	if(m>2*n)
	{
		puts("0");return 0;
	}
	for(int i=1;i<=m;i++)L[i]=998244353;
	for(int i=1;i<=m;i++)L[c[i]]=min(L[c[i]],i),R[c[i]]=max(R[c[i]],i);
	for(int i=1;i<=m+1;i++)dp[i][i-1]=1;
	for(int i=1;i<=m;i++)
		if(L[c[i]]==R[c[i]])dp[i][i]=1;
	for(int len=2;len<=m;len++)
		for(int i=1;i+len-1<=m;i++)
		{
			int j=i+len-1;
			int Min=1e9+7,p=i;sum=0;
			for(int k=i;k<=j;k++)
				if(Min>c[k])Min=c[k],p=k;
			l=L[Min],r=R[Min];
			if(l<i||r>j)continue;
			for(int k=i;k<=l;k++)sum=sum+dp[i][k-1]*dp[k][l-1]%mod;sum=sum%mod;
			for(int k=r;k<=j;k++)dp[i][j]=(dp[i][j]+sum*dp[r+1][k]%mod*dp[k+1][j]%mod)%mod;
			p=0;
			for(int k=l;k<=r;k++)
				if(c[k]==Min)
				{
					if(p)dp[i][j]=dp[i][j]*dp[p+1][k-1]%mod;
					p=k;
				}
		}
	cout<<dp[1][m]<<endl;
	return 0;
}