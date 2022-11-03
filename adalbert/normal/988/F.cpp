#include<bits/stdc++.h>
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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5+100;

int rain[arr],mas[arr],dp[arr],x[arr],p[arr];

signed main()
{
    int a,n,m;

    cin>>a>>n>>m;

    for (int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        r--;
        for (int j=l;j<=r;j++)
            rain[j]=1;
    }

    for (int i=0;i<=a;i++)
        mas[i]=1e18;
    for (int i=1;i<=a;i++)
        dp[i]=1e18;

    for (int i=1;i<=m;i++)
    {
        cin>>x[i]>>p[i];
        mas[x[i]]=min(mas[x[i]],p[i]);
    }

    for (int i=0;i<a;i++)
    {
        if (dp[i]==1e18)
            continue;
        if (!rain[i])
            dp[i+1]=min(dp[i+1],dp[i]);
        if (mas[i]!=1e18)
            for (int j=i+1;j<=a;j++)
            dp[j]=min(dp[j],dp[i]+abs(i-j)*mas[i]);
    }

    if (dp[a]==1e18)
        cout<<-1; else
        cout<<dp[a];
}