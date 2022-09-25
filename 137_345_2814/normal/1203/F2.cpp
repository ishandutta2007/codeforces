#include<cstdio>
#include<algorithm>
using namespace std;
#define N 303
struct sth{int a,b;}s1[N],s2[N];
int dp[N][N],n,a,b,t1,t2,s,as;
bool cmp1(sth a,sth b){return a.a<b.a;}
bool cmp2(sth a,sth b){return a.a+a.b>b.a+b.b;}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(b>=0)s1[++t1]=(sth){a,b};
		else s2[++t2]=(sth){a,b};
	}
	sort(s1+1,s1+t1+1,cmp1);
	sort(s2+1,s2+t2+1,cmp2);
	for(int i=1;i<=t1;i++)if(s>=s1[i].a)as++,s+=s1[i].b;
	for(int i=0;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=-1e9;
	dp[0][0]=s;
	for(int i=1;i<=t2;i++)
	for(int j=0;j<=t2;j++)
	if(dp[i-1][j]>=s2[i].a)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+s2[i].b),dp[i][j]=max(dp[i][j],dp[i-1][j]);
	else dp[i][j]=max(dp[i][j],dp[i-1][j]);
	for(int j=t2;j>=0;j--)if(dp[t2][j]>=0){printf("%d\n",as+j);return 0;}
}//