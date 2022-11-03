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

const int arr=1600;
const int md=1e9+7;

int a[500000];

signed main()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    for (int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        if (2*a[i]>=sum)
        {
            cout<<i;
            return(0);
        }
    }
}