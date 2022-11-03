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

bool happy(int u)
{
    int h=(u%(24*60))/60;
    int m=u%60;
    if (h/10==7 || h%10==7 || m/10==7 || m%10==7)
        return(1);
    return(0);
}

signed main()
{
    int x;
    cin>>x;
    int h,m;
    cin>>h>>m;

    int tim=h*60+m+24*60;
    int res=0;
    while (!happy(tim))
    {
        res++;
        tim-=x;
    }
    cout<<res;
}