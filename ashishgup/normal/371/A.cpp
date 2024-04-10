#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, ans=0;
int a[N], f[3][N];

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]][i%k]++;
    }
    for(int i=0;i<k;i++)
        ans+=min(f[1][i], f[2][i]);
    cout<<ans;
    return 0;   
}