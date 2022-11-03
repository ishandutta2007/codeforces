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
set<string> setik;

int a[400000];
int good[400000];
int n,k;

bool check(int d)
{
    int left=1;

    vector<int> vec;

    vec.pb(1);
    vec.pb(1e9);
    int last=0;
    for (int i=1;i<=n;i++)
    {
        while (a[i]-a[left]>d)
            left++;
        while (left>vec[last])
            last++;
        int l=vec[last];

        bool good=(l<=(i-k+1));

        if (good)
        {
            vec.pop_back();
            vec.pb(i+1);
            vec.pb(1e9);
        }

    }

    return(vec[vec.size()-2]==n+1);
}

signed main()
{
    fast;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=2e18;

    sort(a+1,a+1+n);

    int l=0;
    int r=1e12;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d))
            r=d; else l=d;
    }

    if (check(l)) cout<<l; else
        cout<<r;
}