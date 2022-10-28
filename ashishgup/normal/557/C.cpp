#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, ans=1e9, total=0;
int l[N], d[N], f[N];
vector<int> g[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>l[i];
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>d[i];
    	total+=d[i];
    	f[d[i]]++;
    	g[l[i]].push_back(d[i]);
    }
    for(int i=1e5;i>=1;i--)
    {
    	if(!g[i].size())
    		continue;
    	int curans=total;
    	for(auto it:g[i])
    	{
    		curans-=it;
    		f[it]--;
    	}
    	int sz=g[i].size();
    	int remove=sz-1;
    	int val=0;
    	for(int j=200;j>=1;j--)
    	{
    		int store=min(f[j], remove);
    		val+=store*j;
    		remove-=store;
    	}
    	ans=min(ans, curans-val);
    }
    cout<<ans;
    return 0;
}