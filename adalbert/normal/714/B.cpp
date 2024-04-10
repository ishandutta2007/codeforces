#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
///-------------------///
vector<pair<ll,ll> > vec;
map<ll,ll> cnt;
ll a[100000];
///---program start---///

main()
{
    ll n;
    cin>>n;
    ll k=0;
    ll x=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1])
    {
        k++;
        if (k>2)
        {
            cout<<"NO";
            return(0);
        }
        if (x==0 )
        {
            x=a[i]-a[i-1];
        } else
        if (x!=a[i]-a[i-1])
        {
            cout<<"NO";
            return(0);
        }
    }
    cout<<"YES";

}