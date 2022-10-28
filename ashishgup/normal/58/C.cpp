#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, cur=0;
int a[N];
map<int, int> m;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int l=1, r=n; l<=r; l++, r--)
    {
        m[a[l]-cur]++;
        if(r!=l)
            m[a[r]-cur]++;
        cur++;
    }
    int ans=0;
    for(auto it:m)
    {
        if(it.first>0)
            ans=max(ans, it.second);
    }
    ans=n-ans;
    cout<<ans;
    return 0;
}