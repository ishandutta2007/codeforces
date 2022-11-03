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

int n,tim;

struct Node
{
    int fir,sec,nom;
};

const bool operator < (const Node &i, const Node &j)
{
    return(i.fir<j.fir);
};

Node a[arr];

bool check(int u)
{
    int now=tim;
    int ans=0;
    for (int i=1;i<=n;i++)
        if (u<=a[i].sec)
    {
        if (now>=a[i].fir)
        {
            now-=a[i].fir;
            ans++;
        }
    }

    return(ans>=u);
}

signed main()
{
    cin>>n>>tim;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].sec>>a[i].fir;
        a[i].nom=i;
    }


    sort(a+1,a+1+n);

    int l=0;
    int r=n;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d))
            l=d; else r=d;
    }

    int res=0;
    if (check(r))
        res=r; else
        res=l;

    cout<<res<<'\n';

    vector<int> vec;

    for (int i=1;i<=n;i++)
        if (res<=a[i].sec)
        {
            if (tim>=a[i].fir)
            {
                tim-=a[i].fir;
                if (vec.size()<res)
                vec.pb(a[i].nom);
            }
        }

    cout<<vec.size()<<'\n';
    for (auto i:vec)
        cout<<i<<' ';
}