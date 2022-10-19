#include<bits/stdc++.h>
using namespace std;
int lastans=0,n,m,p[1000005],q[1000005],r[1000005],id[1000005];
int sm[1000005*25],ls[1000005*25],rs[1000005*25],tot=0;
int f(int z)
{
	return (z+lastans-1)%n+1;
}
void add(int x,int y,int l,int r,int u)
{
	if(l==r)
	{
		sm[y]=sm[x]+1;
		return;
	}
	ls[y]=ls[x],rs[y]=rs[x];
	int mid=l+r>>1;
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
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]),r[q[i]]=i;
	for(int i=1;i<=n;i++)add(id[i-1],id[i]=++tot,1,n,r[p[i]]);
	cin>>m;
	while(m--)
	{
		int t_a,t_b,t_c,t_d;
		scanf("%d%d%d%d",&t_a,&t_b,&t_c,&t_d);
		int l1=min(f(t_a),f(t_b)),r1=max(f(t_a),f(t_b));
		int l2=min(f(t_c),f(t_d)),r2=max(f(t_c),f(t_d));
		lastans=query(id[l1-1],id[r1],1,n,l2,r2);
		printf("%d\n",lastans);
		lastans++;
	}
	return 0;
}