#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll T,n,m;
const int N=1e6+10;
char s[N];
int a[N],b[N],vis[N];
ll ans=0;
vector<int> ve[N];
void dfs(int x,int cnt)
{
	vis[x]=1; bool tt=0;
	for(auto v:ve[x])
	  if (!vis[v])
	  { 
	    dfs(v,cnt+1); 
	    tt=1;
	  }
	if (!tt)
	{
		if (cnt%2==1) ans++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ans=0;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) cin>>b[i];
		rep(i,1,n) ve[i].clear(),vis[i]=0;
		rep(i,1,n)
		{
			  ve[a[i]].push_back(b[i]);
			  ve[b[i]].push_back(a[i]);
		}
		rep(i,1,n)
		  if (!vis[i]) dfs(i,1);
		int t=(n-ans)/2;
		assert((n-ans)%2==0);
		ll ans=0;
		rep(i,1,t) ans-=2*i;
		rep(i,n-t+1,n) ans+=2*i;
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
6
3 5 4 6 2 1
3 6 4 5 2 1
*/