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
///---program start---///
bool check(pair <ll,ll> i, pair <ll,ll> j)
{
    if (i.fir==j.fir) return(i.sec>j.sec); else return(i.fir <j.fir);
}
main()
{
    ll l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
        ll tep=0;
        ll ans=0;
        vec.pb(mp(l1,1));
        vec.pb(mp(r1,-1));
        vec.pb(mp(l2,1));
        vec.pb(mp(r2,-1));
        sort(vec.begin(),vec.end(),check);
        for (int i=0;i<vec.size();i++)
        {
            if (tep==2) ans+=vec[i].fir-vec[i-1].fir+1;
            tep+=vec[i].sec;
        }
        if (k>=l1 && k<=r1 && k>=l2 && k<=r2) ans--;
        cout<<ans;

}