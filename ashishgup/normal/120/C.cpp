#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, k;
int a[N];

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans-=(min(a[i]/k, 3) * k);
    }
    cout<<ans;
}