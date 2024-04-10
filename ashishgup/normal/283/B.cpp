#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];
int cache[N][2];

int dp(int x, int sign)
{
    if(x<=0 || x>n)
        return 0;
    int &ans=cache[x][sign];
    if(ans!=-1)
        return ans;
    ans=-1e13;
    if(!sign)
        ans=a[x] + dp(x+a[x], sign^1);
    else
        ans=a[x] + dp(x-a[x], sign^1);
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        int ans=i + dp(i+1, 1);
        if(ans<0)
            ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}