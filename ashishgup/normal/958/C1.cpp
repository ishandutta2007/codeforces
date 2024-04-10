#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, p;
int a[N], pref[N];

int32_t main()
{
    IOS;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int left=pref[i];
        int right=pref[n]-left;
        ans=max(ans, (left%p) + (right%p));
    }
    cout<<ans;
    return 0;
}