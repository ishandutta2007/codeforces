#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
const int mo=1e9+7;
ll f[N];
int col[N];
unordered_map<ll,int> M;
//map<pair<ll,int>,int> P;
int P[N][7];
ll dfs(ll x,int y,int z)
{
	if (!M[x]) return f[z];
	if (M[x])
	{
		if (P[M[x]][y]) return P[M[x]][y]-1;
		if (col[M[x]]&&col[M[x]]!=y) return 0;
		if (z==1) return 1;
		ll ans=0;
		rep(j,1,6)
		  rep(k,1,6)
		    if (j!=y&&j+y!=7&&k!=y&&k+y!=7)
		      (ans+=dfs(x*2,j,z-1)*dfs(x*2+1,k,z-1))%=mo;
		P[M[x]][y]=ans+1;
		return ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int k,n;
	cin>>k;
	f[1]=1;
	rep(i,2,k)
	  f[i]=f[i-1]*f[i-1]%mo*16%mo;
	cin>>n;
	int cnt=0; 
	rep(i,1,n)
	{
		ll x,x2;
		cin>>x;
		x2=x;
		char c[10];
		cin>>c;
		while (x)
		{
			if (!M[x]) M[x]=++cnt;
			x=x/2;
		}
		x=x2;
		if (c[0]=='w') col[M[x]]=1;
		if (c[0]=='y') col[M[x]]=6;
		if (c[0]=='g') col[M[x]]=2;
		if (c[0]=='b') col[M[x]]=5;
		if (c[0]=='r') col[M[x]]=3;
		if (c[0]=='o') col[M[x]]=4;
	}
	ll ans=0;
	rep(i,1,6)
	  (ans+=dfs(1,i,k))%=mo;
	cout<<ans<<endl;
//	cout<<f[k]*6%mo<<endl; 
	return 0;
}