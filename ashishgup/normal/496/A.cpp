#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, ans=0, extra=1005;
int a[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>=2)
            ans=max(ans, a[i]-a[i-1]);
    }
    for(int i=2;i<=n-1;i++)
    {
        extra=min(extra, a[i+1]-a[i-1]);
    }
    ans=max(ans, extra);
    cout<<ans;
    return 0;
}