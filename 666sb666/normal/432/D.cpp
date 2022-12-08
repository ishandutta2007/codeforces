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
#define rank _rank
const int N=1e5+5;
struct node{int len,fa,r,trans[26];}sam[N<<1];
int lst=1,tot=1,sum[N<<1],tmp[N<<1];
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
			sam[cur].fa=sam[q].fa=r;
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
int sa[N],rank[N],height[N],st[N][20],n;
char s[N];
inline void build_sa()
{
	int m=26,p=0;
	for(int i=1;i<=m;i++)sum[i]=0;
	for(int i=1;i<=n;i++)sum[rank[i]=s[i]-'A'+1]++;
	for(int i=1;i<=m;i++)sum[i]+=sum[i-1];
	for(int i=n;i>=1;i--)sa[sum[rank[i]]--]=i;
	for(int j=1;p<n;j<<=1,m=p)
	{
		p=1;
		for(int i=n;i>=n-j+1;i--)tmp[p++]=i;
		for(int i=1;i<=n;i++)if(sa[i]>j)tmp[p++]=sa[i]-j;
		for(int i=1;i<=m;i++)sum[i]=0;
		for(int i=1;i<=n;i++)sum[rank[tmp[i]]]++;
		for(int i=1;i<=m;i++)sum[i]+=sum[i-1];
		for(int i=n;i>=1;i--)sa[sum[rank[tmp[i]]]--]=tmp[i];
		for(int i=1;i<=n;i++)swap(rank[i],tmp[i]);
		p=1;
		rank[sa[1]]=1;
		for(int i=2;i<=n;i++)rank[sa[i]]=(tmp[sa[i-1]]==tmp[sa[i]]&&tmp[sa[i-1]+j]==tmp[sa[i]+j])?p:++p;
	}
}
inline void get_height()
{
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(k)k--;
		int j=sa[rank[i]-1];
		while(s[i+k]==s[j+k])k++;
		height[rank[i]]=k;
	}
}
inline int query(int l,int r)
{
	int k=log2(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int cnt;
pair<int,int>ans[N];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)extend(s[i]-'A');
	top_sort();
	build_sa();
	get_height();
	for(int i=1;i<=n;i++)st[i][0]=height[i];
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)if(i+(1<<j)-1<=n)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int p=1;
	for(int i=1;i<n;i++)
	{
		if(sam[p].trans[s[i]-'A'])p=sam[p].trans[s[i]-'A'];
		else{while(p&&!sam[p].trans[s[i]-'A'])p=sam[p].fa;if(!p)p=1;else p=sam[p].trans[s[i]-'A'];}
		if(query(min(rank[1],rank[n-i+1])+1,max(rank[1],rank[n-i+1]))==i)ans[++cnt]=make_pair(i,sam[p].r);
	}
	ans[++cnt]=make_pair(n,1);
	write(cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}