#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=500105;

int n,m,leaf[MAXN],disleaf[MAXN<<2|1];
vector<int> G[MAXN<<2|1];
void build(int id,int l,int r)
{
	if(l==r){m=max(m,id);leaf[l]=id;disleaf[id]=l;return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	G[id<<1].pb(id);
	G[id<<1|1].pb(id);
}
void query(int id,int l,int r,int ql,int qr,int x)
{
	if(l==ql && r==qr){G[id].pb(x);return;}
	int mid=(l+r)>>1;
	if(qr<=mid)query(id<<1,l,mid,ql,qr,x);
	else if(ql>mid)query(id<<1|1,mid+1,r,ql,qr,x);
	else query(id<<1,l,mid,ql,mid,x),query(id<<1|1,mid+1,r,mid+1,qr,x); 
}

int ind[MAXN<<2|1],q[MAXN<<2|1],a[MAXN];
void solve()
{
	int x;
	scanf("%d",&n);
	m=0;
	build(1,1,n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<0)continue;
		G[leaf[i]].pb(leaf[x]);
		if(x-i==1)continue;
		query(1,1,n+1,i+1,x-1,leaf[i]);
	}
/*
for(int i=1;i<=m;i++)
{
	printf("%d,%d:",i,disleaf[i]);
	for(int j=0;j<G[i].size();++j)
		printf("%d ",G[i][j]);
	printf("\n");
}
*/
	int front=1,rear=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<G[i].size();++j)
			++ind[G[i][j]];
	for(int i=1;i<=m;i++)
		if(!ind[i])q[++rear]=i;
	while(front<=rear)
	{
		int u=q[front++];
		for(int j=0;j<G[u].size();j++)
		{
			--ind[G[u][j]];
			if(!ind[G[u][j]])q[++rear]=G[u][j];
		}
	}
	if(rear!=m)printf("-1\n");
	else
	{
		/*for(int i=1;i<=m;i++)cout<<q[i]<<" ";
		cout<<endl;*/
		int cnt=0;
		for(int i=1;i<=m;i++)
			if(disleaf[q[i]] && disleaf[q[i]]!=n+1)a[disleaf[q[i]]]=++cnt;
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	for(int i=1;i<=m;i++)
		{G[i].clear();ind[i]=disleaf[i]=0;}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}