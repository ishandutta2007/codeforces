#include<bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
int sm[2000005],lz[2000005],l[200005],r[200005];
void pushdown(int l,int r,int o)
{
	if(!lz[o])return;
	int mid=l+r>>1;
	lz[o<<1]=lz[o<<1|1]=lz[o];
	sm[o<<1]=(lz[o]-1)*(mid-l+1);
	sm[o<<1|1]=(lz[o]-1)*(r-mid);
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		lz[o]=v+1;
		sm[o]=v*(r-l+1);
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,v);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
int query(int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm[o];
	pushdown(l,r,o);
	int mid=l+r>>1,ans=0;
	if(mid>=ll)ans+=query(l,mid,o<<1,ll,rr);
	if(mid<rr)ans+=query(mid+1,r,o<<1|1,ll,rr);
	return ans;
}
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,q,flag=1,tot=0;
		cin>>n>>q;
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=4*n;i++)sm[i]=lz[i]=0;
		for(int i=1;i<=n;i++)add(1,n,1,i,i,t[i]-'0');
		for(int i=1;i<=q;i++)scanf("%d%d",&l[i],&r[i]);
		for(int i=q;i>=1;i--)
		{
			int w1=query(1,n,1,l[i],r[i]),w0=r[i]-l[i]+1-w1;
			if(w0==w1)
			{
				puts("NO");
				flag=0;
				break;
			}
			if(w0>w1)add(1,n,1,l[i],r[i],0);
			else add(1,n,1,l[i],r[i],1);
		}
		if(!flag)continue;
		for(int i=1;i<=n;i++)if(query(1,n,1,i,i)!=s[i]-'0')
		{
			puts("NO");
			flag=0;
			break;
		}
		if(flag)puts("YES");
	}
	return 0;
}