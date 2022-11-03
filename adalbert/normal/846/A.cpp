
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
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int a[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        ans=max(ans,(a[n]-a[i-1])+(i-1-(a[i-1])));
    }
    cout<<max(ans,n-a[n]);
}