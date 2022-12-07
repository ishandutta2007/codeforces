#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=55;
const int MOD=1e9+7;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int n,m;
int g[N][N][N][4];
int h[N][N][N];
int JC[N];
void Init (int n)
{
	memset(g,0,sizeof(g));
	g[0][0][1][2]=1;g[0][1][0][1]=1;g[1][0][0][0]=1;
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	for (int u=0;u<=n;u++)
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n;j++) 
	for (int k=0;k<=2;k++)	if (g[u][i][j][k])
	{
		if (k!=0) g[u+1][i][j][0]=add(g[u+1][i][j][0],g[u][i][j][k]);
		if (k!=1) g[u][i+1][j][1]=add(g[u][i+1][j][1],g[u][i][j][k]);
		if (k!=2) g[u][i][j+1][2]=add(g[u][i][j+1][2],g[u][i][j][k]);
		int now=mul(mul(mul(JC[u],JC[i]),JC[j]),g[u][i][j][k]);
		//if (u==2&&i==1&&j==0) printf("%d %d\n",g[u][i][j][k],(mul(JC[u],JC[i]),JC[j]));
		h[u][i][j]=add(h[u][i][j],now);
	}
	//printf("%d\n",h[2][1][0]);
}
vector<int> vec[N];
int f[3][N][2505];
int sum[3];
int d[N][N][2505];
int main()
{
	Init(50);
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		int t,g;
		scanf("%d%d",&t,&g);
		sum[g-1]+=t;vec[g-1].push_back(t);
	}
	if (sum[0]>sum[2])	{swap(sum[0],sum[2]);swap(vec[0],vec[2]);}
	if (sum[1]>sum[2])	{swap(sum[1],sum[2]);swap(vec[1],vec[2]);}
	for (int u=0;u<=2;u++)
	{
		int siz=vec[u].size();
		f[u][0][0]=1;
		for (int i=0;i<siz;i++)
		for (int j=i+1;j>=1;j--)
		for (int k=sum[u];k>=vec[u][i];k--)
		f[u][j][k]=add(f[u][j][k],f[u][j-1][k-vec[u][i]]);
	}
	for (int u=0;u<=vec[0].size();u++)
	for (int j=0;j<=sum[0];j++) if (f[0][u][j])
	for (int i=0;i<=vec[1].size();i++)
	for (int k=0;k<=sum[1];k++) if (f[1][i][k])
	d[u][i][j+k]=add(d[u][i][j+k],mul(f[0][u][j],f[1][i][k]));
	int ans=0;
	for (int u=0;u<=vec[2].size();u++)
	for (int i=0;i<=sum[2];i++) if (f[2][u][i])
	{
		int t=m-i;
		for (int j=0;j<=vec[0].size();j++)
		for (int k=0;k<=vec[1].size();k++)
		{
		//	if (d[j][k][t]) printf("%d %d %d %d\n",u,j,k,h[u][j][k]);
			ans=add(ans,mul(h[u][j][k],(mul(d[j][k][t],f[2][u][i]))));
		}
	}
	printf("%d\n",ans);
	return 0;
}