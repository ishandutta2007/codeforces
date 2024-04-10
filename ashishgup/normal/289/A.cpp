#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;

int32_t main()
{
    IOS;
    cin>>n>>k;
    int value=0;
    for(int i=1;i<=n;i++)  
    {
        int l, r;
        cin>>l>>r;
        value+=(r-l+1);
    }  
    int ans=k - value%k;
    if(ans==k)
        ans=0;
    cout<<ans;
    return 0;
}