#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,q,i,nx[N*2][26],pre[N*2],last,k,len[N*2],ch[N*22][2],tot,tree[N*22],nume,num,dfn[N*2],lat[N*2],pos[N],ind[N*2],rt[N];
int fa[N*2][20],ans,f[N],j,lim[N];
int head[N*2],Next[N*2],adj[N*2];
char c[N];
void Push(int u,int v)
{
	Next[++nume]=head[u];
	head[u]=nume;
	adj[nume]=v;
}
void Insert(int x)
{
	int p=last;last=++k;
	len[k]=len[p]+1;
	for(;p&&!nx[p][x];p=pre[p])nx[p][x]=k;
	if(!p){pre[k]=1;return;}
	if(len[nx[p][x]]==len[p]+1){pre[k]=nx[p][x];return;}
	int np=nx[p][x],q=++k;
	len[q]=len[p]+1;
	pre[q]=pre[np];
	pre[np]=pre[last]=q;
	memcpy(nx[q],nx[np],sizeof(nx[q]));
	for(;nx[p][x]==np;p=pre[p])nx[p][x]=q;
}
void Build(int i,int l,int r)
{
	if(l==r)
		return;
	int mid=l+r>>1;
	ch[i][0]=++tot;
	Build(tot,l,mid);
	ch[i][1]=++tot;
	Build(tot,mid+1,r);
}
void dfs(int i)
{
	dfn[i]=num+1;
	if(ind[i])
		++num;
	int j;
	for(j=head[i];j!=0;j=Next[j])
	{
		fa[adj[j]][0]=i;
		dfs(adj[j]);
	}
	lat[i]=num;
}
void modify(int i,int l,int r,int x,int y)
{
	int p=++tot;
	if(l==r)
	{
		tree[p]=y;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
	{
		ch[p][1]=ch[i][1];
		ch[p][0]=tot+1;
		modify(ch[i][0],l,mid,x,y);
	}
	else
	{
		ch[p][0]=ch[i][0];
		ch[p][1]=tot+1;
		modify(ch[i][1],mid+1,r,x,y);
	}
	tree[p]=max(tree[ch[p][1]],tree[ch[p][0]]);
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,ans=0;
	if(mid>=ll)
		ans=max(ans,Query(ch[i][0],l,mid,ll,rr));
	if(mid<rr)
		ans=max(ans,Query(ch[i][1],mid+1,r,ll,rr));
	return ans;
}
bool check(int x,int l,int op)
{
	int i;
	int p=pos[x];
	for(i=19;i>=0;--i)
		if(len[fa[p][i]]>=l-1+op)
			p=fa[p][i];
	return (Query(rt[x-l],1,n,dfn[p],lat[p])>=l-1+op);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	reverse(c+1,c+1+n);
	last=k=1;
	for(i=1;i<=n;++i)
	{
		pos[i]=k+1;
		ind[k+1]=i;
		Insert(c[i]-'a');
	}
	for(i=2;i<=k;++i)
		Push(pre[i],i);
	dfs(1);
	for(i=1;i<20;++i)
		for(j=1;j<=k;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	rt[0]=tot=1;
	Build(1,1,n);
	for(i=1;i*(i-1)/2<=n;++i)
		for(j=i*(i-1)/2+1;j<=n&&j<=i*(i+1)/2;++j)
			lim[j]=i;
	for(i=1;i<=n;++i)
	{
		if(i!=1)
		{
			for(j=max(f[i-1],2);(check(i,j,0)||check(i-1,j-1,1))&&j<=lim[i];++j);
			f[i]=j-1;
		}
		else
			f[i]=1;
		rt[i]=tot+1;
		ans=max(ans,f[i]);
		modify(rt[i-1],1,n,dfn[pos[i]],f[i]);
		//cout<<tree[rt[i]]<<endl;
	}
	cout<<ans;
}