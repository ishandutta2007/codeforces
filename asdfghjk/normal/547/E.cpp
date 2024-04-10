#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
struct node
{
	int fa,len,ch[26];
}a[N];
int n,q,i,j,k,lst,cnt,pt[N],sum[N*40],tot,head[N],adj[N],nxt[N],root[N],ch[N*40][2],g[N];
char s[N];
void update(int &o,int l,int r,int x)
{
	if(!o)
		o=++tot;
	if(l==r)
	{
		sum[o]++;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(ch[o][0],l,mid,x);
	else
		update(ch[o][1],mid+1,r,x);
	sum[o]=sum[ch[o][0]]+sum[ch[o][1]];
}
int merge(int o1,int o2,int l,int r)
{
	if(!o2)
		return o1;
	if(!o1)
		return o2;
	int rt=++tot;
	if(l==r)
	{
		sum[tot]=sum[o1]+sum[o2];
		return tot;
	}
	int mid=l+r>>1;
	ch[rt][0]=merge(ch[o1][0],ch[o2][0],l,mid);
	ch[rt][1]=merge(ch[o1][1],ch[o2][1],mid+1,r);
	sum[rt]=sum[ch[rt][0]]+sum[ch[rt][1]];
	return rt;
}
int query(int o,int l,int r,int x,int y)
{
	if(!o)
		return 0;
	if(l>=x&&r<=y)
		return sum[o];
	int mid=l+r>>1,rtn=0;
	if(x<=mid)
		rtn=query(ch[o][0],l,mid,x,y);
	if(y>mid)
		rtn+=query(ch[o][1],mid+1,r,x,y);
	return rtn;
}
void dfs(int x)
{
	if(g[x])
		update(root[x],1,n,g[x]);
	for(int y=head[x];y;y=nxt[y])
	{
		dfs(adj[y]);
		root[x]=merge(root[x],root[adj[y]],1,n);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	cnt=1;
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		lst=1;
		for(j=1;s[j];++j)
		{
			k=s[j]-'a';
			int p,np;
			p=lst;
			np=lst=++cnt;
			g[cnt]=i;
			a[np].len=a[p].len+1;
			for(;p&&!a[p].ch[k];p=a[p].fa)
				a[p].ch[k]=np;
			if(!p)
				a[np].fa=1;
			else
			{
				int q=a[p].ch[k];
				if(a[q].len==a[p].len+1)
					a[np].fa=q;
				else
				{
					int nq=++cnt;
					a[nq]=a[q];
					a[nq].len=a[p].len+1;
					a[np].fa=a[q].fa=nq;
					for(;p&&a[p].ch[k]==q;p=a[p].fa)
						a[p].ch[k]=nq;
				}
			}
		}
		for(j=1,k=1;s[j];++j)
			k=a[k].ch[s[j]-'a'];
		pt[i]=k;
	}
	for(i=2;i<=cnt;++i)
	{
		adj[i-1]=i;
		nxt[i-1]=head[a[i].fa];
		head[a[i].fa]=i-1;
	}
	dfs(1);
	while(q--)
	{
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n",query(root[pt[k]],1,n,i,j));
	}
	return 0;
}