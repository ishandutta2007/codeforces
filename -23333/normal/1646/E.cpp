#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll n,m;
const int N=2e6;
struct re{
	int a,b;
};
bool f[N];
/*int solve(int x,vector<int> ve,int y)
{
	int nn=ve.size();
	int ans=y/x;
	rep(i,1,(1<<nn)-1)+
	{
		ll now=1; int tt=1;
		rep(j,0,nn-1)
		  if ((i>>j)&1)  {now*=ve[j]; tt=-tt;}
		ans+=tt*y/(now*x);
	}
	return ans;
} */
ll gcd(ll x,ll y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	//n=1e6;
	ll ans=1;
	rep(i,2,n)
	if (!f[i])
	{
		ll now=i;
		int cnt=1;
		while (now<=n)
		{
		    now=now*i; 
			if (now<=n) f[now]=1;
			cnt++;
		}
		cnt--;
		rep(i,1,(1<<cnt)-1)
		{
			ll gg=1; int mn=1e9;
			int t=-1;
			for(int j=1;j<=cnt;j++)
			  if ((i>>(j-1))&1)
			  {
			  	 t=-t;
			  	 gg=gg*j/gcd(gg,j);
			  	 mn=min(mn,j);
			  }
			ans+=t*(m/(gg/mn));
		}
	}
	cout<<ans<<endl;
	return 0;
}