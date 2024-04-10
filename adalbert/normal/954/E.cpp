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

ld a[300000],t[300000];

bool check(int i, int j)
{
    return(abs(t[i])<abs(t[j]));
}

signed main()
{
    fast;
    int n,tt;
    cin>>n>>tt;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    ld res=0;
    vector<int> vec1, vec2;

    for (int i=1;i<=n;i++)
    {
        cin>>t[i];
        t[i]-=tt;
        if (abs(t[i])<1e-7)
        {
            res+=a[i];
        } else
        if (t[i]<0)
            vec1.pb(i); else
            vec2.pb(i);
    }

    ld sum1=0,sum2=0;

    for (auto i:vec1)
        sum1-=a[i]*t[i];
    for (auto i:vec2)
        sum2+=a[i]*t[i];

    if (sum1>sum2)
    {
        sort(vec1.begin(),vec1.end(),check);
        for (auto i:vec1)
        {
            ld now=min(a[i],sum2/abs(t[i]));
            res+=now;
            sum2-=abs(t[i])*now;
        }
        for (auto i:vec2)
            res+=abs(a[i]);
    } else
    {
        sort(vec2.begin(),vec2.end(),check);
        for (auto i:vec2)
        {
            ld now=min(a[i],sum1/abs(t[i]));
            res+=now;
            sum1-=abs(t[i])*now;
        }
        for (auto i:vec1)
            res+=a[i];
    }
    cout<<fixed<<setprecision(9)<<res<<'\n';
}
/*

*/