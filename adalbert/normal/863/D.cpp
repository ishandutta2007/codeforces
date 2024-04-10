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

typedef long long ll;

#define int ll

int a[200000],t[200000],l[200000],r[200000];

signed main()
{
    int n,q,m;
    cin>>n>>q>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=q;i++)
        cin>>t[i]>>l[i]>>r[i];

    while (m--)
    {
        int p;
        cin>>p;
        for (int i=q;i>=1;i--)
        {
            if (p<l[i] || p>r[i]) continue;
            if (t[i]==1)
            {
                if (p==l[i]) p=r[i]; else
                    p--;
            } else
            {
                p=r[i]-abs(l[i]-p);
            }
            //cout<<p<<'\n';
        }
        cout<<a[p]<<' ';
    }
}