#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int N=2e5;
int a[N],g[N];
vector<int> S[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int c=0,d=0,ans=0;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  S[a[i]].push_back(i);
    }
    rep(i,0,n) S[i].push_back(0);
    rep(i,1,n)
	{
		g[a[i]]++;
		if (a[i]==c||a[i]==d)
		{
			continue;
    	} else
    	{
    		ans++;
    		int x1,x2;
    		if (!S[c][g[c]]) x1=1e8; else x1=S[c][g[c]];
    		if (!S[d][g[d]]) x2=1e8; else x2=S[d][g[d]];
    		if (x1<x2) d=a[i]; else c=a[i];
    	}
    }
    cout<<ans<<endl;
    return 0;
}