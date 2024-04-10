#include<cstdio>
#define inf 0x3f3f3f3f
int n,m,ans=0;
int Anx[5005][26]={},Bnx[5005][26]={},dp[5005][5005]={};
char A[5005],B[5005];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	read(n),read(m),scanf("%s",A+1),scanf("%s",B+1);
	for(int i=n;i;--i)
	{
		for(int j=0;j<26;++j)Anx[i][j]=Anx[i+1][j];
		Anx[i][A[i]-'a']=i;
	}
	for(int i=n;i;--i)
	{
		for(int j=0;j<26;++j)Bnx[i][j]=Bnx[i+1][j];
		Bnx[i][B[i]-'a']=i;
	}
	for(int i=n+1;i;--i)dp[i][m+1]=-inf;
	for(int i=m+1;i;--i)dp[n+1][i]=-inf;
	for(int i=n;i;--i)
		for(int j=m;j;--j)
		{
			dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
			if(A[i]!=B[j])continue;
			dp[i][j]=max(dp[i][j],max(2-i-j,4+dp[i+1][j+1]));
			ans=max(ans,dp[i][j]+i+j);
		}
	printf("%d",ans);
	return 0;
}
/*
dp[i][j]=max(4+dp[i1][j1]-(i1-i)-(j1-j))
dp[i][j]-i-j=4+max(dp[i1][j1]-i1-j1)
*/