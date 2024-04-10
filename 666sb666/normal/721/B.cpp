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
struct S
{
	char s[150];
	int len,have;
}a[150];
inline bool cmp(S a,S b)
{
	return a.len<b.len;
}
char s[150];
inline bool same(int i,int j)
{
	if(a[i].len!=a[j].len)return false;
	int len=min(a[i].len,a[j].len);
	for(int k=1;k<=len;k++)if(a[i].s[k]!=a[j].s[k])return false;
	return true;
}
int main()
{
	int n,k,len,ans=0,num=0;
	read(n),read(k);
	for(int i=1;i<=n;i++)scanf("%s",a[i].s+1),a[i].len=strlen(a[i].s+1);
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<i;j++)if(same(i,j))flag=false;
		if(flag)a[i].have=1;
		else a[i].have=0;
	}
	scanf("%s",s+1);
	len=strlen(s+1);
	int tot=0;
	for(int i=1;i<=n;i++)if(a[i].have&&a[i].len==len)tot++;
	sort(a+1,a+n+1,cmp);
	int p=1;
	while(a[p].len<len&&p<=n)
	{
		if(a[p].have)
		{
			ans++;
			num++;
			if(num>=k)num-=k,ans+=5;
		}
		p++;
	}
	printf("%d ",ans+1);
	write(ans+(num+tot-1)/k*5+tot);
	return 0;
}