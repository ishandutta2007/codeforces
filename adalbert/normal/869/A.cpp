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

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i];
        use[x[i]]=1;
    }

    for (int i=1;i<=n;i++)
    {
        cin>>y[i];
        use[y[i]]=1;
    }

    int res=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
             res+=use[x[i]^y[j]];
        }


    if (res%2)
    cout<<"Koyomi"; else
    cout<<"Karen";

}