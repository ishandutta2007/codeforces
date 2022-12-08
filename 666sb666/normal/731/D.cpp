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
const int maxn=1000005;
vector<int>a[maxn];
int n,c,l[maxn],f[maxn];
int main()
{
	read(n),read(c);
	for(int i=1;i<=n;i++)
	{
		read(l[i]);
		for(int j=1;j<=l[i];j++)
		{
			int x;
			read(x);
			a[i].push_back(x);
		}
	}
	for(int i=1;i<n;i++)
	{
		int now=0,len=min(l[i],l[i+1]);
		while(now<len&&a[i][now]==a[i+1][now])now++;
		if(now>=len)
		{
			if(l[i]<=l[i+1])f[0]++,f[c]--;
			continue;
		}
		int x=a[i][now],y=a[i+1][now];
		if(x>y)
		{
			int t=c-x+1;
			x=1,y=y+t;
			if(y>c)y-=c;
			int t2=c-y;
			f[t]++,f[t+t2+1]--;
		}
		else if(x<y)
		{
			int t=c-y+1,last=x;
			f[0]++,f[t]--;
			x+=t;
			if(x>c)x-=c;
			y=1;
			int t2=c-x+1;
			x=1,y+=t2;
			if(y>c)y-=c;
			if(x>=last)continue;
			int t3=last-x;
			f[t+t2]++,f[t+t2+t3]--;
		}
	}
	for(int i=1;i<c;i++)f[i]+=f[i-1];
	for(int i=0;i<c;i++)if(f[i]==n-1)
	{
		write(i);
		return 0;
	}
	puts("-1");
	return 0;
}