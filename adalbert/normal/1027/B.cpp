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
#define y eth
#pragma GCC optimize ("O3")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5;

signed main()
{
    int n, q;
    cin >> n >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if ((x+y)%2==0)
        {
            int pl1=(n+1)/2;
            int pl0=n/2;

            int cnt1=x/2;
            int cnt0=(x-1)/2;

            int pl;
            if (x%2)
                pl=(y+1)/2; else
                pl=y/2;

            int ans=pl1*cnt1+pl0*cnt0+pl;

            cout << ans << '\n';
        } else
        {
            int pl1=(n+1)/2;
            int pl0=n/2;

            int cnt1=x/2;
            int cnt0=(x-1)/2;

            int pl;
            if (x%2)
                pl=(y+1)/2; else
                pl=y/2;

            int ans=pl1*cnt1+pl0*cnt0+pl;

            cout << ((x-1)*n + y - ans ) + (n*n+1)/2 << '\n';
        }



    }
}