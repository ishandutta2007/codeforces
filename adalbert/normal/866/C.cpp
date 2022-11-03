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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define int ll

int n,r;

ld p[600],dp[55][55*101];
int s[600],f[600];

ld get(ld u)
{
    for (int i=0;i<=n*101;i++)
        if (i<=r)
        dp[n][i]=0; else
        dp[n][i]=1e9;

    for (int i=n-1;i>=0;i--)
        for (int j=0;j<=10000;j++)
        {
            ld fas=(min(dp[i+1][j+f[i+1]],u)+f[i+1])*(p[i+1]);
            ld slow=(min(dp[i+1][j+s[i+1]],u)+s[i+1])*(1.0-p[i+1]);

            dp[i][j]=fas+slow;
        }
    return(dp[0][0]);
}

signed main()
{
    cin>>n>>r;

    for (int i=1;i<=n;i++)
    {
        cin>>f[i]>>s[i]>>p[i];
        p[i]/=100.0;
    }

    ld l=0.0;
    ld r=1e9;
    int cnt=100;
    while (cnt--)
    {
        ld d=(l+r)/2.0;
        if (get(d)>d) l=d; else r=d;
    }
    cout<<fixed<<setprecision(9)<<l<<'\n';
}
/*
4
6 1
3 1
3 0
0 3
3
9 3
2 3
6 5
*/