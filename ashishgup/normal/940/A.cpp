#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, d;
int a[N];

int32_t main()
{
    IOS;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        auto it=upper_bound(a+i, a+n+1, a[i]+d);
        int index=it-(a);
        int remove=n+1-index;
        ans=min(ans, remove + i-1);
    }
    cout<<ans;
    return 0;
}