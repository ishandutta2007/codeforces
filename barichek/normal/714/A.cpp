#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

main()
{
    ll x1,y1,x2,y2,k;
    cin>>x1>>y1>>x2>>y2>>k;
    bool ok=false;
    vector< pair<ll,ll> > a;
    ull ans=0;
    a.pb(mp(x1,-1));
    a.pb(mp(y1,+1));
    a.pb(mp(x2,-1));
    a.pb(mp(y2,+1));
    a.pb(mp(k,0));
    sort(all(a));
    int cur=0;
    for (int i=0;i<5;i++)
    {
        if (cur==-2) ans+=a[i].fir-a[i-1].fir+1;
        if (cur==-2&&a[i].sec==0) ok=true;
        cur+=a[i].sec;
    }
    cout<<max(ans-2*ok,0ull);
}