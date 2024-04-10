#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,x,y,a[N],tree[N*22],k,ch[N*22][2],rt[N],sta[N],top;
void Build(int i,int l,int r)
{
	if(l==r)
		return;
	int mid=l+r>>1;
	ch[i][0]=++k;
	Build(k,l,mid);
	ch[i][1]=++k;
	Build(k,mid+1,r);
}
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[++k]=y;
		return;
	}
	int mid=l+r>>1;
	int t=++k;
	if(mid>=x)
	{
		ch[t][1]=ch[i][1];
		ch[t][0]=k+1;
		modify(ch[i][0],l,mid,x,y);
	}
	else
	{
		ch[t][0]=ch[i][0];
		ch[t][1]=k+1;
		modify(ch[i][1],mid+1,r,x,y);
	}
	tree[t]=max(tree[ch[t][0]],tree[ch[t][1]]);
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int ans=0;
	int mid=l+r>>1;
	if(mid>=ll)
		ans=Query(ch[i][0],l,mid,ll,rr);
	if(mid<rr)
		ans=max(ans,Query(ch[i][1],mid+1,r,ll,rr));
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		rt[0]=k=1;
		Build(1,1,n);
		top=0;
		int ans=0;
		for(i=1;i<=n;++i)
		{
			while(top&&a[sta[top]]<a[i])
				--top;
			int x=Query(rt[i-1],1,n,1,a[i])+1;
			if(top)
				x=max(x,Query(rt[sta[top]-1],1,n,1,a[i])+2);
			rt[i]=k+1;
			modify(rt[i-1],1,n,a[i],x);
			ans=max(ans,x);
			sta[++top]=i;
		}
		for(i=1;i<=k;++i)
			ch[i][0]=ch[i][1]=tree[i]=0;
		printf("%d\n",ans);
	}
}