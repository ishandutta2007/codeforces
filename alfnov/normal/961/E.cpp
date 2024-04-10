#include<bits/stdc++.h>
using namespace std;
int sm[800005*25],ls[800005*25],rs[800005*25],id[200005],a[200005];
int tot=0;
void add(int x,int y,int l,int r,int u)
{
	if(l==r)
	{
		sm[y]=sm[x]+1;
		return;
	}
	int mid=l+r>>1;
	ls[y]=ls[x],rs[y]=rs[x];
	if(u<=mid)add(ls[x],ls[y]=++tot,l,mid,u);
	else add(rs[x],rs[y]=++tot,mid+1,r,u);
	sm[y]=sm[ls[y]]+sm[rs[y]];
}
int query(int x,int y,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm[y]-sm[x];
	int mid=l+r>>1,ans=0;
	if(mid>=ll)ans+=query(ls[x],ls[y],l,mid,ll,rr);
	if(mid<rr)ans+=query(rs[x],rs[y],mid+1,r,ll,rr);
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=min(a[i],n);
	id[0]=0;
	for(int i=1;i<=n;i++)add(id[i-1],id[i]=++tot,1,n,a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i+1>a[i])continue;
		ans+=query(id[i],id[a[i]],1,n,i,n);
	}
	cout<<ans<<endl;
	return 0;
}