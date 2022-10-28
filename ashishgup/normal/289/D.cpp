#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, k;
int ans=1, ans2=0;
int v[N];

int pow(int a, int b, long long m)
{
    int ans=1; 
    while(b>0)
    { 
        if(b%2==1) 
            ans=(ans*a)%m; 
        b/=2; 
        a=(a*a)%m; 
    } 
    return ans%m; 
}
 
void dfs(int i)
{
    if(i==k+1)
    {
        int check=1;
        for(int j=1;j<=k;j++)
        {
            int cur=j;
            int vis[k+1];
            memset(vis, 0, sizeof(vis));
            while(cur!=1 && !vis[cur])
            {
                vis[cur]=1;
                cur=v[cur];
            }
            if(cur!=1)
                check=0;
            if(!check)
                return;
        }
        if(check)
            ans2++;
        return;
    }
    for(int j=1;j<=k;j++)
    {
        v[i]=j;
        dfs(i+1);
    }
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    ans=pow(n-k, n-k, MOD);
    ans=max(ans, 1LL);
    dfs(1);
    ans*=ans2;
    ans%=MOD;
    cout<<ans;
    return 0;
}