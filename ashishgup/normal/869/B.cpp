#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int a, b;
    cin>>a>>b;
    int ans=1;
    for(int i=a+1;i<=b;i++)
    {
        ans*=(i%10);
        ans%=10;
        if(ans==0)
            break;
    }
    cout<<ans;
    return 0;
}