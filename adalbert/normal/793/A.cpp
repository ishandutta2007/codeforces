#include <bits/stdc++.h>
using namespace std;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define int ll
#define m_p make_pair
#define sec second
typedef long long ll;
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
int a[200000];
signed main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int mn=1e9;
    for (int i=1;i<=n;i++)
        mn=min(mn,a[i]);
    for (int i=1;i<=n;i++)
        a[i]-=mn;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]%k!=0)
        {
            cout<<-1;
            return(0);
        }
        ans+=a[i]/k;
    }
    cout<<ans;
}