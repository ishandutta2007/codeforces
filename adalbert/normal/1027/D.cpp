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
const int arr=2e5+100;

int a[arr],c[arr],use[arr];

signed main()
{
    fast;
    int n;
    cin >> n;

    for (int i=1;i<=n;i++)
        cin >> c[i];

    for (int i=1;i<=n;i++)
        cin >> a[i];

    int ans=0;

    for (int i=1;i<=n;i++)
        if (!use[i])
    {
        int mn=1e9;
        int now=i;
        vector<int> tutu;

        while (!use[now])
        {
            use[now]=1;
            tutu.pb(now);
            now=a[now];
        }

        reverse(tutu.begin(),tutu.end());

        for (auto i:tutu)
        {
            mn=min(mn,c[i]);

            if (i==now)
            {
                ans+=mn;
                break;
            }
        }
    }

    cout << ans << '\n';
}