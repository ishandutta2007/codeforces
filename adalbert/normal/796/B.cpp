#include <bits/stdc++.h>
using namespace std;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
typedef long long ll;
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
int d[2000000];
signed main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int h;
        cin>>h;
        d[h]=1;
    }
    int now=1,ans=0;
    while (k--)
    {
        if (d[now] && ans==0)
        {
            ans=now;
        }
        int u,v;
        cin>>u>>v;
        if (now==u)
        {
            now=v;
        } else
        if (now==v)
        {
            now=u;
        }
        if (d[now] && ans==0)
        {
            ans=now;
        }
    }
    if (ans==0) cout<<now; else
    cout<<ans;
}