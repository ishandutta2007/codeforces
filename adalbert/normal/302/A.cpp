#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///------------------------------------------------------------///

///------------------------------------------------------------///


///------------------------------------------------------------///
int main()
{
    fast;
    ll n,km=0,kp=0,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        if (a==-1) km++; else kp++;
    }
    for (int i=1;i<=m;i++)
    {
        ll l,r;
        cin>>l>>r;
        if ((r-l+1)%2==1) cout<<0<<'\n'; else
        if ((r-l+1)/2<=min(km,kp)) cout<<1<<'\n'; else cout<<0<<'\n';
    }
}