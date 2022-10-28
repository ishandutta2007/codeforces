#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a[N];

int32_t main()
{
    IOS;
    int n, a, b;
    cin>>n>>a>>b;
    int ans=0;
    for(int i=1;i<=a;i++)
    {
    	if(n-i<=0)
    	{
    		continue;
    	}
    	int x1=a/i;
    	int x2=b/(n-i);
    	int x=min(x1, x2);
    	ans=max(ans, x);
    }
    for(int i=1;i<=b;i++)
    {
    	if(n-i<=0)
    	{
    		continue;
    	}
    	int x1=b/i;
    	int x2=a/(n-i);
    	int x=min(x1, x2);
    	ans=max(ans, x);
    }
    cout<<ans;
    return 0;
}