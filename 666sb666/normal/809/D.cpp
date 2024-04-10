#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=3e5+5,INF=1e9;
struct T{int l,r,k,f,lazy;}t[N<<1];
int cnt,root;
int n,l[N],r[N];
inline int newnode(int v){cnt++;t[cnt].k=rand();t[cnt].f=v;return cnt;}
inline void pushdown(int x)
{
	if(t[x].lazy)
	{
		if(t[x].l)t[t[x].l].lazy+=t[x].lazy,t[t[x].l].f+=t[x].lazy;
		if(t[x].r)t[t[x].r].lazy+=t[x].lazy,t[t[x].r].f+=t[x].lazy;
		t[x].lazy=0;
	}
}
int merge(int a,int b)
{
	if(!a)return b;if(!b)return a;
	if(t[a].k>t[b].k){pushdown(a);t[a].r=merge(t[a].r,b);return a;}
	else {pushdown(b);t[b].l=merge(a,t[b].l);return b;}
}
pair<int,int> split(int x,int k)
{
	if(!x)return make_pair(0,0);
	pair<int,int> y;pushdown(x);
	if(t[x].f>=k)y=split(t[x].l,k),t[x].l=y.second,y.second=x;
	else y=split(t[x].r,k),t[x].r=y.first,y.first=x;
	return y;
}
int getmin(int x){while(t[x].l)pushdown(x),x=t[x].l;return t[x].f;}
int getans(int x)
{
	if(!x)return 0;pushdown(x);
	return getans(t[x].l)+getans(t[x].r)+(t[x].f<=INF);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;i++)root=merge(root,newnode(INF+i));
	for(int i=1;i<=n;i++)
	{
		pair<int,int>a,b,c;
		a=split(root,l[i]);
		b=split(a.second,r[i]);
		if(b.first)t[b.first].lazy++,t[b.first].f++;
		int mn=getmin(b.second);
		c=split(b.second,mn+1);
		root=merge(a.first,newnode(l[i]));
		root=merge(root,b.first);
		root=merge(root,c.second);
	}
	printf("%d\n",getans(root));
	return 0;
}