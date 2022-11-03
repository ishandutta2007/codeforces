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
const ll base=31;
const int arr=6e5;
const int md=1e9+9;

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    k++;

    if (k<=n)
    {
        cout<<k<<' '<<1;
        return(0);
    }

    k-=n;
    m--;

    int last=0;
    last=k/m;
    k%=m;
    if (k==0)
    {
        k+=m;
        last--;
    }

    if (last%2==0)
    {
        cout<<n-last<<' '<<1+k;
    } else
    {
        cout<<n-last<<' '<<1+(m-k+1);
    }
}