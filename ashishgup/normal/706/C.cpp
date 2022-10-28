#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], cache[N][2];
string s[N][2]; //0 = Not reverse, 1 = reversed

int dp(int idx, int rev)
{
    if(idx==n+1)
        return 0;
    int &ans=cache[idx][rev];
    if(ans!=-1)
        return ans;
    ans=1e15;
    if(s[idx][0]>=s[idx-1][rev])
        ans=min(ans, dp(idx+1, 0));
    if(s[idx][1]>=s[idx-1][rev])
        ans=min(ans, a[idx] + dp(idx+1, 1));
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0];
        s[i][1]=s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    int ans=min(dp(2, 0), a[1] + dp(2, 1));
    if(ans>1e14)
        ans=-1;
    cout<<ans;
    return 0;
}