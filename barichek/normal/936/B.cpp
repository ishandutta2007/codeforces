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

int n,m;
vi reb[arr];
bool use[arr][2];
bool calc_now[arr][2];
int dp[arr][2];
int go[arr][2];

bool dfs(int now,int cnt)
{
    if (use[now][cnt]){
        return dp[now][cnt];
    }
    use[now][cnt]=1;
    calc_now[now][cnt]=1;
    int& res=dp[now][cnt];
    if (len(reb[now])==0){
        if (cnt==0){
            res=1;
            go[now][cnt]=-1;
            calc_now[now][cnt]=0;
            return res;
        }
        else{
            res=0;
            go[now][cnt]=-1;
            calc_now[now][cnt]=0;
            return res;
        }
    }
    res=0;
    for (auto wh:reb[now]){
        if (!calc_now[wh][cnt^1]){
            if (dfs(wh,cnt^1)){
                res=1;
                go[now][cnt]=wh;
                calc_now[now][cnt]=0;
                return 1;
            }
        }
    }
    calc_now[now][cnt]=0;
    return res;
}

bool use1[arr];
bool calc_now1[arr];
bool OK=0;

void dfs1(int now)
{
    use1[now]=1;
    calc_now1[now]=1;
    for (auto wh:reb[now]){
        if (use1[wh]){
            if (calc_now1[wh]){
                OK=1;
            }
        }
        else{
            dfs1(wh);
        }
    }
    calc_now1[now]=0;
}

bool is_cycle_from_s(int s)
{
    dfs1(s);
    return OK;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int c;
        cin>>c;
        while (c--){
            int v;
            cin>>v;
            reb[i].pb(v);
        }
    }
    int s;
    cin>>s;
    bool ok=dfs(s,1);
    if (ok){
        cout<<"Win"<<"\n";
        vi ans(0);
        int cur1=s;
        int cur2=1;
        while (cur1!=-1){
            ans.pb(cur1);
            cur1=go[cur1][cur2];
            cur2^=1;
        }
//        cout<<len(ans)<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    elif (is_cycle_from_s(s)){
        cout<<"Draw"<<"\n";
    }
    else{
        cout<<"Lose"<<"\n";
    }
}