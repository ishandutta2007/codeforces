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
struct node{int fa,len,r,trans[26];}sam[N<<1];
int n,k,tot=1,lst=1,sum[N<<1],tmp[N<<1],num[N<<1],vis[N<<1];
char s[N];
inline void extend(int x)
{
	int p=lst,cur=lst=++tot;
	sam[cur].len=sam[p].len+1;sam[cur].r=1;
	while(p&&!sam[p].trans[x])sam[p].trans[x]=cur,p=sam[p].fa;
	if(!p)sam[cur].fa=1;
	else
	{
		int q=sam[p].trans[x];
		if(sam[q].len==sam[p].len+1)sam[cur].fa=q;
		else
		{
			int r=++tot;
			sam[r].len=sam[p].len+1;
			memcpy(sam[r].trans,sam[q].trans,sizeof(sam[q].trans));
			sam[r].fa=sam[q].fa;
			sam[q].fa=sam[cur].fa=r;
			while(p&&sam[p].trans[x]==q)sam[p].trans[x]=r,p=sam[p].fa;
		}
	}
}
inline void top_sort()
{
	for(int i=1;i<=tot;i++)sum[sam[i].len]++;
	for(int i=1;i<=tot;i++)sum[i]+=sum[i-1];
	for(int i=tot;i>=1;i--)tmp[sum[sam[i].len]--]=i;
	for(int i=tot;i>=1;i--)sam[sam[tmp[i]].fa].r+=sam[tmp[i]].r;
}
void dfs(int u)
{
	vis[u]=1;if(u==1)num[u]=0;else num[u]=sam[u].r;if(num[u]>k)num[u]=k+1;
	for(int x=0;x<26;x++)if(sam[u].trans[x])
	{
		if(!vis[sam[u].trans[x]])dfs(sam[u].trans[x]);
		num[u]+=num[sam[u].trans[x]];if(num[u]>k)num[u]=k+1;
	}
}
void getans(int u,int k)
{
	if(u!=1&&k<=sam[u].r)return;
	int tmp=sam[u].r;if(u==1)tmp=0;
	for(int x=0;x<26;x++)if(sam[u].trans[x])
	{
		if(tmp+num[sam[u].trans[x]]>=k){putchar('a'+x);getans(sam[u].trans[x],k-tmp);return;}
		tmp+=num[sam[u].trans[x]];
	}
}
int main()
{
	scanf("%s",s);n=strlen(s);
	read(k);
	for(int i=0;i<n;i++)extend(s[i]-'a');
	top_sort();
	dfs(1);
	if(k>num[1])return puts("No such line."),0;
	getans(1,k);
	return 0;
}