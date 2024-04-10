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
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;

int bpow(int u, int step)
{
    if (step==0)
        return(1); else
    if (step%2)
        return(bpow(u,step-1)*u%md); else
        return(bpow(u*u%md,step/2));
}

int a[200000],b[200000],rev[200000];

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int j=1;j<=n;j++)
        cin>>b[j];


    rev[m]=bpow(m,md-2);
    rev[2]=bpow(2,md-2);

    int now=1;
    int res=0;

    for (int i=1;i<=n;i++)
    {
        if (a[i]==0 && b[i]==0)
        {
            res+=now*m%md*(m-1)%md*rev[2]%md*rev[m]%md*rev[m]%md;
            res%=md;
            now=now*rev[m]%md;
        } else
        if (a[i]==0)
        {
            res+=now*(m-b[i])%md*rev[m]%md;
            res%=md;
            now=now*rev[m]%md;
        } else
        if (b[i]==0)
        {
            res+=now*(a[i]-1)%md*rev[m]%md;
            res%=md;
            now=now*rev[m]%md;
        } else
        {
            if (a[i]>b[i])
            {
                res+=now;
                res%=md;
                break;
            } else
            if (a[i]<b[i])
            {
                break;
            }
        }
    }

    cout<<res%md;
}
/*
1 2
0
0

*/