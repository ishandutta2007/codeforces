#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

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

struct solver
{
    const int M=22;
    int n;
    vector<vector<int>> reb;
    vector<vector<int>> pred;
    vector<int> d;

    solver()
    {
        n=0;
        reb.clear();
        pred.clear();
        d.clear();
    }
    solver(int n)
    {
        this->n=n;
        reb.assign(n,{});
        pred.assign(n,vector<int>(M,0));
        d.assign(n,0);
    }

    void add_edge(int u,int v)
    {
//        cout<<"add_edge to solver :: "<<u<<" "<<v<<"\n";
        reb[u].pb(v);
        reb[v].pb(u);
    }
    void dfs(int now,int p)
    {
        pred[now][0]=p;
        for (int i=1;i<M;i++){
            pred[now][i]=pred[pred[now][i-1]][i-1];
        }
        for (auto wh:reb[now]){
            if (wh!=p){
                d[wh]=d[now]+1;
                dfs(wh,now);
            }
        }
    }
    void build()
    {
        dfs(0,0);
    }
    int lca(int u,int v)
    {
        if (d[u]>d[v]){
            swap(u,v);
        }
        for (int i=M-1;i>=0;i--){
            if (d[pred[v][i]]>=d[u]){
                v=pred[v][i];
            }
        }
        if (u==v){
            return u;
        }
        for (int i=M-1;i>=0;i--){
            if (pred[u][i]!=pred[v][i]){
                u=pred[u][i];
                v=pred[v][i];
            }
        }
        return pred[u][0];
    }
    int dist(int u,int v)
    {
        return d[u]+d[v]-2*d[lca(u,v)];
    }
};

vi reb[arr];
bool bad[arr];
vector<vi> comps;
map<pii,int> used_edge;

map<pii,bool> have_in_start_graph;

bool use_edge(int u,int v)
{
    if (u>v){
        swap(u,v);
    }
    return used_edge[{u,v}];
}

void set_use_edge(int u,int v)
{
    if (u>v){
        swap(u,v);
    }
    used_edge[{u,v}]=1;
}

int timer=0;
bool use[arr];
int tin[arr];
int tup[arr];

set<pii> s;

void dfs(int now,int pred)
{
//    cout<<"dfs :: "<<now<<" "<<pred<<"\n";
    use[now]=1;
    tin[now]=timer++;
    tup[now]=tin[now];
    int cnt_go=0;
    for (auto wh:reb[now]){
        if (wh==pred){
            continue;
        }
        if (use[wh]){
            tup[now]=min(tup[now],tin[wh]);
        }
        else{
            cnt_go++;
            dfs(wh,now);
            tup[now]=min(tup[now],tup[wh]);
            if (tup[wh]>=tin[now]){
                if (now!=pred){
                    bad[now]=1;
                }
//                cout<<"i find :: "<<now<<" "<<"with wh :: "<<wh<<"\n";
                vi cur_comp;
                while (!s.empty()&&s.rbegin()->fir>=tin[wh]){
                    auto kek=*s.rbegin();
                    s.erase(kek);
                    cur_comp.pb(kek.sec);
                }
                cur_comp.pb(now);
//                cout<<"cur_comp :: ";
//                for (auto j:cur_comp){
//                    cout<<j<<" ";
//                }
//                cout<<"\n";
                comps.pb(cur_comp);
            }
        }
    }
    s.insert(mp(tin[now],now));
    if (now==pred&&cnt_go>1){
        bad[now]=1;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
//        have_in_start_graph[{u,v}]=1;
//        have_in_start_graph[{v,u}]=1;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    int last=n;
    if (n*(n-1)/2!=m){
        dfs(1,1);
        solver S(n+len(comps));

//        for (auto i:comps){
//            cout<<"comp :: ";
//            for (auto j:i){
//                cout<<j<<" ";
//            }
//            cout<<"\n";
//        }

        for (auto i:comps){
            for (auto j:i){
                S.add_edge(j,last);
            }
            last++;
        }

        S.build();

        while (q--){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            cout<<S.dist(a,b)/2<<"\n";
        }
    }
    else{
        while (q--){
            cout<<1<<"\n";
        }
    }
}