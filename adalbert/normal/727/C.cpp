#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp_ make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool check=0;
///------------------------------------------------------------///
ll a[100000];
///------------------------------------------------------------///
ask(ll i, ll j)
{
    cout<<'?'<<' '<<i<<' '<<j<<'\n';
    fflush(stdout);
    ll ans;
    cin>>ans;
    return(ans);
}
///------------------------------------------------------------///
int main()
{
    ll n;
    //fast;
    cin>>n;
    ll s12=ask(1,2);
     ll s23=ask(2,3);
      ll s13=ask(3,1);
    a[1]=(s12+s13-s23)/2;
    a[2]=s12-a[1];
    a[3]=s13-a[1];
    for (int i=4;i<=n;i++)
    {
        ll tep=ask(1,i);
        a[i]=tep-a[1];
    }
    cout<<'!'<<' ';
    for (int i=1;i<=n-1;i++)
        cout<<a[i]<<' ';
    cout<<a[n]<<'\n';
    fflush(stdout);
}