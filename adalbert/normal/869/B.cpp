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

#define int ll

bool use[4000000];
int x[4000],y[4000];

int get(int l, int r)
{
    int ans=1;
    for (int i=l+1;i<=r;i++)
        ans*=i;
    return(ans);
}

signed main()
{
    int l,r;
    cin>>l>>r;
    l++;
    if (r-l<20)
    {
        int res=1;
        for (int i=l;i<=r;i++)
        {
            res*=i;
            res%=10;
        }
        cout<<res;
    } else
    cout<<0;
}