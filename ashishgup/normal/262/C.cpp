#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], q[N];

int32_t main()
{
    IOS;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>q[i];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(q+1, q+m+1);
    sort(a+1, a+n+1);
    int ans=0;
    for(int i=n;i>=1;i-=(q[1]+2))
    {
        for(int j=i;j>max(0LL, i-q[1]);j--)
            ans+=a[j];
    }
    cout<<ans;
    return 0;
}