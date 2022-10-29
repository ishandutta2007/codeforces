#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
struct edge
{
	int u,v,w;
}e[N],f[N];
struct node
{
	int id,h;
}w[N];
int n,m,q,i,j,k,l,p[N],mxdep[N];
bool ans[N];
inline void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
bool cmp(node a,node b)
{
	if(e[a.h].w!=e[b.h].w)
		return e[a.h].w<e[b.h].w;
	return a.id<b.id;
}
bool cmq(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return !p[x]?x:find(p[x]);
}
struct sx
{
	int a,b,mxdep,p;
}st[500005];
int top,pot;
void merge(int x,int y)
{
	int a=find(x),b=find(y);
	if(mxdep[a]>mxdep[b])
		swap(a,b);
	st[++top]=(sx){a,b,mxdep[b],p[a]};
	mxdep[b]=max(mxdep[b],mxdep[a]+1);
	p[a]=b;
}
void Resume()
{
	mxdep[st[top].b]=st[top].mxdep;
	p[st[top].a]=st[top].p;
	--top;
}
int main()
{
	Read(n);Read(m);
	for(i=1;i<=m;++i)
	{
		Read(e[i].u);
		Read(e[i].v);
		Read(e[i].w);
		f[i]=e[i];
	}
	sort(f+1,f+1+m,cmq);
	Read(q);
	for(i=1;i<=q;++i)
	{
		Read(j);
		while(j--)
		{
			Read(k);
			w[++l]=(node){i,k};
		}
	}
	sort(w+1,w+1+l,cmp);
	for(i=1;i<=q;++i)
		ans[i]=true;
	for(i=1,k=1;i<=l;i=j)
	{
		while(f[k].w<e[w[i].h].w)
		{
			if(find(f[k].u)!=find(f[k].v))
				merge(f[k].u,f[k].v);
			++k;
		}
		pot=top;
		for(j=i;j<=l&&e[w[i].h].w==e[w[j].h].w&&w[i].id==w[j].id;++j)
			if(find(e[w[j].h].u)!=find(e[w[j].h].v))
				merge(e[w[j].h].u,e[w[j].h].v);
			else
				ans[w[j].id]=false;
		while(top>pot)
			Resume();
	}
	for(i=1;i<=q;++i)
		if(ans[i])
			puts("YES");
		else
			puts("NO");
	return 0;
}