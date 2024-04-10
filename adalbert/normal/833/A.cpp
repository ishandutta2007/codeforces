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
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
#define int ll
int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b) a%=b; else
        b%=a;
    return(a+b);
}

void solve()
{
    int a,b;
    cin>>a>>b;
    int k=a*b;
    int l=1;
    int r=1000000;
    //cout<<r<<'\n';
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (d*d*d>k) r=d; else l=d;
    }

    int res=0;
    if (l*l*l==k)
        res=l;
    if (r*r*r==k)
        res=r;
    if (res==0)
    {
        cout<<"No"<<'\n';
        return;
    }
    if (a%res!=0)
    {
        cout<<"No"<<'\n';
        return;
    }
    if (b%res!=0)
    {
        cout<<"No"<<'\n';
        return;
    }

    int x=a/res;
    int y=b/res;

    if (a!=x*x*y || b!=y*y*x)
    {
        cout<<"No"<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
}

signed main()
{
    fast;
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
}