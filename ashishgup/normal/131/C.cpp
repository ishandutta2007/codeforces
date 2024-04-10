#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int cache[N][N];

int n, m, t;

int nCr(int n, int r)
{
    if(r==0)
        return 1;
    if(n==r)
        return 1;
    int &ans=cache[n][r];
    if(ans!=-1)
        return ans;
    ans=nCr(n-1, r-1) + nCr(n-1, r);
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n>>m>>t;
    int ans=0;
    for(int i=4;i<=min(n, t);i++)
    {
        if(t-i<=0)
            break;
        if(t-i>m)
            continue;
        ans+=nCr(n, i)*nCr(m, t-i);
    }
    cout<<ans;
    return 0;
}