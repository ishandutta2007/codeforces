#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=200005,mod=1000000007;

int n,Q,a[MAXN];
struct Fenwick
{
	bool mode;
	ll c[MAXN];
	void add(int x,ll d)
	{
		if(mode)d=(d%mod+mod)%mod;
		for(int i=x;i<=n;i+=(i&-i))
		{
			c[i]+=d;
			if(mode && c[i]>=mod)c[i]-=mod;
		}
	}
	ll query(int x)const
	{
		ll ans=0;
		for(int i=x;i;i-=(i&-i))
		{
			ans+=c[i];
			if(mode && ans>=mod)ans-=mod;
		}
		return ans;
	}
	ll operator ()(int l,int r)const
	{
		ll ans=query(r)-query(l-1);
		return mode?(ans+mod)%mod:ans;
	}
}w,wa;

int main()
{
    int x,y;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	a[i]-=i;
    }
    w.mode=0;
    wa.mode=1;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x);
    	w.add(i,x);
    	wa.add(i,(ll)x*a[i]);
    }
    while(Q--)
    {
    	scanf("%d%d",&x,&y);
    	if(x<0)
    	{
    		x=-x;
    		w.add(x,y-w(x,x));
    		wa.add(x,(ll)y*a[x]-wa(x,x));
    	}
    	else
    	{
    		ll t=(w(x,y)+1)/2;
    		int l=x,r=y,mid,ans=y;
    		while(l<=r)
    		{
    			mid=(l+r)>>1;
    			if(w(x,mid)>=t)ans=mid,r=mid-1;
    			else l=mid+1;
    		}
    		//cout<<ans<<" "<<wa(x,ans)<<" "<<wa(ans+1,y)<<" ";
    		cout<<(((ll)a[ans]*w(x,ans)-wa(x,ans)-(ll)a[ans]*w(ans+1,y)
				+wa(ans+1,y))%mod+mod)%mod<<endl;
    	}
    }
    return 0;
}