#pragma GCC optimize("O3")
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

bool kill[ar][ar];
vi reb[arr];
int p[arr];
bool use[arr];
bool use1[arr];
bool use2[arr];
vector<pii> cycle;

void dfs1(int now,int pred)
{
    use[now]=1;
    use1[now]=1;
    p[now]=pred;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs1(wh,now);
        }
        elif (cycle.empty()&&use1[wh]){
            int cur=now;
            while (cur!=wh){
                cycle.pb({p[cur],cur});
                cur=p[cur];
            }
            cycle.pb({now,wh});
        }
    }
    use1[now]=0;
}

bool ok;

void dfs2(int now)
{
    use[now]=1;
    use2[now]=1;

    for (auto wh:reb[now]){
        if (kill[now][wh]){
            continue;
        }
        if (!use[wh]){
            dfs2(wh);
        }
        elif (use2[wh]){
            ok=0;
        }
    }

    use2[now]=0;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    while (m--){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
    }
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs1(i,-1);
        }
    }
    if (cycle.empty()){
        return cout<<"YES"<<"\n", 0;
    }
//    cout<<"cycle :: "<<"\n";
//    for (auto i:cycle){
//        cout<<i.fir<<" "<<i.sec<<"\n";
//    }
    for (auto i:cycle){
        ok=1;
        kill[i.fir][i.sec]=1;

        for (int j=1;j<=n;j++){
            use[j]=0;
            use2[j]=0;
        }
        for (int j=1;j<=n;j++){
            if (!use[j]){
                dfs2(j);
            }
        }

        if (ok){
            return cout<<"YES"<<"\n", 0;
        }

        kill[i.fir][i.sec]=0;
    }
    cout<<"NO"<<"\n";
}