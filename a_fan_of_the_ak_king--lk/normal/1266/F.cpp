#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=500005,E=262144;
const long long inf=30000000000000000ll;
const int inv=500000004;
int n,m,i,j,k,u,v,head[N],Next[N*2],adj[N*2],d[N],df[N],fa[N],a[N],b[N];
int ans1[N],ans2[N],ans[N],tree[N],tmp[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int f)
{
	int j;
	fa[i]=f;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
		{
			dfs(adj[j],i);
			d[i]=max(d[i],d[adj[j]]);
		}
	++d[i];
}
void fdfs(int i)
{
	int mx=0,mxx;
	for(int j=head[i];j!=0;j=Next[j])
		if(mx<d[adj[j]]&&adj[j]!=fa[i])
		{
			mx=d[adj[j]];
			mxx=adj[j];
		}
	if(mx<df[i])
	{
		mx=df[i];
		mxx=0;
	}
	++mx;
	for(int j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa[i])
			if(adj[j]!=mxx)
				df[adj[j]]=mx;
			else
			{
				int m=df[i];
				for(int k=head[i];k!=0;k=Next[k])
					if(adj[k]!=mxx&&adj[k]!=fa[i])
						m=max(m,d[adj[k]]);
				df[mxx]=m+1;
			}
	for(int j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa[i])
			fdfs(adj[j]);
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	dfs(1,0);
	fdfs(1);
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=head[i];j!=0;j=Next[j])
			if(adj[j]!=fa[i])
				a[++k]=d[adj[j]];
		if(df[i])
			a[++k]=df[i];
		sort(a+1,a+1+k,cmp);
		for(int y=1;y<=k;)
		{
			for(j=y;j<=k&&a[y]==a[j];++j);
			ans1[a[y]]=max(ans1[a[y]],j-1);
			ans1[a[y]+1]=max(ans1[a[y]+1],y);
			y=j;
		}
	}
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=head[i];j!=0;j=Next[j])
			if(adj[j]!=fa[i])
				a[++k]=d[adj[j]];
		if(df[i])
			a[++k]=df[i];
		for(j=1;j<=k+1;++j)
			tmp[j]=0;
		sort(a+1,a+1+k,cmp);
		for(j=head[i];j!=0;j=Next[j])
			if(adj[j]!=fa[i])
			{
				int t=0;
				for(int m=head[adj[j]];m!=0;m=Next[m])
					if(adj[m]!=fa[adj[j]])
						b[++t]=d[adj[m]];
				sort(b+1,b+1+t,cmp);
				for(int m=1;m<=t;++m)
				{
					int x=lower_bound(a+1,a+1+k,b[m],greater<int>())-a;
					ans2[b[m]]=max(ans2[b[m]],x-1+m-(d[adj[j]]>=b[m]));
					tmp[x]=max(tmp[x],x+m-(d[adj[j]]>=b[m]));
				}
			}
		for(j=1;j<=k;++j)
		{
			tmp[j]=max(tmp[j-1]+1,tmp[j]);
			ans2[a[j]]=max(ans2[a[j]],tmp[j]);
		}
		for(int y=1;y<=k;)
		{
			for(j=y;j<=k&&a[y]==a[j];++j);
			ans2[a[y]]=max(ans2[a[y]],j-1);
			y=j;
		}
	}
	for(i=n;i>=1;--i)
	{
		ans1[i]=max(ans1[i+1],ans1[i]);
		ans2[i]=max(ans2[i+1],ans2[i]);
	}
	for(i=1;i*2-1<=n;++i)
	{
		ans[i*2-1]=ans1[i];
		ans[i*2]=ans2[i];
	}
	++ans[1];
	for(i=1;i<=n;++i)
		printf("%d ",max(ans[i],1));
}