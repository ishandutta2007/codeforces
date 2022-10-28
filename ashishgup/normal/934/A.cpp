#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], b[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {   
        int curmax=-1e18;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
                continue;
            for(int k=1;k<=m;k++)
            {
                curmax=max(curmax, a[j]*b[k]);
            }
        }
        ans=min(ans, curmax);
    }
    cout<<ans;
    return 0;
}