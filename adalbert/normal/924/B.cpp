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

int e[200000];

signed main()
{
    fast;
    int n,u;
    cin>>n>>u;
    for (int i=1;i<=n;i++)
        cin>>e[i];

    int last=1;
    bool ch=0;
    ld res=0;
    for (int i=1;i<=n;i++)
    {
        while(last+1<=n && e[last+1]-e[i]<=u)
            last++;
        if (last-i+1>=3)
        {
            res=max(res,ld(e[last]-e[i+1])/ld(e[last]-e[i]));
            ch=1;
        }
    }

    if (!ch)
        cout<<-1; else
    cout<<fixed<<setprecision(9)<<res<<'\n';
}
/*
*/