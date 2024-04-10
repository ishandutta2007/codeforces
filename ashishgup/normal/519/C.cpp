#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(2*i>m)
            break;
        int remn=n-i;
        int remm=m-2*i;
        int otherteams=min(remn/2, remm);
        ans=max(ans, i+otherteams);
    }
    cout<<ans;
    return 0;
}