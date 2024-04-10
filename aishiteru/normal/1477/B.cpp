#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long M=3799912185593857ll;
int n,t,i,l[N],r[N],lazy[N*4],s[N*4],m;
char c[N],f[N];
void pushdown(int i,int l,int r)
{
	if(lazy[i]!=-1)
	{
		int mid=l+r>>1;
		lazy[i<<1|1]=lazy[i<<1]=lazy[i];
		s[i<<1]=lazy[i]*(mid-l+1),s[i<<1|1]=lazy[i]*(r-mid);
		lazy[i]=-1;
	}
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]=x;
		s[i]=x*(r-l+1);
		return;
	}
	pushdown(i,l,r);
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	s[i]=s[i<<1]+s[i<<1|1];
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return s[i];
	int mid=l+r>>1,ans=0;
	pushdown(i,l,r);
	if(mid>=ll)
		ans+=Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		ans+=Query(i<<1|1,mid+1,r,ll,rr);
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
		scanf("%d %d",&n,&m);
		scanf("%s",c+1);
		scanf("%s",f+1);
		for(i=1;i<=m;++i)
			scanf("%d %d",&l[i],&r[i]);
		for(i=0;i<=n*4;++i)
			lazy[i]=-1;
		for(i=1;i<=n;++i)
			modify(1,1,n,i,i,f[i]-'0');
		for(i=m;i>=1;--i)
		{
			int w=Query(1,1,n,l[i],r[i]);
			if(w*2==r[i]-l[i]+1)
				break;
			modify(1,1,n,l[i],r[i],(w*2>r[i]-l[i]+1));	
		}
		if(i==0)
		{
			for(i=1;i<=n;++i)
				if(c[i]-'0'!=Query(1,1,n,i,i))
					break;
			puts(i>n?"YES":"NO");
		}
		else
			puts("NO");
	}
}