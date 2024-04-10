#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, ans=0;
int diag[N], diag2[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x, y;
        cin>>x>>y;
        diag[y-x+1000]++;
        diag2[x+y]++;
    }
    for(auto it:diag)
        ans+=(it*(it-1)/2);
    for(auto it:diag2)
        ans+=(it*(it-1)/2);
    cout<<ans;
    return 0;
}