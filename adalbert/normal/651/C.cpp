#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define  pb push_back
#define make_pair mp
#define sec second
#define fir first
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
map <ll,map<ll,ll> > cntxy;
map <ll,ll> cntx,cnty;
int main()
{
        ll n=0;
        ll ans=0;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            ll x,y;
            cin>>x>>y;
            ans+=cntx[x];
            ans+=cnty[y];
            ans-=cntxy[x][y];
            cntx[x]++;
            cnty[y]++;
            cntxy[x][y]++;
        }
        cout<<ans;
}