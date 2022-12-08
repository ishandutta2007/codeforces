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
const int N=5005;
struct SAM
{
	struct node{int len,fa,r,trans[26];}sam[N<<1];
	int tot,lst,sum[N<<1],tmp[N<<1];
	inline void init(){tot=lst=1;}
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
}A,B;
char a[N],b[N];
int n,m,ans=2e9;
int main()
{
	scanf("%s%s",a,b);
	n=strlen(a);m=strlen(b);A.init();B.init();
	for(int i=0;i<n;i++)A.extend(a[i]-'a');
	for(int i=0;i<m;i++)B.extend(b[i]-'a');
	A.top_sort();B.top_sort();
	for(int i=0;i<n;i++)
	{
		int pos=i,p=1,q=1,flag=1;
		while((pos<n&&(A.sam[p].r>1||B.sam[q].r>1))||pos==i)
		{
			if(!B.sam[q].trans[a[pos]-'a']){flag=0;break;}
			p=A.sam[p].trans[a[pos]-'a'],q=B.sam[q].trans[a[pos]-'a'],pos++;
		}
		if(flag&&A.sam[p].r==1&&B.sam[q].r==1)ans=min(ans,pos-i);
	}
	if(ans<2e9)write(ans);else puts("-1");
	return 0;
}