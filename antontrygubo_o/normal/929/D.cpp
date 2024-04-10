#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n, st, fi, inf=10000000000, inf1=1000000;
ll g[100010], col[100010];
vector<ll> g_col[100010];
ll ans[100010];

int main()
{
	cin >> n >> st >> fi; st--; fi--;
	for (ll i=0; i<n-1; i++)
	  cin >> g[i];
	for (ll i=0; i<n; i++)
	  cin >> col[i];
	for (ll i=0; i<n; i++)
	  g_col[col[i]].push_back(i);
	ans[st]=0;
	for (ll i=st+1; i<n; i++)
    {
       ll r=upper_bound(g_col[g[i-1]].begin(), g_col[g[i-1]].end(), st-1)-g_col[g[i-1]].begin();
       if (r!=g_col[g[i-1]].size() && g_col[g[i-1]][r]>=st && g_col[g[i-1]][r]<i)
       {
       	 ans[i]=ans[i-1];
         continue;
       }
       else
       {
       	  ll l=lower_bound(g_col[g[i-1]].begin(), g_col[g[i-1]].end(), st)-g_col[g[i-1]].begin();
       	  if (l!=0 && g_col[g[i-1]][l-1]<st)
       	    ans[i]=max(ans[i-1], st-g_col[g[i-1]][l-1]);
       	  else
       	    ans[i]=inf;
	   }
	}
	for (ll i=st-1; i>=0; i--)
	{
		ll l=lower_bound(g_col[g[i]].begin(), g_col[g[i]].end(), st+1)-g_col[g[i]].begin();
		ll r=upper_bound(g_col[g[i]].begin(), g_col[g[i]].end(), st)-g_col[g[i]].begin();
		if (l!=0 && g_col[g[i]][l-1]<=st && g_col[g[i]][l-1]>i)
		{
			ans[i]=ans[i+1];
			continue;
		}
		else
		{
			if (r!=g_col[g[i]].size() && g_col[g[i]][r]>st)
			  ans[i]=max(ans[i+1], g_col[g[i]][r]-st);
			else
			  ans[i]=inf;
		}
	}
	ll answer=abs(fi-st), lef=-inf1, rig=inf1, i=(fi>st ? 1 : 0);
	while (fi!=st)
	{
		answer+=ans[fi]*2; 
		if (i==1 && rig<=fi)
		{
			cout << -1; 
			return 0;
		}
		if (i==0 && lef>=fi)
		{
		    cout << -1; 
			return 0;	
		} 
		if (i==1)
		{
			i=0; rig=fi; 
			if (ans[fi]>=0 && ans[fi]<n) fi=st-ans[fi];
			else { cout << -1; return 0; }
		}
		else if (i==0)
		{
			i=1; lef=fi; 
			if (ans[fi]>=0 && ans[fi]<n) fi=st+ans[fi];
			else { cout << -1; return 0; }
		}
	}
	if (answer<inf)
	  cout << answer;
	else
	  cout << -1;
}