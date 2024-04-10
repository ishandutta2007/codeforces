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
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

int a[300000];

signed main()
{
    int n,m;
    cin>>n>>m;

    multiset<pair<int,int> > setik;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        setik.insert({a[i]%m,i});
    }

    int ans=0;

    for (int i=0;i<m;i++)
    {
        int cnt=n/m;

        while (cnt--)
        {
            if ((*setik.begin()).fir<=i)
            {
                ans+=i-(*setik.begin()).fir;
                a[(*setik.begin()).sec]+=i-(*setik.begin()).fir;
                setik.erase(setik.begin());
            } else
            {
                ans+=i+m-(*setik.rbegin()).fir;
                a[(*setik.rbegin()).sec]+=i+m-(*setik.rbegin()).fir;
                setik.erase(setik.find(*setik.rbegin()));
            }
        }
    }

    cout<<ans<<'\n';

    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}