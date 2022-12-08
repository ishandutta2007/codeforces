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
const int N=1e5+5;
char a[N],b[N];
int n1,n2,f[N],g[N],p[N][26],q[N][26],ans,tmp[4];
inline int binary1(int x,int y,int z)
{
	if(x>n1||p[n1][z]-p[x-1][z]<=0)return n1+1;
	int l=x,r=y;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(p[mid][z]-p[x-1][z]>0)r=mid;
		else l=mid+1;
	}
	return r;
}
inline int binary2(int x,int y,int z)
{
	if(y<1||q[1][z]-q[y+1][z]<=0)return 0;
	int l=x,r=y;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(q[mid][z]-q[y+1][z]>0)l=mid;
		else r=mid-1;
	}
	return l;
}
inline int binary3(int x,int y,int z)
{
	if(x>y||g[n2]<=z)return 0;
	int l=x,r=y;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(g[mid]<=z)l=mid+1;
		else r=mid;
	}
	return r;
}
int main()
{
	scanf("%s%s",a+1,b+1);
	n1=strlen(a+1);n2=strlen(b+1);
	for(int i=1;i<=n1;i++)
	{
		for(int j=0;j<26;j++)p[i][j]+=p[i-1][j];
		p[i][a[i]-'a']++;
	}
	for(int i=n1;i>=1;i--)
	{
		for(int j=0;j<26;j++)q[i][j]+=q[i+1][j];
		q[i][a[i]-'a']++;
	}
	for(int i=1;i<=n2;i++)f[i]=binary1(f[i-1]+1,n1,b[i]-'a');
	g[n2+1]=n1+1;
	for(int i=n2;i>=1;i--)g[i]=binary2(1,g[i+1]-1,b[i]-'a');
	bool flag=false;
	if(f[1]<=n1||g[n2]>0)flag=true;
	if(!flag)return puts("-"),0;
	for(int i=1;i<=n2;i++)if(f[i]<=n1&&i>ans)ans=i,tmp[0]=1,tmp[1]=i;
	for(int i=1;i<=n2;i++)if(g[i]>0&&n2-i+1>ans)ans=n2-i+1,tmp[0]=i,tmp[1]=n2;
	for(int i=1;i<=n2;i++)
	{
		int j=binary3(i+1,n2,f[i]);
		if(j&&i+n2-j+1>ans)ans=i+n2-j+1,tmp[0]=1,tmp[1]=i,tmp[2]=j,tmp[3]=n2;
	}
	if(tmp[2]){for(int i=tmp[0];i<=tmp[1];i++)putchar(b[i]);for(int i=tmp[2];i<=tmp[3];i++)putchar(b[i]);}
	else for(int i=tmp[0];i<=tmp[1];i++)putchar(b[i]);
	return 0;
}