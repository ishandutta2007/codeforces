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

int a[arr];
int b[arr];
vector<pii> reb[arr];

void dfs(int now=1,int pred=-1,int cost_go=-1)
{
    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            dfs(wh.fir,now,wh.sec);
        }
    }
    #define i now
    if (b[i]>=a[i]){
        if (pred!=-1){
            b[pred]+=b[i]-a[i];
            b[i]=a[i];
        }
    }
    else{
        if (pred!=-1){
            if (2e17/cost_go<=a[i]-b[i]){
                exit(!(cout<<"NO"<<"\n"));
            }
            if (b[pred]-1.0*cost_go*(a[i]-b[i])<-2e17){
                exit(!(cout<<"NO"<<"\n"));
            }
            b[pred]-=cost_go*(a[i]-b[i]);
            b[i]=a[i];
        }
    }
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
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=2;i<=n;i++){
        int u,k;
        cin>>u>>k;
        reb[u].pb(mp(i,k));
    }
    dfs();
    if (b[1]>=a[1]){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}