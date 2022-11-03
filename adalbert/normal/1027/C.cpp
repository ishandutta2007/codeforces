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

int cnt[20000], a[2000000];

signed main()
{
    fast;
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        vector<int> vec;

        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]]==2)
            {
                vec.pb(a[i]);
            }

            if (cnt[a[i]]==4)
            {
                vec.pb(a[i]);
            }


        }

        for (int i=1;i<=n;i++)
            cnt[a[i]]=0;
        if (vec.size()==1)
            vec.pb(vec[0]);

        sort(vec.begin(),vec.end());

        int ans=0;

        for (int i=0;i+1<vec.size();i++)
            if (ld(vec[i])/ld(vec[i+1])+ld(vec[i+1])/ld(vec[i])<ld(vec[ans])/ld(vec[ans+1])+ld(vec[ans+1])/ld(vec[ans]))
            ans=i;

        cout << vec[ans] << ' ' << vec[ans] << ' ' << vec[ans+1] << ' ' << vec[ans+1] << '\n';
    }
}