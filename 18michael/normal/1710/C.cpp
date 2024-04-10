#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,ans;
int dp[200002][2][2][2][2][2][2];
char s[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),dp[0][0][0][0][0][0][0]=1;
	for(int i=0;i<n;++i)
	{
		s[i+1]^=48;
		for(int j=0;j<2;++j)//a<b
		for(int k=0;k<2;++k)//b<c
		for(int l=0;l<2;++l)//a=b!=c
		for(int o=0;o<2;++o)//a=c!=b
		for(int q=0;q<2;++q)
		for(int p=0;p<2;++p)
		if(dp[i][j][k][l][o][q][p])
		{
			//if(dp[i][j][k][l][o][p])printf("dp[%d][%d][%d][%d][%d][%d]=%d\n",i,j,k,l,o,p,dp[i][j][k][l][o][p]);
			for(int c=0;c<(p? 2:s[i+1]+1);++c)
			for(int b=0;b<(k? 2:c+1);++b)
			for(int a=0;a<(j? 2:b+1);++a)
			{
			//printf("dp[%d][%d][%d][%d][%d][%d] -> dp[%d][%d][%d][%d][%d][%d] (a:%d b:%d c:%d)\n",
			//i,j,k,l,o,p,i+1,j|(a<b),k|(b<c),l|(b==c && b!=a),o|(a==c && a!=b),p|(c<s[i+1]),a,b,c);
			upd(dp[i+1][j|(a<b)][k|(b<c)][l|(b==c && b!=a)][o|(a==c && a!=b)][q|(a==b && a!=c)][p|(c<s[i+1])],
			dp[i][j][k][l][o][q][p]);
			}
		}
	}
	/*for(int i=0;i<=n;++i)
		for(int j=0;j<2;++j)//a<b
		for(int k=0;k<2;++k)//b<c
		for(int l=0;l<2;++l)//a=b!=c
		for(int o=0;o<2;++o)//a=c!=b
		for(int q=0;q<2;++q)//a=c!=b
		for(int p=0;p<2;++p)
			if(dp[i][j][k][l][o][q][p])printf("dp[%d][%d][%d][%d][%d][%d]=%d\n",i,j,k,l,o,q,p,dp[i][j][k][l][o][q][p]);*/
	ans=((dp[n][1][1][1][1][1][0]+dp[n][1][1][1][1][1][1])*6LL)%mod;
	return 0&printf("%d",ans);
}