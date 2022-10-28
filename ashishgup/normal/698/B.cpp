#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], vis[N], root[N];

int dfs(int k)
{
	if(vis[k])
		return root[k];
	vis[k]=1;
	root[k]=k;
	root[k]=dfs(a[k]);
	return root[k];
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    	dfs(a[i]);
    int ans=-1, actualroot=-1;
    for(int i=1;i<=n;i++)
    {
    	ans+=(i==dfs(a[i]));
    	if(i==a[i])
    		actualroot=i;
    }	
    if(actualroot==-1)
    {
    	ans++;
    	for(int i=1;i<=n;i++)
	    {
	    	if(i==dfs(a[i]))
	    	{
	    		actualroot=i;
	    		a[i]=i;
	    		break;
	    	}
	    }
    }
    for(int i=1;i<=n;i++)
    {
    	if(i==dfs(a[i]))
    	{
    		a[i]=actualroot;
    	}
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    	cout<<a[i]<<" ";
    return 0;
}