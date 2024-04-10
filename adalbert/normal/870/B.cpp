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
#define files() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

int a[200000],smn[200000],pmn[200000];

signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec;

    int mn=1e18;
    int mx=-1e18;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }

    if (k==1)
    {
        cout<<mn;
    } else
    if (k>=3)
    {
        cout<<mx;
    } else
    {
        pmn[1]=a[1];
        for (int i=2;i<=n;i++)
            pmn[i]=min(pmn[i-1],a[i]);

        smn[n]=a[n];
        for (int i=n-1;i>=1;i--)
            smn[i]=min(smn[i+1],a[i]);

        int ans=-1e18;
        for (int i=1;i<n;i++)
        {
            ans=max(ans,max(pmn[i],smn[i+1]));
        }

        cout<<ans;
    }



}

/*
5 3
-4 -5 -3 -2 -1
*/

///https://ideone.com/eRRJ67