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
int d[arr];

int T;

int tin[arr];
int tout[arr];

bool is_pred(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int pp[arr];

void dfs(int now,int pred)
{
    tin[now]=++T;

    pp[now]=pred;
    for (auto wh:reb[now]){
        if (wh!=pred){
            d[wh]=d[now]+1;
            dfs(wh,now);
        }
    }

    tout[now]=T;
}

int get1(int a)
{
    fflush(stdout);
    cout<<"A"<<" "<<a<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    fflush(stdout);
    return res;
}

int get2(int a)
{
    fflush(stdout);
    cout<<"B"<<" "<<a<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    fflush(stdout);
    return res;
}

bool in1[arr];
bool in2[arr];

void solve()
{
    T=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        reb[i].clear();
        in1[i]=0;
        in2[i]=0;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1,1);
    int s1,s2;
    cin>>s1;
    vi a1(s1);
    for (auto& i:a1){
        cin>>i;
        in1[i]=1;
    }
    cin>>s2;
    vi a2(s2);
    for (auto& i:a2){
        cin>>i;
        in2[i]=1;
    }

    int x=a1[0];
    for (auto i:a1){
        if (d[i]<d[x]){
            x=i;
        }
    }

    if (in2[get1(x)]){
        cout<<"C"<<" "<<x<<"\n";
        return;
    }

    int y=a2[0];
    for (auto i:a2){
        if (d[i]<d[y]){
            y=i;
        }
    }
    int ys=get2(y);

    if (!is_pred(x,ys)){
        cout<<"C"<<" "<<-1<<"\n";
        return;
    }

    int best=x;
    for (auto i:a1){
        if (is_pred(i,ys)){
            if (d[best]<d[i]){
                best=i;
            }
        }
    }

    if (in2[get1(best)]){
        cout<<"C"<<" "<<best<<"\n";
        return;
    }

    cout<<"C"<<" "<<-1<<"\n";
}

main()
{
//    #ifdef I_love_Maria_Ivanova
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}