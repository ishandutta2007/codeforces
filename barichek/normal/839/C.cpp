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

vi reb[arr];

ld dfs(int now=1,int pred=-1)
{
    if (pred!=-1&&len(reb[now])==1){
        return 0;
    }
    int cnt_go=0;
    ld res=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            res+=1+dfs(wh,now);
            cnt_go++;
        }
    }
    return res/ld(cnt_go);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    /// a rechi hvorii
    /// i ti, vshe tut u tomy holi
    /// idy na golos miy
    /// idy na golos miy

    /// hay navit ne zbudetsya
    /// zavtra nehayno i nevidvorotnyo vidbudetsya

    int n;
    cin>>n;
    if (n==1){
        return cout<<0<<"\n", 0;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    cout<<fixed<<setprecision(10)<<dfs()<<"\n";
}