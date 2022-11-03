#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define int ll
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int a[100],b[100];
signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        a[c]++;
    }
    for (int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        b[c]++;
    }
    int ans=0;
    for (int i=1;i<=5;i++)
    {
        if ((a[i]+b[i])%2==1)
        {
            cout<<-1;
            return(0);
        }
        if (a[i]>b[i]) ans+=(a[i]-b[i])/2;
    }
    cout<<ans;

}