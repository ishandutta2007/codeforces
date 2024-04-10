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
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;

int a[arr];

void solve()
{
    int last=0;

    int n;
    cin>>n;
    while (n--)
    {
        int l,r;
        cin>>l>>r;
        last=max(last,l);
        if (last<=r)
        {
            cout<<last<<' ';
            last++;
        } else
        cout<<0<<' ';
    }
    cout<<'\n';
}

signed main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
        solve();
}
/*
2
set physicsexercise 2
query physicsexercise
*/