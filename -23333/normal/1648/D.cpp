#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=6e5;
ll a[4][N];
int n,m;
struct re{
	ll v1,v2,v3;
	void clear()
	{
		v1=v2=v3=-1e18;
	}
	re operator +(const re x)const{
		return {max(v1,x.v1),max(v2,x.v2),max({v1+x.v2,v3,x.v3})};
	}
};
vector<re> ve[N];
#define mid ((h+t)/2)
struct sgt{
	re v[N*4]; 
	void build(int x,int h,int t)
	{
		if (h==t)
		{
			v[x].v1=a[1][h]-a[2][h-1];
			v[x].v2=a[2][h]-a[3][h-1]+a[3][n];
			v[x].v3=v[x].v1+v[x].v2;
			return;
		}
		build(x*2,h,mid); build(x*2+1,mid+1,t);
		v[x]=v[x*2]+v[x*2+1];
	};
	void g(int x,int h,int t,int pos,ll k)
	{
		if (h==t)
		{
			v[x].v1=max(v[x].v1,k);
			v[x].v3=v[x].v1+v[x].v2;
			return;
		}
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
		v[x]=v[x*2]+v[x*2+1];
	}
	re q(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v[x];
		re ans; ans.clear();
		if (h1<=mid) ans=ans+q(x*2,h,mid,h1,t1);
		if (mid<t1) ans=ans+q(x*2+1,mid+1,t,h1,t1);
		return ans;
	}
}S;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,3)
	  rep(j,1,n)
	  {
	    cin>>a[i][j];
	    a[i][j]+=a[i][j-1];
	  }
	S.build(1,1,n);
	rep(i,1,m)
	{
		int x,y,z;
		cin>>x>>y>>z;
		ve[y].push_back({x,z});
	}
	ll ans=-1e18;
	rep(i,1,n)
	{
		for (auto v:ve[i])
		{
			re now=S.q(1,1,n,v.v1,i);
			if (i+1<=n) S.g(1,1,n,i+1,now.v1-v.v2);
			ans=max(ans,now.v3-v.v2);
		}
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}