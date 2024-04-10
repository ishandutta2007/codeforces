#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define mid ((h+t)>>1)
#define ll long long
const int N=2e6;
int a[N],jh[N],fz[N],n,q;
ll sum[N];
#define updata(x) sum[x]=sum[x*2+1]+sum[x*2]
void change(int x,int h,int t,int pos,int k,int o,int cs)
{
	if (h==t)
	{
		sum[x]=k; return;
	}
	o^=fz[cs];
	if (pos<=mid)
	  if (o^jh[cs]==0) change(x*2,h,mid,pos,k,o,cs+1);
	  else change(x*2+1,h,mid,pos,k,o,cs+1);
	else if (o^jh[cs]==0) change(x*2+1,mid+1,t,pos,k,o,cs+1);
	   else change(x*2,mid+1,t,pos,k,o,cs+1);
	updata(x); 
}
ll query(int x,int h,int t,int h1,int t1,int o,int cs)
{
	if (h1<=h&&t<=t1) return sum[x];
	o^=fz[cs];
	ll ans=0;
	if (h1<=mid)
	  if (o^jh[cs]==0) ans+=query(x*2,h,mid,h1,t1,o,cs+1);
	  else ans+=query(x*2+1,h,mid,h1,t1,o,cs+1);
	if (mid<t1) if (o^jh[cs]==0) ans+=query(x*2+1,mid+1,t,h1,t1,o,cs+1);
	  else ans+=query(x*2,mid+1,t,h1,t1,o,cs+1);
	return  ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	int m=n;
	int op=1;
	rep(i,1,n) op=op*2;
	n=op; 
	rep(i,1,n) cin>>a[i],change(1,1,n,i,a[i],0,1);
	rep(i,1,q)
	{
		int tt,x,t;
		cin>>tt;
		if(tt==1||tt==4) cin>>x>>t;
		else cin>>t;
		if (tt==1) change(1,1,n,x,t,0,1);
		if (tt==2) fz[m-t+1]^=1;
		if (tt==3) jh[m-t]^=1;
		if (tt==4) cout<<query(1,1,n,x,t,0,1)<<endl;
	}
	return 0;
}