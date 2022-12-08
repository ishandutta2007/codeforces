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
const int maxn=200;
int n,a[maxn];
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(ch!='W'&&ch!='B')ch=getchar();
		if(ch=='B')a[i]=1;
	}
	bool flag=false;
	for(int i=1;i<=n;i++)if(a[i])flag=true;
	if(!flag)
	{
		puts("0");
		return 0;
	}
	int tot=0;
	int p=1;
	while(p<=n&&a[p]==0)p++;
	while(p<=n)
	{
		int q=p;
		while(a[q+1]==1&&q<=n)q++;
		tot++;
		p=q+1;
		while(p<=n&&a[p]==0)p++;
	}
	write(tot);
	p=1;
	while(p<=n&&a[p]==0)p++;
	while(p<=n)
	{
		int q=p;
		while(a[q+1]==1&&q<=n)q++;
		printf("%d ",q-p+1);
		p=q+1;
		while(p<=n&&a[p]==0)p++;
	}
	return 0;
}