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

int a[110000];

signed main()
{
    int n,k;
    cin>>n>>k;

    int mx=-1;
    int imx=0;

    for (int i=1;i<=k;i++)
    {
        cin>>a[i];
        if (n/a[i]*a[i]>mx)
        {
            mx=n/a[i]*a[i];
            imx=i;
        }
    }

    cout<<imx<<' '<<n/a[imx];
}