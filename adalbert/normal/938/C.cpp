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

const int arr=2e5;

bool check(int a, int b)
{
    if (a>b)
        swap(a,b);
    if ((a+b)%2)
        return(0);
    int n=(a+b)/2;
    int nn=b-n;

    if (n<=0)
        return(0);

    if (nn>n)
        return(0);

    int l=1;
    int r=n;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (n/d>nn)
            l=d; else r=d;
    }

    if (n/l==nn)
    {

        cout<<n<<' '<<l<<'\n';
        return(1);
    }
    if (n/r==nn)
    {
        cout<<n<<' '<<r<<'\n';
        return(1);
    }

    return(0);

}

void solve()
{
    int n;
    cin>>n;
    if (n==0)
    {
        cout<<1<<' '<<1<<'\n';
        return;
    }

    for (int i=1;i*i<=n;i++)
        if (n%i==0)
    {
        if (check(i,n/i))
            return;
    }
    cout<<-1<<'\n';
}

signed main()
{
    int t;
    cin>>t;
    while (t--)
        solve();
}
/*

*/