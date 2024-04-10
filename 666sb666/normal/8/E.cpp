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
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const int N=51;
int n,a[N];
long long f[N][N][2][2],k;
bool vis[N][N][2][2];
long long work(int l,int r,int rev,int inv)
{
	if(l>r)return 1;
	if(vis[l][r][rev][inv])return f[l][r][rev][inv];
	vis[l][r][rev][inv]=1;
	long long&ans=f[l][r][rev][inv];
	ans=0;
	for(int i=0;i<2;i++)if(a[l]==-1||a[l]==i)
		for(int j=0;j<2;j++)if(a[r]==-1||a[r]==j)
		if((l<r||i==j)&&(rev||i<=j)&&(inv||i<=1-j))ans+=work(l+1,r-1,i<j||rev,i<1-j||inv);
	return ans;
}
int main()
{
	read(n),scanf("%lld",&k);
	memset(a,-1,sizeof(a));
	a[0]=0;
	if(work(0,n-1,0,0)<=k)return puts("-1"),0;
	for(int i=1;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		a[i]=0;
		long long tmp=work(0,n-1,0,0);
		if(tmp<=k)k-=tmp,a[i]=1;
	}
	for(int i=0;i<n;i++)printf("%d",a[i]);
	return 0;
}