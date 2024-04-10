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

///---program start

#define arr (int)(3e5+10)

vi reb[arr];
bool use1[arr];
bool use_c[arr];

void dfs1(int now)
{
    use1[now]=1;
    use_c[now]=1;
    for (auto wh:reb[now]){
        if (use1[wh]){
            if (use_c[wh]){
                exit(!(cout<<-1<<"\n"));
            }
        }
        else{
            dfs1(wh);
        }
    }
    use_c[now]=0;
}

char C;
int n,m;

bool use_dp[arr];
int dp[arr];
string s;

int dfs2(int now)
{
    if (use_dp[now]){
        return dp[now];
    }
    use_dp[now]=1;
    int& res=dp[now];
    for (auto wh:reb[now]){
        res=max(res,dfs2(wh));
    }
    res+=(s[now]==C);
    return res;
}

int solve(char c)
{
    C=c;

    memset(use_dp,0,sizeof(use_dp));
    memset(dp,0,sizeof(dp));

    int res=0;
    for (int i=0;i<n;i++){
        res=max(res,dfs2(i));
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m;
    cin>>s;
    while (m--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        reb[u].pb(v);
    }
    for (int i=0;i<n;i++){
        if (!use1[i]){
            dfs1(i);
        }
    }
    int ans=0;
    for (int i='a';i<='z';i++){
        ans=max(ans,solve(i));
    }
    cout<<ans<<"\n";
}