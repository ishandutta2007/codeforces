#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#pragma GCC optimize ("O2")
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

int a[1000];

signed main()
{
    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
        cin>>a[i];


    int s=1;
    int f=n;

    while (s!=n+1 && a[s]<=k)
        s++;

    while (f!=0 && a[f]<=k)
        f--;

    if (f==0)
        cout<<n; else
        cout<<s-1+(n-f);

}