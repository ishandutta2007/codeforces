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
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll
int n;
int a[400000],mn[400000],mx[400000];
void solve(int i, int l, int r)
{
    l=max(l,mn[i]);
    r=min(r,mx[i]);
    if (l>r)
    {
        cout<<-1;
        exit(0);
    }

    if (i==n)
    {
        a[i]=r;
        return;
    }

    solve(i+1,l-1,r+1);
    a[i]=min(r,a[i+1]+1);
    if (a[i]<l || abs(a[i]-a[i+1])>1)
    {
        cout<<-1;
        exit(0);
    }
}

signed main()
{

    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>mn[i]>>mx[i];
        mx[i]+=mn[i];
    }

    solve(1,-1e9,1e9);

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        ans+=a[i]-mn[i];
        if (a[i]>mx[i] || a[i]<mn[i])
        {
            cout<<-1;
            return(0);
        }
    }

    cout<<ans<<'\n';
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}