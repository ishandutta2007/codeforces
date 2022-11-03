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
const int arr=4e5;
const int md=1e18+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///

int n,nn;

int a[40];
int cnt=0;

vector<int> vec1,vec2;

void gen1(int u, int last)
{
    if (last>nn)
        return;
    cnt++;
    int nxt=u*a[last];
    if (nxt/a[last]==u)
    {
        vec1.pb(nxt);
        gen1(nxt,last);
    }


    gen1(u,last+1);
}
void gen2(int u, int last)
{
    if (last>nn)
        return;
    cnt++;
    int nxt=u*a[last];
    if (nxt/a[last]==u)
    {
        vec2.pb(nxt);
        gen2(nxt,last);
    }


    gen2(u,last+1);
}
int get(int u)
{
    int res=0;
    int last=0;

    for (auto i:vec1)
    {
        int c=u/i;
        if (c==0)
            break;
        while(vec2[last]>c)
            last++;
        res+=vec2.size()-last-1;
    }
    return(res);
}

signed main()
{
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>a[i];


    random_shuffle(a+1,a+1+n);

    vec1.pb(1);
    nn=n/2;
    gen1(1,1);
    nn=n;
    vec2.pb(1);
    gen2(1,n/2+1);

    if (vec1.size()>vec2.size())
        swap(vec1,vec2);

    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());

    reverse(vec2.begin(),vec2.end());
    vec2.pb(0);
    int l=1;
    int r=1e18;

    int k;
    cin>>k;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (get(d)<k)
            l=d; else
            r=d;
    }

    if (get(l)==k)
        cout<<l; else
        cout<<r;
}
/*
16
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53

10000000
*/