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
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

int a[500000],suf[500000],pred[500000],last[500000];

map<int,int> mp;

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=1;i<=n;i++)
    {

        for (int j=0;j<=32;j++)
            if ((a[i]&(1ll<<j))!=0)
            last[j]=i; else
            pred[i]=max(pred[i],last[j]);
    }

    for (int i=0;i<=32;i++)
    {
        last[i]=n+1;
    }

    for (int i=1;i<=n;i++)
        suf[i]=n+1;

    for (int i=n;i>=1;i--)
    {
        for (int j=0;j<=32;j++)
            if ((a[i]&(1ll<<j))!=0)
            last[j]=i; else
            suf[i]=min(suf[i],last[j]);
    }

    int ans=n*(n-1)/2;

    int las=0;
    for (int i=1;i<=n;i++)
    {
        pred[i]=max(pred[i],mp[a[i]]);
        mp[a[i]]=i;
        ans-=(i-pred[i])*(suf[i]-i)-1;
    }


    cout<<ans;
}
/*
1
2 1
2 10 100
2 100 10
2 1 10
2 1 5
1 1 2 2
*/