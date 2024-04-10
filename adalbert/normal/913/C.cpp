#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef unsigned long long ll;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///

vector<int> vec[arr];
int c[100];
bool get(int u, int c)
{
    return(u&(ll(1)<<c));
}

signed main()
{
    int n,l;
    cin>>n>>l;
    for (int i=1;i<=n;i++)
        cin>>c[i];
    for (int i=n+1;i<=40;i++)
        c[i]=1e18;
    n=40;
    for (int i=2;i<=n;i++)
        c[i]=min(c[i],c[i-1]*2);

    int cost=0;
    for (int i=1;i<=n;i++)
        if (get(l,i-1))
        cost+=c[i]; else
        cost=min(cost,c[i]);

    cout<<cost<<'\n';
}