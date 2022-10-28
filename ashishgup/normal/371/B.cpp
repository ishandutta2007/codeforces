#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

vector<int> v={2, 3, 5};
map<pair<int, int>, int> cache;

int dp(int a, int b)
{
    if(a==b)
        return 0;
    int &ans=cache[{a, b}];
    if(ans!=0)
        return ans;
    ans=1e9;
    for(auto it:v)
    {
        if(a%it==0)
            ans=min(ans, 1+dp(a/it, b));
        if(b%it==0)
            ans=min(ans, 1+dp(a, b/it));
    }
    return ans;
}

int32_t main()
{
    IOS;
    int a, b;
    cin>>a>>b;
    int ans=dp(a, b);
    if(ans>1e5)
        ans=-1;
    cout<<ans;
    return 0;   
}