#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define stop system("pause");
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;
typedef map<int,int> mii;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

map<pair<ll,ll>,ll> edge_cost;

set<ll> visit;

ll lca(ll u,ll v)
{
    visit.clear();
    while (u!=0)
    {
        visit.insert(u);
        u/=2;
    }
    while (v!=0)
    {
        if (visit.count(v)) return v;
        v/=2;
    }
}

vector< pair<ll,ll> > edge_list;

void build_way(ll u,ll v)
{
    edge_list.clear();
    ll lcashka=lca(u,v);
    while (u!=lcashka)
    {
        edge_list.pb(mp(u/2,u));
        u/=2;
    }
    while (v!=lcashka)
    {
        edge_list.pb(mp(v/2,v));
        v/=2;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<ll> all_res;
    while (n--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            ll u,v,cost;
            cin>>u>>v>>cost;
            build_way(u,v);
            for (auto edge:edge_list)
                edge_cost[edge]+=cost;
        }
        else
        {
            ll u,v;
            cin>>u>>v;
            build_way(u,v);
            ll ans=0;
            for (auto edge:edge_list)
                ans+=edge_cost[edge];
            all_res.pb(ans);
        }
    }
    for (auto i:all_res)
        cout<<i<<"\n";
}