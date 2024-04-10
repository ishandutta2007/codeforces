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
const int arr=6e5;

int sum[arr],a[arr];
int n,r,k;
bool check(int u)
{
    for (int i=1;i<=n+1;i++)
        sum[i]=0;
    for (int i=1;i<=n;i++)
    {
        sum[max(ll(1),i-r)]+=a[i];
        sum[min(n+1,i+r+1)]-=a[i];
    }
    sum[1]-=u;
    int now=0;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        now+=sum[i];
        if (now<0)
        {
            res-=now;
            sum[min(n+1,i+2*r+1)]+=now;
            now=0;
            if (res>k)
                return(0);
        }
    }
    return(res<=k);
}

signed main()
{

    cin>>n>>r>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int l=0;
    int r=2e18;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d))
            l=d; else r=d;
    }

    cout<<l;
}
/*
*/