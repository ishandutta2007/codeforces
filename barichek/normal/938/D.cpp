#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vector<pii> reb[arr];
int dist[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        w*=2;
        reb[u].pb({v,w});
        reb[v].pb({u,w});
    }
    for (int i=1;i<=n;i++){
        cin>>dist[i];
    }
    set<pii> q;
    for (int i=1;i<=n;i++){
        q.insert({dist[i],i});
    }
    while (!q.empty()){
        int now=q.begin()->sec;
        q.erase(q.begin());
        for (auto wh:reb[now]){
            if (dist[wh.fir]>dist[now]+wh.sec){
                q.erase(mp(dist[wh.fir],wh.fir));
                dist[wh.fir]=dist[now]+wh.sec;
                q.insert(mp(dist[wh.fir],wh.fir));
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}