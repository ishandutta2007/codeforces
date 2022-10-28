#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n;
int f[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        f[u]++;
        f[v]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(f[i]==1);
    cout<<ans;
    return 0;
}