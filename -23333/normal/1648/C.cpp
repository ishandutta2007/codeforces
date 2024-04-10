#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
ll a[N],b[N],sum[N],nn;
ll jc[N],jc2[N];
#define lowbit(x) (x&(-x))
const int mo=998244353;
#define mid ((h+t)/2)
struct sgt{
	ll v[N],v2[N];
	sgt()
	{
		rep(i,0,N-1) v2[i]=1;
	}
	void add(int x,int h,int t,int pos,int k)
	{
		if (h==t) 
		{ 
		  v[x]+=k;
		  v2[x]=jc[v[x]];
		  return;
		}
		if (pos<=mid) add(x*2,h,mid,pos,k);
		else add(x*2+1,mid+1,t,pos,k);
		v[x]=v[x*2]+v[x*2+1];
		v2[x]=v2[x*2]*v2[x*2+1]%mo;
	}
	int q(int x,int h,int t,int h1,int t1)
	{
		if (h1>t1) return 0;
		if (h1<=h&&t<=t1)
		{ 
		  return v[x];
	    }
		int ans=0;
		if (h1<=mid) ans+=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans+=q(x*2+1,mid+1,t,h1,t1);
		return ans; 
	}
	ll q2(int x,int h,int t,int h1,int t1)
	{
		if (h1>t1) return 1;
		if (h1<=h&&t<=t1)
		{ 
		  return v2[x];
	    }
		ll ans=1;
		if (h1<=mid) ans=q2(x*2,h,mid,h1,t1);
		if (mid<t1) ans*=q2(x*2+1,mid+1,t,h1,t1);
		ans%=mo;
		return ans; 
	}
}S;
ll fsp(int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y%2==1) ans=ans*x%mo;
    return ans;
}
ll C(int x,int y)
{
	if (y<0||x<y) return 0;
	return jc[x]*jc2[y]%mo*jc2[x-y]%mo; 
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
//	cin>>T;
    T=1;
    nn=2e5;
	while (T--)
	{ 
	   int n,m;
	   cin>>n>>m;
	   jc[0]=1; jc2[0]=1;
	   rep(i,1,n) jc[i]=jc[i-1]*i%mo;
       jc2[n]=fsp(jc[n],mo-2);
       dep(i,n-1,1) jc2[i]=jc2[i+1]*(i+1)%mo;
	   rep(i,1,n)
	   { 
	     cin>>a[i],S.add(1,1,nn,a[i],1);
	     sum[a[i]]++;
	   }
	   rep(i,1,m) cin>>b[i];
	   ll ans=0;
	   rep(i,1,m)
	   {
	   	  ll n1=S.q(1,1,nn,1,b[i]-1),n3=S.q(1,1,nn,b[i],nn);
	   	  ll n2=S.q2(1,1,nn,1,b[i]-1),n4=S.q2(1,1,nn,b[i],nn);
	   	 // cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl;
	   	  ans=(ans+jc[n1]*jc[n3]%mo*fsp(n2,mo-2)%mo*fsp(n4,mo-2)%mo*C(n1+n3-1,n1-1))%mo; 
	   	  sum[b[i]]--;
	   	  if (sum[b[i]]<0) break;
	   	  S.add(1,1,nn,b[i],-1);
	   	  if (i==n&&m>n)
		  { 
			   ans++;
			   break;
		  }
		 // cout<<ans<<endl;
	   }
	   cout<<ans%mo<<endl;
    }
	return 0;
}/*
4 4
1 1 1 1
2 2 2 2
4 4
1 1 2 2
2 2 1 1
*/