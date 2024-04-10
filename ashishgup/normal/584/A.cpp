#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, t;
    cin>>n>>t;
    if(t==10)
    {
        if(n==1)
        {
            cout<<"-1";
            return 0;
        }
        n--;
    }
    cout<<t;
    for(int i=1;i<=n-1;i++)
        cout<<"0";
    return 0;   
}