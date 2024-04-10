#include<bits/stdc++.h>
using namespace std;
int a[100005],s_max[400005];
long long s_sum[400005];
void build(int l,int r,int o)
{
	if(l==r)
	{
		s_sum[o]=s_max[o]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	s_sum[o]=s_sum[o<<1]+s_sum[o<<1|1];
	s_max[o]=max(s_max[o<<1],s_max[o<<1|1]);
}
long long query(int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return s_sum[o];
	int mid=l+r>>1;
	long long ans=0;
	if(mid>=ll)ans+=query(l,mid,o<<1,ll,rr);
	if(mid<rr)ans+=query(mid+1,r,o<<1|1,ll,rr);
	return ans;
}
void add_2(int l,int r,int o,int ll,int rr,int p)
{
	if(s_max[o]<p)return;
	if(l==r)
	{
		a[l]%=p;
		s_sum[o]=s_max[o]=a[l];
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)add_2(l,mid,o<<1,ll,rr,p);
	if(mid<rr)add_2(mid+1,r,o<<1|1,ll,rr,p);
	s_sum[o]=s_sum[o<<1]+s_sum[o<<1|1];
	s_max[o]=max(s_max[o<<1],s_max[o<<1|1]);
}
void add_1(int l,int r,int o,int k,int x)
{
	if(l==r)
	{
		a[k]=x;
		s_sum[o]=s_max[o]=a[k];
		return;
	}
	int mid=l+r>>1;
	if(k<=mid)add_1(l,mid,o<<1,k,x);
	else add_1(mid+1,r,o<<1|1,k,x);
	s_sum[o]=s_sum[o<<1]+s_sum[o<<1|1];
	s_max[o]=max(s_max[o<<1],s_max[o<<1|1]);
}
int main()
{
	int n;
    int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,n,1,l,r));
		}else if(op==2)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			add_2(1,n,1,l,r,x);
		}else
		{
			int k,x;
			scanf("%d%d",&k,&x);
			add_1(1,n,1,k,x);
		}
	}
	return 0;
}