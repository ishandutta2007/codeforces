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

int mx[arr],h[arr],pl[arr];
map<int,int> mp;
vector<pair<int,int> > vec[arr];

signed main()
{
    fast;
    int n,m,b,inc,dam;
    cin>>n>>m;
    cin>>b>>inc>>dam;

    for (int i=1;i<=n;i++)
    {
        cin>>mx[i]>>h[i]>>pl[i];
    }


    while (m--)
    {
        int t,e,h;
        cin>>t>>e>>h;
        vec[e].pb({t,h});
    }


    for (int i=1;i<=n;i++)
    {

        vec[i].pb({1e18,0});
        sort(vec[i].begin(),vec[i].end());
        int l=0;
        int hel=h[i];
        for (auto j:vec[i])
        {
            if (mx[i]<=dam)
            {
                mp[l]++;
                mp[j.fir]--;
            } else
            if (pl[i]==0)
            {
                if (hel<=dam)
                {
                    mp[l]++;
                    mp[j.fir]--;
                }
            } else
            {
                if (hel<=dam)
                {
                    int right=(dam-hel)/pl[i]+l;
                    right=min(right,j.fir-1);
                    if (right>=l)
                    {
                        mp[l]++;
                        mp[right+1]--;
                    }
                }
            }
            hel=j.sec;
            l=j.fir;
        }
    }

    int ans=0;
    int open=0;

    for (auto i:mp)
    {
        if (i.fir>=int(1e18)-1 && open!=0 && inc!=0)
        {
            cout<<-1;
            return(0);
        }

        ans=max(ans,(b+inc*(i.fir-1))*open);
        open+=i.sec;
        //cout<<i.fir<<' '<<open<<'\n';
    }

    cout<<ans;
}
/*
1 3
100 0 500
1000 50 0
1 1 700
10 1 300
15 1 498
*/