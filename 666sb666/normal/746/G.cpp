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
const int N=2e5+5;
int n,t,k,a[N],tmp=0,now;
vector<int>v[N];
int main()
{
	read(n),read(t),read(k);
	for(int i=1;i<=t;i++)read(a[i]);
	for(int i=1;i<=t;i++)if(a[i]>a[i+1])tmp+=a[i]-a[i+1];
	if(tmp>k)
	{
		puts("-1");
		return 0;
	}
	tmp=k-tmp;
	for(int i=2;i<=a[1]+1;i++)v[1].push_back(i);
	now=1;
	for(int i=1;i<t;i++)
	{
		int q=now+a[i],yu=a[i]-a[i+1];
		if(yu<0)yu=0;
		if(a[i]-1-yu<=tmp)
		{
			for(int j=q+1;j<=q+a[i+1];j++)v[now+1].push_back(j);
			now=q;
			tmp-=a[i]-1-yu;
			continue;
		}
		for(int j=1;j<=a[i]-yu-tmp;j++)v[j+now].push_back(j+q);
		for(int j=a[i]-yu-tmp+1;j<=a[i+1];j++)v[now+1].push_back(j+q);
		tmp=0;
		now+=a[i];
	}
	if(tmp)return puts("-1"),0;
	write(n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++)printf("%d %d\n",i,v[i][j]);
	return 0;
}