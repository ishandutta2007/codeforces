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

int dp1[200000],dp2[200000],dp3[200000],a[200000];

signed main()
{
    int n,p,q,r;
    cin>>n>>p>>q>>r;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
    {
        dp1[i]=p*a[i];
        if (i>1)
            dp1[i]=max(dp1[i],dp1[i-1]);
    }

    for (int i=1;i<=n;i++)
    {
        dp2[i]=q*a[i]+dp1[i];
        if (i>1)
            dp2[i]=max(dp2[i],dp2[i-1]);
    }

    for (int i=1;i<=n;i++)
    {
        dp3[i]=r*a[i]+dp2[i];
        if (i>1)
            dp3[i]=max(dp3[i],dp3[i-1]);
    }


    cout<<dp3[n];
}
/*
5 1 -3 2
-1 -2 -3 -4 -5
*/