#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3005;

int n;
int s[N], c[N], cache[N][N][5];

int dp(int i, int prev, int cnt)
{
    if(cnt==4)
        return 0;
    if(i==n+1)
        return 3e8+1;
    int &ans=cache[i][prev][cnt];
    if(ans!=-1)
        return ans;
    ans=dp(i+1, prev, cnt);
    if(s[i]>s[prev])
        ans=min(ans, c[i] + dp(i+1, i, cnt+1));
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]; 
    for(int i=1;i<=n;i++)
        cin>>c[i];  
    int ans=dp(1, 0, 1); 
    if(ans>3e8)
        ans=-1;
    cout<<ans;
    return 0;
}