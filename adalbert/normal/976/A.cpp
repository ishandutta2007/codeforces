#include<bits/stdc++.h>
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll base=31;
const int arr=6e5;
const int md=1e9+9;

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;

    int cnt0=0;
    int cnt1=0;
    for (auto i:st)
        if (i=='0')
        cnt0++; else
        cnt1++;
    if (cnt1==0)
        cout<<0; else
    {
        cout<<1;
        while (cnt0--)
            cout<<0;
    }
}