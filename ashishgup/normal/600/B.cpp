#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int a[N], b[N];

int32_t main()
{
    IOS;
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
    	cin>>b[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=m;i++)
    {
    	int ans=upper_bound(a+1, a+n+1, b[i])-(a+1);
    	cout<<ans<<" ";
    }
    return 0;
}