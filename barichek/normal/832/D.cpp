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

int pred[arr][20];
int deep[arr];
vi reb[arr];

void dfs(int now=1,int pred_=1,int deep_=0)
{
    deep[now]=deep_;
    pred[now][0]=pred_;
    for (auto wh:reb[now]){
        if (wh!=pred_){
            dfs(wh,now,deep_+1);
        }
    }
}

int lca(int u,int v)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    for (int i=19;i>=0;i--){
        if (deep[pred[v][i]]>=deep[u]){
            v=pred[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=19;i>=0;i--){
        if (pred[u][i]!=pred[v][i]){
            u=pred[u][i];
            v=pred[v][i];
        }
    }
    return pred[u][0];
}

int lca1(int u,int v)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    for (int i=19;i>=0;i--){
        if (deep[pred[v][i]]>=deep[u]){
            v=pred[v][i];
        }
    }
    for (int i=19;i>=0;i--){
        if (pred[u][i]!=pred[v][i]){
            u=pred[u][i];
            v=pred[v][i];
        }
    }
    return v;
}

int intersect(int u1,int u2,int v1,int v2)
{
    return max(0,deep[lca(u1,v1)]-max(deep[v2],deep[u2])+1);
}

void upd(int u,int v,vector<pii>& ways)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    int l=lca(u,v);
    if (l==u){
        ways.pb(mp(v,u));
    }
    elif (l==v){
        ways.pb(mp(u,v));
    }
    else{
        int l1=lca1(u,v);
        ways.pb(mp(u,l));
        ways.pb(mp(v,l1));
    }
}

int get(int a,int b,int c)
{
    vector<pii> ways1(0);
    upd(a,b,ways1);
    vector<pii> ways2(0);
    upd(b,c,ways2);
    int res=0;
    for (auto i:ways1){
        for (auto j:ways2){
            res+=intersect(i.fir,i.sec,j.fir,j.sec);
        }
    }
    return res;
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

    fast;
    int n,q;
    cin>>n>>q;
    for (int i=2;i<=n;i++){
        int u,v=i;
        cin>>u;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs();
    for (int j=1;j<20;j++){
        for (int i=1;i<=n;i++){
            pred[i][j]=pred[pred[i][j-1]][j-1];
        }
    }
    while (q--){
        vi a(3);
        for (auto& i:a){
            cin>>i;
        }
        sort(all(a));
        int ans=0;
        do{
            ans=max(ans,get(a[0],a[1],a[2]));
        }
        while(next_permutation(all(a)));
        cout<<ans<<"\n";
    }
}