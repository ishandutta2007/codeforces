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
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int dp[2100][1100];
int a[2100],b[2100];


int n,k,p;

bool check(int u)
{
    int l=1;
    for (int i=1;i<=n;i++)
    {
        if (l>k) return(0);
        while (abs(a[i]-b[l])+abs(p-b[l])>u)
        {
            l++;
            if (l>k) return(0);
        }
        l++;
    }
    return(1);
}

signed main()
{
    cin>>n>>k>>p;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=k;i++)
        cin>>b[i];

    sort(a+1,a+1+n);
    sort(b+1,b+1+k);

    int l=0;
    int r=1e16;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d)) r=d; else l=d;
    }
    if (check(l)) cout<<l; else cout<<r;
}