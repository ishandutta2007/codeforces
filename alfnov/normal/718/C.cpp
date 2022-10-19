#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct comp
{
	int re,im;
	comp(int re=0,int im=0):re(re),im(im){}
}sm1[400005],sm2[400005],lz1[400005],lz2[400005];
comp cs(0,(2ll*mod+1)/5),c1((mod+1)/2,(mod+1)/2),c2((mod+1)/2,(mod-1)/2);
comp operator+(comp a,comp b)
{
	return comp((a.re+b.re)%mod,(a.im+b.im)%mod);
}
comp operator-(comp a,comp b)
{
	return comp((a.re-b.re)%mod,(a.im-b.im)%mod);
}
comp operator*(comp a,comp b)
{
	return comp((1ll*a.re*b.re+5ll*a.im*b.im)%mod,(1ll*a.re*b.im+1ll*a.im*b.re)%mod);
}
comp operator^(comp a,int b)
{
	comp ans(1,0);
	while(b)
	{
		if(b&1)ans=ans*a;
		b>>=1;
		a=a*a;
	}
	return ans;
}
void pushdown1(int l,int r,int o)
{
	sm1[o<<1]=sm1[o<<1]*lz1[o],sm1[o<<1|1]=sm1[o<<1|1]*lz1[o];
	lz1[o<<1]=lz1[o<<1]*lz1[o],lz1[o<<1|1]=lz1[o<<1|1]*lz1[o];
	lz1[o]=comp(1,0);
}
void pushdown2(int l,int r,int o)
{
	sm2[o<<1]=sm2[o<<1]*lz2[o],sm2[o<<1|1]=sm2[o<<1|1]*lz2[o];
	lz2[o<<1]=lz2[o<<1]*lz2[o],lz2[o<<1|1]=lz2[o<<1|1]*lz2[o];
	lz2[o]=comp(1,0);
}
void add1(int l,int r,int o,int ll,int rr,comp v)
{
	if(l>=ll&&r<=rr)
	{
		sm1[o]=sm1[o]*v,lz1[o]=lz1[o]*v;
		return;
	}
	pushdown1(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll)add1(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add1(mid+1,r,o<<1|1,ll,rr,v);
	sm1[o]=sm1[o<<1]+sm1[o<<1|1];
}
void add2(int l,int r,int o,int ll,int rr,comp v)
{
	if(l>=ll&&r<=rr)
	{
		sm2[o]=sm2[o]*v,lz2[o]=lz2[o]*v;
		return;
	}
	pushdown2(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll)add2(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add2(mid+1,r,o<<1|1,ll,rr,v);
	sm2[o]=sm2[o<<1]+sm2[o<<1|1];
}
comp query1(int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm1[o];
	pushdown1(l,r,o);
	int mid=(l+r)>>1;
	comp ans(0,0);
	if(mid>=ll)ans=ans+query1(l,mid,o<<1,ll,rr);
	if(mid<rr)ans=ans+query1(mid+1,r,o<<1|1,ll,rr);
	return ans;
}
comp query2(int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm2[o];
	pushdown2(l,r,o);
	int mid=(l+r)>>1;
	comp ans(0,0);
	if(mid>=ll)ans=ans+query2(l,mid,o<<1,ll,rr);
	if(mid<rr)ans=ans+query2(mid+1,r,o<<1|1,ll,rr);
	return ans;
}
void build(int l,int r,int o)
{
	lz1[o]=lz2[o]=comp(1,0);
	if(l==r)
	{
		sm1[o]=c1,sm2[o]=c2;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	sm1[o]=sm1[o<<1]+sm1[o<<1|1];
	sm2[o]=sm2[o<<1]+sm2[o<<1|1];
}
int main()
{
	int n,m;
	cin>>n>>m;
	build(1,n,1);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		add1(1,n,1,i,i,c1^(a-1));
		add2(1,n,1,i,i,c2^(a-1));
	}
	while(m--)
	{
		int op,li,rui;
		scanf("%d%d%d",&op,&li,&rui);
		if(op==2)
		{
			comp ans=cs*(query1(1,n,1,li,rui)-query2(1,n,1,li,rui));
			printf("%d\n",(ans.re+mod)%mod);
		}else
		{
			int kai;
			scanf("%d",&kai);
			add1(1,n,1,li,rui,c1^kai);
			add2(1,n,1,li,rui,c2^kai);
		}
	}
	return 0;
}