#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5;
int n,m;
ll a[N],b[N],sum[N],ans[N];
pair<ll,int> c[N];
struct re{
	int a,b;
};
const int mo=1e9+7;
vector<re>ve[N];
#define mid ((h+t)/2)
struct sgt{
	ll v[N*4];
	void clear()
	{
		memset(v,0,sizeof(v));
	}
	void g(int x,int h,int t,int pos,ll k)
	{
		(v[x]+=k)%=mo;
		if (h==t) return;
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
	}
	ll q(int x,int h,int t,int h1,int t1)
	{
		ll ans=0;
		if (h1<=h&&t<=t1) return v[x];
		if (h1<=mid) ans=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans+=q(x*2+1,mid+1,t,h1,t1);
		ans%=mo;
		return ans; 
	}
}S1,S2;
void solve()
{
	rep(i,0,n) c[i]={-sum[i],-i};
	sort(c,c+n+1);
	rep(i,0,n)
	{
		int x=-c[i].second;
		for(auto v:ve[x+1])
		{
		  (ans[v.b]+=S1.q(1,1,n,x+1,v.a-1)-S2.q(1,1,n,x+1,v.a-1)*(sum[x]%mo))%=mo; 
	    }
	    S1.g(1,1,n,x,(a[x+1]-a[x])*(sum[x]%mo));
	    S2.g(1,1,n,x,(a[x+1]-a[x]));
	}
	S1.clear(); S2.clear();
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) { cin>>b[i]; sum[i]=sum[i-1]+b[i];}
	rep(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		ve[x].push_back({y,i});
	}
	solve();
	rep(i,1,n) b[i]=-b[i],sum[i]=-sum[i];
	solve();
	rep(i,1,m) cout<<(ans[i]%mo+mo)%mo<<endl;
	return 0;
}
/*
5 1
2 4 5 9 10
-1 1 -3 2 1
1 5
*/