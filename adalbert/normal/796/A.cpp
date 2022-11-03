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
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans=1e9;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if (a!=0 && a<=k) ans=min(ans,abs(m-i)*10);
    }
    cout<<ans;
}