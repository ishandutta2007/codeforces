#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int g(int u)
{
    if (u<10)
        return(u);
    int res=1;
    while (u!=0)
    {
        if (u%10!=0)
            res*=u%10;
        u/=10;
    }
    return(g(res));
}

int f[1000010][10];

signed main()
{
    int mx=1e6;
    for (int i=1;i<=mx;i++)
    {
        f[i][g(i)]++;
    }

    for (int i=1;i<=mx;i++)
        for (int j=0;j<=9;j++)
            f[i][j]+=f[i-1][j];

    int q;
    cin>>q;
    while (q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<f[r][k]-f[l-1][k]<<'\n';
    }
}
/*
*/