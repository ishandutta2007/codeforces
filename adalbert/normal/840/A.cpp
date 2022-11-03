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
const int arr=3*1e5;

int ans[arr],a[arr];
pair<int,int> b[arr];
signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
         cin>>b[i].fir;
         b[i].sec=i;
    }
    sort(b+1,b+1+n);
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);

    for (int i=1;i<=n;i++)
    {
        ans[b[i].sec]=a[i];
    }
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}