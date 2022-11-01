#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((int)101*1000)
#define MOD ((int)1e9+7)

struct Mat{
	ll r,c,a[2][2];
	Mat (){for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=0;}
	void operator *=(Mat x)
	{
		Mat res;res.r=r;res.c=x.c;
		for(int k=0;k<c;k++)
			for(int i=0;i<r;i++)
				for(int j=0;j<x.c;j++)
					res.a[i][j]+=a[i][k]*x.a[k][j],res.a[i][j]%=MOD;
		*this=res;
	}
	Mat operator ^(ll num)
	{
		Mat res,ex=*this;res.r=r;res.c=c;
		for(int i=0;i<min(r,c);i++)res.a[i][i]=1;
		while(num)
		{
			if(num%2)res*=ex;
			ex*=ex;
			num/=2;
		}
		return res;
	}
};
ll n,m;
Mat base,base2,I,seg[4*N],lazy[4*N];

void update(ll,ll,Mat,ll,ll,ll);
void shift(ll xl,ll xr,ll id)
{
	ll mid=(xl+xr)/2;
	lazy[id*2]*=lazy[id];
	lazy[id*2+1]*=lazy[id];
	seg[id*2]*=lazy[id];
	seg[id*2+1]*=lazy[id];
	lazy[id]=I;
}

Mat merge(Mat x,Mat y)
{
	Mat res=base2;
	res.a[0][0]=(x.a[0][0]+y.a[0][0])%MOD;
	res.a[0][1]=(x.a[0][1]+y.a[0][1])%MOD;
	return res;
}

void update(ll ql,ll qr,Mat val,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		lazy[id]*=val;
		seg[id]*=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(xl,xr,id);
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

Mat query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return base2;
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	shift(xl,xr,id);
	return merge(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	base.a[0][0]=base.a[0][1]=base.a[1][0]=1;base.r=2;base.c=2;
	base2.r=1;base2.c=2;base2.a[0][0]=1,base2.a[0][1]=0;
	I.r=2,I.c=2;I.a[0][0]=I.a[1][1]=1;
	for(int i=0;i<4*N;i++)seg[i]=base2,lazy[i]=I;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		Mat ex=base^x;
		update(i,i+1,ex);
	}
	while(m--)
	{
		ll t,l,r,x;
		cin>>t;
		if(t==1)
		{
			cin>>l>>r>>x;
			Mat ex=base^x;
			update(l-1,r,ex);
		}
		if(t==2)
		{
			cin>>l>>r;
			cout<<query(l-1,r).a[0][1]<<"\n";
		}
	}
	return 0;
}