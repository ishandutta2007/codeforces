#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
inline void read(int&n)
{int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();n=x*f;}
int writingarray[20];
inline void write(int k)
{int num=0;if(k<0)putchar('-'),k=-k;if(!k)writingarray[++num]=0;while(k)writingarray[++num]=k%10,k/=10;while(num)putchar(writingarray[num--]+'0');puts("");}
/*----------------------------------------------------------------yf's header file---------------------------------------------------------------------------*/
const int maxn=100001;
int n,f[maxn],w[maxn],fa[maxn][40],son[maxn][40],g[maxn][40];
long long sum[maxn][40];
long long k;
inline int lg2(long long k)
{
	int i=0;
	long long s=1;
	while(s<=k)s*=2,i++;
	return i; 
}
inline long long left(int p)
{
	long long s=1;
	for(int i=1;i<=p;i++)s*=2;
	return s;
}
inline long long querysum(int w,long long k)
{
	int p=lg2(k),now=w;
	long long ans=0,cnt=0;
	for(int i=p;i>=0;i--)if(cnt+left(i)<=k)
	{
		cnt+=left(i);
		ans+=sum[now][i];
		now=fa[now][i];
	}
	return ans;
}
inline int querymin(int w,long long k)
{
	int p=lg2(k),now=w,ans=2e9;;
	long long cnt=0;
	for(int i=p;i>=0;i--)if(cnt+left(i)<=k)
	{
		cnt+=left(i);
		ans=min(ans,g[now][i]);
		now=fa[now][i];
	}
	return ans;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)read(f[i]),f[i]++;
	for(int i=1;i<=n;i++)read(w[i]);
	int p=lg2(k);
	for(int i=1;i<=n;i++)fa[i][0]=f[i];
	for(int j=1;j<=p;j++)
		for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=n;i++)g[i][0]=w[i];
	for(int j=1;j<=p;j++)
		for(int i=1;i<=n;i++)g[i][j]=min(g[i][j-1],g[fa[i][j-1]][j-1]);
	for(int i=1;i<=n;i++)sum[i][0]=w[i];
	for(int j=1;j<=p;j++)
		for(int i=1;i<=n;i++)sum[i][j]=sum[i][j-1]+sum[fa[i][j-1]][j-1];
	for(int i=1;i<=n;i++)printf("%lld %d\n",querysum(i,k),querymin(i,k));
	return 0;
}