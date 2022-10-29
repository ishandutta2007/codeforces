#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000005;
struct node
{
	int ch[2],w,size,add;
}a[N];
int n,i,j,k,l[N],r[N],num,ans,cnt,root,u;
void pushdown(int o)
{
	a[a[o].ch[0]].add+=a[o].add,a[a[o].ch[1]].add+=a[o].add;
	a[o].w+=a[o].add;
	a[o].add=0;
}
void maintain(int o)
{
	a[o].size=a[a[o].ch[0]].size+a[a[o].ch[1]].size+1;
}
void built(int &o,int l,int r)
{
	if(l>r)
	{
		o=0;
		return;
	}
	int mid=l+r>>1;
	o=++cnt;
	a[o].w=(mid<=1?0:1<<30);
	a[o].size=r-l+1;
	built(a[o].ch[0],l,mid-1);
	built(a[o].ch[1],mid+1,r);
}
int Rank(int o,int x)
{
	if(!o)
		return 0;
	pushdown(o);
	if(a[o].w<=x)
		return a[a[o].ch[0]].size+1+Rank(a[o].ch[1],x);
	else
		return Rank(a[o].ch[0],x);
}
void work(int o)
{
	if(!o)
		return;
	pushdown(o);
	work(a[o].ch[0]);
	++u;
	if(a[o].w<(1<<30))
		ans=max(ans,u-2);
	work(a[o].ch[1]);
}
int cmp(int o,int x)
{
	if(a[a[o].ch[0]].size+1==x)
		return -1;
	return a[a[o].ch[0]].size+1<x;
}
void rotate(int &o,int d)
{
	int k=a[o].ch[d];
	a[o].ch[d]=a[k].ch[d^1];
	a[k].ch[d^1]=o;
	maintain(o);
	maintain(k);
	o=k;
}
void splay(int &o,int x)
{
	pushdown(o);
	int k1=cmp(o,x);
	if(k1==-1)
		return;
	if(k1==1)
		x-=a[a[o].ch[0]].size+1;
	pushdown(a[o].ch[k1]);
	int k2=cmp(a[o].ch[k1],x);
	if(k2!=-1)
	{
		if(k2==1)
			x-=a[a[a[o].ch[k1]].ch[0]].size+1;
		splay(a[a[o].ch[k1]].ch[k2],x);
		if(k1==k2)
			rotate(o,k1);
		else
			rotate(a[o].ch[k1],k2);
	}
	rotate(o,k1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",l+i,r+i);
	built(root,0,n+5);
	for(i=1;i<=n;++i)
	{
		j=Rank(root,l[i]-1);
		k=Rank(root,r[i]-1);
		if(j<k)
		{
			splay(root,j);
			splay(a[root].ch[1],k-j+1);
			pushdown(root);
			pushdown(a[root].ch[1]);
			a[a[a[root].ch[1]].ch[0]].add++;
		}
		splay(root,k);
		splay(a[root].ch[1],2);
		a[a[root].ch[1]].ch[0]=0;
		maintain(a[root].ch[1]);
		maintain(root);
		splay(root,j);
		splay(a[root].ch[1],1);
		pushdown(root);
		pushdown(a[root].ch[1]);
		++cnt;
		a[cnt].size=1;
		a[cnt].w=l[i];
		a[a[root].ch[1]].ch[0]=cnt;
		maintain(a[root].ch[1]);
		maintain(root);
	}
	work(root);
	printf("%d",ans);
	return 0;
}