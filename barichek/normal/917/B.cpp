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

bool use[101][101][26];
bool dpp[101][101][26];
vector<pii> reb[arr];

bool dp(int u,int v,int last)
{
    if (use[u][v][last]){
        return dpp[u][v][last];
    }
    use[u][v][last]=1;
    bool& res=dpp[u][v][last];
    for (auto wh:reb[u]){
        if (wh.sec>=last){
            res|=(!dp(v,wh.fir,wh.sec));
        }
    }
    return res;
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
        char c;
        cin>>u>>v>>c;
        reb[u].pb({v,c-'a'});
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (dp(i,j,0)){
                cout<<'A';
            }
            else{
                cout<<'B';
            }
        }
        cout<<"\n";
    }
}