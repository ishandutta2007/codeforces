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
//#define int long long

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

#define arr (int)(1e6+10)

string type[arr];
int val[arr];
vi reb[arr];

int easy_value[arr];

void dfs0(int now)
{
    if (val[now]!=-1){
        easy_value[now]=val[now];
        return;
    }
    for (auto wh:reb[now]){
        dfs0(wh);
    }
    if (type[now]=="AND"){
        easy_value[now]=easy_value[reb[now][0]]&easy_value[reb[now][1]];
    }
    if (type[now]=="OR"){
        easy_value[now]=easy_value[reb[now][0]]|easy_value[reb[now][1]];
    }
    if (type[now]=="XOR"){
        easy_value[now]=easy_value[reb[now][0]]^easy_value[reb[now][1]];
    }
    if (type[now]=="NOT"){
        easy_value[now]=!easy_value[reb[now][0]];
    }
}

int deep[arr];
const int M=22;
bool is[arr][M];
int pred[arr][M];

void dfs(int now)
{
//    cout<<"dfs :: "<<now<<"\n";
    for (int j=1;j<M;j++){
        if (pred[now][j-1]){
            pred[now][j]=pred[pred[now][j-1]][j-1];
        }
    }
    for (int j=1;j<M;j++){
        if (pred[now][j]){
            is[now][j]=is[now][j-1]&is[pred[now][j-1]][j-1];
        }
    }
    if (val[now]!=-1){
        return;
    }
    if (type[now]=="AND"){
        if (easy_value[reb[now][0]]==1){
            if (easy_value[reb[now][1]]==1){
                is[reb[now][0]][0]=1;
                is[reb[now][1]][0]=1;
            }
        }
        if (easy_value[reb[now][0]]==0){
            if (easy_value[reb[now][1]]==1){
                is[reb[now][0]][0]=1;
            }
        }
        if (easy_value[reb[now][0]]==1){
            if (easy_value[reb[now][1]]==0){
                is[reb[now][1]][0]=1;
            }
        }
    }
    if (type[now]=="OR"){
        if (easy_value[reb[now][0]]==1){
            if (easy_value[reb[now][1]]==1){
            }
        }
        if (easy_value[reb[now][0]]==0){
            if (easy_value[reb[now][1]]==1){
                is[reb[now][1]][0]=1;
            }
        }
        if (easy_value[reb[now][0]]==1){
            if (easy_value[reb[now][1]]==0){
                is[reb[now][0]][0]=1;
            }
        }
        if (easy_value[reb[now][0]]==0){
            if (easy_value[reb[now][1]]==0){
                is[reb[now][0]][0]=1;
                is[reb[now][1]][0]=1;
            }
        }
    }
    if (type[now]=="XOR"){
        is[reb[now][0]][0]=1;
        is[reb[now][1]][0]=1;
    }
    if (type[now]=="NOT"){
        is[reb[now][0]][0]=1;
    }
    for (auto wh:reb[now]){
        dfs(wh);
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>type[i];
        if (type[i]=="AND"){
            int u,v;
            cin>>u>>v;
            pred[u][0]=i;
            pred[v][0]=i;
            reb[i].pb(u);
            reb[i].pb(v);
        }
        if (type[i]=="OR"){
            int u,v;
            cin>>u>>v;
            pred[u][0]=i;
            pred[v][0]=i;
            reb[i].pb(u);
            reb[i].pb(v);
        }
        if (type[i]=="XOR"){
            int u,v;
            cin>>u>>v;
            pred[u][0]=i;
            pred[v][0]=i;
            reb[i].pb(u);
            reb[i].pb(v);
        }
        if (type[i]=="NOT"){
            int u;
            cin>>u;
            pred[u][0]=i;
            reb[i].pb(u);
        }
        if (type[i]=="IN"){
            int u;
            cin>>u;
            val[i]=u;
        }
        else{
            val[i]=-1;
        }
    }
    dfs0(1);
//    for (int i=1;i<=n;i++){
//        cout<<easy_value[i]<<"\n";
//    }
//    cout<<" !!!\n";
    dfs(1);
//    for (int i=1;i<=n;i++){
//        for (int j=0;j<M;j++){
//            cout<<"pred["<<i<<"]["<<j<<"] :: "<<pred[i][j]<<"\n";
//        }
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=0;j<M;j++){
//            cout<<"is["<<i<<"]["<<j<<"] :: "<<is[i][j]<<"\n";
//        }
//    }
    for (int i=1;i<=n;i++){
        if (val[i]!=-1){
            int kek=i;
            bool res=1;
            for (int j=M-1;j>=0;j--){
                if (pred[kek][j]){
                    res&=is[kek][j];
                    kek=pred[kek][j];
                }
            }
            bool print=(easy_value[1]^res);
            cout<<print;
        }
    }
    cout<<"\n";
}