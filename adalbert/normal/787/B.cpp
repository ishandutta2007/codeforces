#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define pb push_back
#define files(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
map<int,int> mp;
signed main()
{
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        mp.clear();
        int k;
        cin>>k;
        bool ch=1;
        for (int i=1;i<=k;i++)
        {
            int a;
            cin>>a;
            mp[a]=1;
            if (mp[-a]==1) ch=0;
        }
        if (ch)
        {
            cout<<"YES";
            return(0);
        }
    }
    cout<<"NO";
}