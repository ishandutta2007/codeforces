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
const int maxn=1000001;
int n,m,a[maxn],nxt[maxn],s[maxn<<2],pre[maxn],ans[maxn]; 
struct A
{
	int l,r,id;
	bool operator <(const A&b)const
	{
		return r<b.r;
	}
}q[maxn];
map<int,int>p;
void cover(int u,int l,int r,int left,int right,int c)
{
	if(l>=left&&r<=right)
	{
		s[u]^=c;
		return;
	}
	int mid=(l+r)>>1;
	if(left<=mid)cover(u<<1,l,mid,left,right,c);
	if(right>mid)cover(u<<1|1,mid+1,r,left,right,c);
}
int query(int u,int l,int r,int p)
{
	if(l==r)return s[u];
	int mid=(l+r)>>1;
	if(p<=mid)return s[u]^query(u<<1,l,mid,p);
	else return s[u]^query(u<<1|1,mid+1,r,p);
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),pre[i]=pre[i-1]^a[i];
	read(m);
	for(int i=1;i<=m;i++)read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1;i<=n;i++)nxt[i]=p[a[i]],p[a[i]]=i;
	int h=1;
	for(int i=1;i<=n;i++)
	{
		cover(1,1,n,nxt[i]+1,i,a[i]);
		while(q[h].r==i)ans[q[h].id]=query(1,1,n,q[h].l)^pre[q[h].r]^pre[q[h].l-1],h++;
	}
	for(int i=1;i<=m;i++)write(ans[i]);
	return 0;
}