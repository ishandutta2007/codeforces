
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

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define int ll

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int dp[arr],cost[arr];

signed main()
{
    int n,k,m;
    cin>>n>>k>>m;

    for (int i=1;i<=k;i++)
        cin>>cost[i];
    sort(cost+1,cost+1+k);
    for (int i=1;i<=k;i++)
        cost[i]+=cost[i-1];

    for (int i=1;i<=1e5;i++)
        dp[i]=1e18;

    for (int i=1;i<=n;i++)
    {
        for (int now=n*(k+2);now>=0;now--)
            for (int take=0;take<=k;take++)
                dp[now+take+(take==k)]=min(dp[now+take+(take==k)],dp[now]+cost[take]);
    }

    int ans=0;

    for (int i=0;i<=n*(k+2);i++)
        if (dp[i]<=m) ans=i;
    cout<<ans;
}