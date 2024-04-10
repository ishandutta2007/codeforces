#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int a[300000],b[300000];

signed main()
{
    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        if (b[i])
        {
            ans+=a[i];
            a[i]=0;
        }
    }

    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    int mx=0;
    for (int i=k;i<=n;i++)
        mx=max(mx,a[i]-a[i-k]);

    cout<<ans+mx;
}
/*1
2 0
*/