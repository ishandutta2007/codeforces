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

int n,m;
vector<pair<pii,pii>> edges;
vector<pair<pii,pii>> reb[arr];
bool use[arr];
vi vec;
int pos[arr];

void dfs(int now)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh.fir.sec]){
            dfs(wh.fir.sec);
        }
    }
    vec.pb(now);
}

bool check(int x)
{
    for (int i=1;i<=n;i++){
        reb[i].clear();
        use[i]=0;
    }
    for (auto i:edges){
        if (i.sec.fir>x){
            reb[i.fir.fir].pb(i);
        }
    }
    vec.clear();
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i);
        }
    }
    reverse(all(vec));
    for (int i=0;i<len(vec);i++){
        pos[vec[i]]=i;
    }
    for (auto i:edges){
        if (i.sec.fir>x){
            if (pos[i.fir.fir]>pos[i.fir.sec]){
                return 0;
            }
        }
    }
    return 1;
}

void build(int x)
{
    for (int i=1;i<=n;i++){
        reb[i].clear();
        use[i]=0;
    }
    for (auto i:edges){
        if (i.sec.fir>x){
            reb[i.fir.fir].pb(i);
        }
    }
    vec.clear();
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i);
        }
    }
    reverse(all(vec));
    for (int i=0;i<len(vec);i++){
        pos[vec[i]]=i;
    }
    vi ans(0);
    for (auto i:edges){
        if (i.sec.fir<=x){
            if (pos[i.fir.fir]>pos[i.fir.sec]){
                ans.pb(i.sec.sec);
            }
        }
    }

    sort(all(ans));
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        edges.pb(mp(mp(u,v),mp(c,i)));
    }
    int l=0,r=1e9;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<" ";
    build(l);
}