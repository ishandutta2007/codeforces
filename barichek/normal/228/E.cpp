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

struct sat2
{
    int n;
    vector<bool> use;
    vi order;
    vector<vi> reb;
    vector<vi> rreb;
    vi comp;

    sat2() {}
    sat2(int n)
    {
        this->n=n;
        use.resize(n);
        order.clear();
        reb.resize(n);
        rreb.resize(n);
        comp.resize(n);
    }

    void add_edge(int u,int v)
    {
        reb[u].pb(v);
        rreb[v].pb(u);
    }
    void dfs1(int now)
    {
        use[now]=1;
        for (auto wh:reb[now]){
            if (!use[wh]){
                dfs1(wh);
            }
        }
        order.pb(now);
    }
    void dfs2(int now,int num)
    {
        comp[now]=num;
        for (auto wh:rreb[now]){
            if (!comp[wh]){
                dfs2(wh,num);
            }
        }
    }
    void build()
    {
        for (int i=0;i<n;i++){
            if (!use[i]){
                dfs1(i);
            }
        }
        reverse(all(order));
        int num=0;
        for (auto i:order){
            if (!comp[i]){
                dfs2(i,++num);
            }
        }
    }
};

/// 2*i - build
/// 2*i+1 - not build

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,m;
    cin>>n>>m;
    sat2 kek=*new sat2(2*n);
    while (m--){
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        if (c==1){
            kek.add_edge(2*u,2*v);
            kek.add_edge(2*v,2*u);
            kek.add_edge(2*u+1,2*v+1);
            kek.add_edge(2*v+1,2*u+1);
        }
        else{
            kek.add_edge(2*u,2*v+1);
            kek.add_edge(2*v,2*u+1);
            kek.add_edge(2*u+1,2*v);
            kek.add_edge(2*v+1,2*u);
        }
    }

    kek.build();

    for (int i=0;i<n;i++){
        if (kek.comp[2*i]==kek.comp[2*i+1]){
            return cout<<"Impossible"<<"\n", 0;
        }
    }
    vi ans(0);
    for (int i=0;i<n;i++){
        if (kek.comp[2*i]>kek.comp[2*i+1]){
            ans.pb(i+1);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}