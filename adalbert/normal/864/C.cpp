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

int a,b,f,k;

int next(int now)
{
    int l=0;
    int r=1e10+1;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (2*a*d+f>now+b)
            r=d; else l=d;
    }

    int an1;
    if (2*a*r+f>now+b) an1=2*a*l+f; else
        an1=2*a*r+f;

    l=1;
    r=1e10+1;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (2*a*d-f>now+b)
            r=d; else l=d;
    }

    int an2;
    if (2*a*r-f>now+b) an2=2*a*l-f; else
        an2=2*a*r-f;

    if (an2>now+b) an2=now;
    if (an1>now+b) an1=now;
    //cout<<an1<<' '<<an2<<'\n';
    return(max(an1,an2));
}

signed main()
{
    cin>>a>>b>>f>>k;
    int now=0;
    int ans=0;
    while(now+b<k*a)
    {
        ans++;
        int p=next(now);
        if (p==now)
        {
            cout<<-1;
            return(0);
        }
        now=p;
    }
    //if (now<k*a) ans++;
    cout<<ans;
}