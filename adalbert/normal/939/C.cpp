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

int a[310000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int s,f;
    cin>>s>>f;
    f--;
    for (int i=n+1;i<=2*n;i++)
        a[i]=a[i-n];
    for (int i=1;i<=2*n;i++)
        a[i]+=a[i-1];

    int mx=-1;
    int rans=0;

    for (int i=1;i<=n;i++)
    {
        int left=s-i+1;
        int right=f-i+1;
        if (left<=0)
        {
            left+=n;
            right+=n;
        }

        if (a[right]-a[left-1]>mx)
        {
            mx=a[right]-a[left-1];
            rans=i;
        }
    }

    cout<<rans;
}