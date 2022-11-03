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
typedef long long ll;
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

signed main()
{
    int n,pos,l,r;
    cin>>n>>pos>>l>>r;
    if (l==1 && r==n)
    {
        cout<<0;
    } else
    if (l==1)
    {
        cout<<abs(r-pos)+1;
    } else
    if (r==n)
    {
        cout<<abs(l-pos)+1;
    } else
    cout<<min(abs(l-pos)+abs(r-l)+2,abs(r-pos)+abs(r-l)+2);
}
/*
5
1 2 3 4 5
5
1 1
2 2
3 3
4 4
5 5
*/