#include<bits/stdc++.h>
using namespace std;
int sm[600005],lz[600005],a[150005],b[150005];
void pushdown(int l,int r,int o)
{
	lz[o<<1]+=lz[o],lz[o<<1|1]+=lz[o];
	sm[o<<1]+=lz[o],sm[o<<1|1]+=lz[o];
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,int u)
{
	if(l>=ll&&r<=rr)
	{
		lz[o]+=u,sm[o]+=u;
		return;
	}
	pushdown(l,r,o);
	int mid=l+r>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,u);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,u);
	sm[o]=min(sm[o<<1],sm[o<<1|1]);
}
int main()
{
	int n,m,h,ans=0;
	cin>>n>>m>>h;
	h=-h;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),b[i]=-b[i];
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)add(1,m,1,i,i,i-m-1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=-a[i];
	for(int i=1;i<=n;i++)
	{
		int wz=upper_bound(b+1,b+m+1,h-a[i])-b-1;
		if(wz)add(1,m,1,1,wz,1);
		if(i<m)continue;
		if(sm[1]>=0)ans++;
		wz=upper_bound(b+1,b+m+1,h-a[i-m+1])-b-1;
		if(wz)add(1,m,1,1,wz,-1);
	}
	cout<<ans<<endl;
	return 0;
}