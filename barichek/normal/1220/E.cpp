//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

vi reb[arr];
bool use[arr];
int T;
int tin[arr];
int tup[arr];

map<pii,bool> is_bridge;

void dfs1(int now,int pred)
{
    use[now]=1;
    tin[now]=tup[now]=++T;
    for (auto wh:reb[now]){
        if (wh==pred){
            continue;
        }
        if (!use[wh]){
            dfs1(wh,now);
            if (tup[wh]>tin[now]){
                is_bridge[mp(now,wh)]=1;
                is_bridge[mp(wh,now)]=1;
            }
            tup[now]=min(tup[now],tup[wh]);
        }
        else{
            tup[now]=min(tup[now],tin[wh]);
        }
    }
}

int comp[arr];

void dfs2(int now,int c)
{
    use[now]=1;
    comp[now]=c;
    for (auto wh:reb[now]){
        if (!use[wh]&&!is_bridge[mp(now,wh)]){
            dfs2(wh,c);
        }
    }
}

int value[arr];
vi reb_G[arr];

int sz[arr];
bool is_big[arr];
int dp[arr][2];

void dfs3(int now,int pred)
{
    vector<pii> cur;
    for (auto wh:reb_G[now]){
        if (wh!=pred){
            dfs3(wh,now);
            cur.pb(mp(dp[wh][0],dp[wh][1]));
        }
    }
    if (1){
        /// dp[now][1] - get back
        dp[now][1]=value[now];
        int sum=0;
        for (auto i:cur){
            sum+=max(0ll,i.sec);
        }
        if (sum==0&&!is_big[now]){
            int max_sec=-1e18;
            for (auto i:cur){
                max_sec=max(max_sec,i.sec);
            }
            sum+=max_sec;
        }
        dp[now][1]+=sum;
    }
    if (1){
        /// dp[now][0] - not must get back
        dp[now][0]=value[now];
        int sum=0;
        for (auto i:cur){
            sum+=max(0ll,i.sec);
        }
        int best=0;
        for (auto i:cur){
            sum-=max(0ll,i.sec);

            best=max(best,sum+i.fir);

            sum+=max(0ll,i.sec);
        }
        dp[now][0]+=best;
        /// lol
        dp[now][0]=max(dp[now][0],dp[now][1]);
    }
}

int w[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>w[i];
    }
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    int s;
    cin>>s;
    dfs1(1,-1);
    memset(use,0,sizeof(use));
    int c=0;
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs2(i,c);
            c++;
        }
    }
    for (int i=1;i<=n;i++){
        value[comp[i]]+=w[i];
        sz[comp[i]]++;
        if (sz[comp[i]]>=3){
            is_big[comp[i]]=1;
        }
    }
    for (int i=1;i<=n;i++){
        for (auto wh:reb[i]){
            if (i<wh&&is_bridge[mp(i,wh)]){
                reb_G[comp[i]].pb(comp[wh]);
                reb_G[comp[wh]].pb(comp[i]);
            }
        }
    }
    dfs3(comp[s],-1);
    cout<<max(dp[comp[s]][0],dp[comp[s]][1]);
}