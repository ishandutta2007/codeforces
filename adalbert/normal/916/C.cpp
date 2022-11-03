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
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
///

int go[arr];
bool simple(int u)
{
    for (int i=2;i*i<=u;i++)
    {
        if (u%i==0)
            return(0);
    }
    return(1);
}

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=2;i<=n;i++)
        go[i]=1;
    go[n]=2;
    int sum=n;

    while (!simple(sum))
    {
        sum++;
        go[2]++;
    }

    m-=(n-1);

    cout<<2<<' '<<sum<<'\n';

    for (int i=2;i<=n && m;i++)
        for (int j=i+1;j<=n && m;j++)
    {
        cout<<i<<' '<<j<<' '<<int(1e9)<<'\n';
        m--;
    }

    for (int i=2;i<=n;i++)
        cout<<i<<' '<<1<<' '<<go[i]<<'\n';
}