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
vi rreb[arr];
int a[arr];
int use[arr];
vi order;

vi comp[arr];

void dfs(int now)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs(wh);
        }
    }
    order.pb(now);
}

void rdfs(int now,int color)
{
    use[now]=color;
    comp[color].pb(now);
    for (auto wh:rreb[now]){
        if (!use[wh]){
            rdfs(wh,color);
        }
    }
}

bool have[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,h;
    cin>>n>>m>>h;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    while (m--){
        int u,v;
        cin>>u>>v;
        if ((a[u]+1)%h==a[v]){
//            cout<<"edge :: "<<u<<" "<<v<<" !!\n";
            reb[u].pb(v);
            rreb[v].pb(u);
        }
        swap(u,v);
        if ((a[u]+1)%h==a[v]){
//            cout<<"edge :: "<<u<<" "<<v<<" !!\n";
            reb[u].pb(v);
            rreb[v].pb(u);
        }
    }
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i);
        }
    }
    memset(use,0,sizeof(use));
    reverse(all(order));
    int cnt=0;
    for (auto i:order){
        if (!use[i]){
            rdfs(i,++cnt);
        }
    }
    for (int i=1;i<=n;i++){
        for (auto wh:reb[i]){
            if (use[i]!=use[wh]){
                have[use[i]]=1;
            }
        }
    }
    vi ans(n);
    for (int i=0;i<n;i++){
        ans[i]=i+1;
    }
    for (int i=1;i<=cnt;i++){
        if (!have[i]){
            if (len(comp[i])<len(ans)){
                ans=comp[i];
            }
        }
    }

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}