#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0, leastodd=N*N;
int a[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
        if(a[i]%2)
            leastodd=min(leastodd, a[i]);
    }
    if(ans%2)
        ans-=leastodd;
    cout<<ans;
    return 0;
}