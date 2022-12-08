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
const int N=1e6+5;
struct node{int fa,trans[26],len,lst,r;}s[N<<1];
int last=1,tot=1,sum[N<<1],tmp[N<<1];
inline void extend(int x)
{
	int p=last,cur=last=++tot;
	s[cur].len=s[p].len+1;s[cur].r=1;
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
inline void top_sort()
{
	for(int i=1;i<=tot;i++)sum[s[i].len]++;
	for(int i=1;i<=tot;i++)sum[i]+=sum[i-1];
	for(int i=tot;i>=1;i--)tmp[sum[s[i].len]--]=i;
}
inline void work()
{
	top_sort();
	for(int i=tot;i>=1;i--)s[s[tmp[i]].fa].r+=s[tmp[i]].r;
}
char str[N];
int main()
{
	scanf("%s",str);int len=strlen(str);
	for(int i=0;i<len;i++)extend(str[i]-'a');
	work();
	int n;read(n);
	for(int k=1;k<=n;k++)
	{
		scanf("%s",str);int len=strlen(str),p=1,cnt=0;
		long long ans=0;
		for(int i=0;i<len;i++)if(s[p].trans[str[i]-'a'])p=s[p].trans[str[i]-'a'],cnt++;
		else{while(p&&!s[p].trans[str[i]-'a'])p=s[p].fa;if(!p)p=1,cnt=0;else cnt=s[p].len+1,p=s[p].trans[str[i]-'a'];}
		while(s[p].fa&&s[s[p].fa].len>=len)p=s[p].fa,cnt=s[p].len;
		if(cnt>=len&&s[p].lst!=k)s[p].lst=k,ans+=s[p].r;
		for(int i=0;i<len-1;i++)
		{
			if(s[p].trans[str[i]-'a'])p=s[p].trans[str[i]-'a'],cnt++;
			else{while(p&&!s[p].trans[str[i]-'a'])p=s[p].fa;if(!p)p=1,cnt=0;else cnt=s[p].len+1,p=s[p].trans[str[i]-'a'];}
			while(s[p].fa&&s[s[p].fa].len>=len)p=s[p].fa,cnt=s[p].len;
			if(cnt>=len&&s[p].lst!=k)s[p].lst=k,ans+=s[p].r;
		}
		printf("%lld\n",ans);
	}
	return 0;
}