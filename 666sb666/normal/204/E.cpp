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
struct node
{
	int len,fa,trans[26],cnt,lst;
	long long res;
}s[N<<1];
int tot=1,last=1;
inline void extend(int x)
{
	int p=last,cur=last=++tot;
	s[cur].len=s[p].len+1;
	while(p&&!s[p].trans[x])s[p].trans[x]=cur,p=s[p].fa;
	if(!p)s[cur].fa=1;
	else
	{
		int q=s[p].trans[x];
		if(s[p].len+1==s[q].len)s[cur].fa=q;
		else
		{
			int r=++tot;
			s[r].len=s[p].len+1;
			memcpy(s[r].trans,s[q].trans,sizeof(s[q].trans));
			s[r].fa=s[q].fa;
			s[cur].fa=s[q].fa=r;
			while(p&&s[p].trans[x]==q)s[p].trans[x]=r,p=s[p].fa;
		}
	}
}
int n,k,sum[N<<1],tmp[N<<1];
string str[N];
inline void top_sort()
{
	for(int i=1;i<=tot;i++)sum[s[i].len]++;
	for(int i=1;i<=tot;i++)sum[i]+=sum[i-1];
	for(int i=tot;i>=1;i--)tmp[sum[s[i].len]--]=i;
}
inline void work()
{
	for(int i=1;i<=n;i++)
	{
		int now=1;
		for(int j=0;j<str[i].size();j++)
		{
			now=s[now].trans[str[i][j]-'a'];
			for(int p=now;p&&s[p].lst!=i;p=s[p].fa)s[p].cnt++,s[p].lst=i;
		}
	}
	top_sort();
	for(int i=1;i<=tot;i++)
	{
		s[tmp[i]].res=s[s[tmp[i]].fa].res;
		if(s[tmp[i]].cnt>=k)s[tmp[i]].res+=s[tmp[i]].len-s[s[tmp[i]].fa].len;
	}
	for(int i=1;i<=n;i++)
	{
		int now=1;
		long long ans=0;
		for(int j=0;j<str[i].size();j++)
		{
			now=s[now].trans[str[i][j]-'a'];
			ans+=s[now].res;
		}
		printf("%lld ",ans);
	}
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		last=1;
		for(int j=0;j<str[i].size();j++)extend(str[i][j]-'a');
	}
	work();
	return 0;
}