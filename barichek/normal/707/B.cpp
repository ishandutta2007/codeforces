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
const ld eps=1e-6;

///---program start---///

#define int ll

bool ok[arr];

main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector< pair< pair<int,int> ,int> > reb;
    while (m--)
    {
        int u,v,l;
        cin>>u>>v>>l;
        reb.pb(mp(mp(u,v),l));
        reb.pb(mp(mp(v,u),l));
    }
    while (k--)
    {
        int dop;
        cin>>dop;
        ok[dop]=true;
    }
    int ans=maxll;
    for (auto i:reb)
    {
        //cout<<i.fir.fir<<" "<<i.fir.sec<<"\n";
        //cout<<ok[i.fir.fir]<<" "<<ok[i.fir.sec]<<" !\n";
        if (ok[i.fir.fir]&&!ok[i.fir.sec])
            ans=min(ans,i.sec);
        if (!ok[i.fir.fir]&&ok[i.fir.sec])
            ans=min(ans,i.sec);
    }
    if (ans==maxll)
        return cout<<-1, 0;
    cout<<ans;
}