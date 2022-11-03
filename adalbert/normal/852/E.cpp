#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg
#define int ll
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;
typedef long double ld;
const int arr=2*1e6;

const int md=1e9+7;

int dp[arr];

int ans=0;
vector<int> vec[arr];

void dfs(int u, int pred)
{
    dp[u]=2;

    bool ch=1;
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]!=pred)
        {
            ch=0;
            dfs(vec[u][i],u);
            dp[u]*=dp[vec[u][i]];
            dp[u]%=md;
        }
    if (ch)
        dp[u]=1;
}

int pow_(int u, int step)
{
    u%=md;
    if (step==1) return(u); else
    if (step%2) return(pow_(u,step-1)*u%md); else
    return(pow_(u*u%md,step/2));
}

void solve(int u, int pred, int f)
{
    int res=f*2;
    res%=md;
    for (int i=0;i<vec[u].size();i++)
    if (vec[u][i]!=pred)
    {
        res*=dp[vec[u][i]];
        res%=md;
    }
    ans+=res;
    ans%=md;

    if (pred==0 && vec[u].size()==1)
    {
        res=res*pow_(2,md-2);
        res%=md;
    }
    for (int i=0;i<vec[u].size();i++)
    if (vec[u][i]!=pred)
    {
        solve(vec[u][i],u,res*pow_(dp[vec[u][i]]%md,md-2)%md);
    }
}

signed main()
{
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<1;
        return(0);
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    dfs(1,0);

    solve(1,0,1);

    cout<<ans<<'\n';
}