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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[10000],dp[2100][2100],sum1[2100],sum2[2100];

int get1(int l, int r)
{
    if (l>r)
        return(0);
    return(sum1[r]-sum1[l-1]);
}

int get2(int l, int r)
{
    if (l>r)
        return(0);
    return(sum2[r]-sum2[l-1]);
}

signed main()
{
    int a,b;
    cin>>a>>b;

    vector<int> vec;

    while (a!=0)
    {
        if (a>0)
        {
            vec.pb(a%b);
            a=-(a/b);
        } else
        {
            int c=abs(a);
            int need=-((c/b+(c%b!=0))*b);
            vec.pb(abs(need)+a);
            a=abs(need)/b;
        }
    }
    cout<<vec.size()<<'\n';
    for (auto i:vec)
        cout<<i<<' ';
}