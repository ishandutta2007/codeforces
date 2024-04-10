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

#define arr (int)(1e5+10)

int n,m,d;
string s[arr];

vi reb[arr];
vi rreb[arr];

bool ok(int ver,int day)
{
    return s[ver][day]=='1';
}

bool use[arr];

void dfs1(int now,vi& top)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs1(wh,top);
        }
    }
    top.pb(now);
}

int pos_in_top[arr];
vi in_comp[arr];
int what[arr];

void dfs2(int now,pair<int,int>& comp)
{
    use[now]=1;
    comp.fir=min(comp.fir,pos_in_top[now]);
    in_comp[comp.sec].pb(now);
    for (auto wh:rreb[now]){
        if (!use[wh]){
            dfs2(wh,comp);
        }
    }
}

int dp[arr][50];
int new_dp[arr][50];

bool used[arr][50];

void dfs3(int now,int j,vector<pii>& top)
{
    used[now][j]=1;
    for (auto wh:reb[now]){
        if (what[wh]==what[now]&&!used[wh][(j+1==d?0:j+1)]){
            dfs3(wh,(j+1==d?0:j+1),top);
        }
    }
    top.pb(mp(now,j));
}

void dfs4(int now,int j,vector<pii>& cur)
{
    used[now][j]=1;
    for (auto wh:rreb[now]){
        if (what[wh]==what[now]&&!used[wh][(j==0?d-1:j-1)]){
            dfs4(wh,(j==0?d-1:j-1),cur);
        }
    }
    cur.pb(mp(now,j));
}

int buf[arr];

void upd_dp(int num_of_comp)
{
//    cout<<"upd_dp :: ";
//    for (auto i:in_comp[num_of_comp]){
//        cout<<i<<" ";
//    }
//    cout<<"\n";

    vector<pii> top(0);
    for (auto i:in_comp[num_of_comp]){
        for (int j=0;j<d;j++){
            if (!used[i][j]){
                dfs3(i,j,top);
            }
        }
    }
    reverse(all(top));
//    cout<<"top ::: ";
//    for (auto i:top){
//        cout<<"("<<i.fir<<","<<i.sec<<")"<<",";
//    }
//    cout<<"\n";

    for (auto i:in_comp[num_of_comp]){
        for (int j=0;j<d;j++){
            used[i][j]=0;
        }
    }
    for (auto j:top){
        new_dp[j.fir][j.sec]=-1e9;
    }
    vector<pii> current(0);
    for (auto i:top){
        if (!used[i.fir][i.sec]){
            current.clear();
            dfs4(i.fir,i.sec,current);

//            cout<<"current :: ";
//            for (auto j:current){
//                cout<<"("<<j.fir<<","<<j.sec<<")"<<",";
//            }
//            cout<<"\n";

            int best_dp_prev=-1e9;
            for (auto j:current){
                best_dp_prev=max(best_dp_prev,dp[j.fir][j.sec]);
            }

            for (auto j:current){
                buf[j.fir]=0;
            }
            int new_lol=0;
            for (auto j:current){
                if (ok(j.fir,j.sec)&&buf[j.fir]==0){
                    new_lol++;
                    buf[j.fir]=1;
                }
            }
            for (auto j:current){
                new_dp[j.fir][j.sec]=max(new_dp[j.fir][j.sec],best_dp_prev+new_lol);
            }
            for (auto j:current){
                buf[j.fir]=0;
            }
        }
    }
    for (auto j:top){
        dp[j.fir][j.sec]=new_dp[j.fir][j.sec];
    }
    for (auto i:in_comp[num_of_comp]){
        for (int j=0;j<d;j++){
            for (auto to:reb[i]){
                if (what[to]!=what[i]){
                    dp[to][(j+1==d?0:j+1)]=max(dp[to][(j+1==d?0:j+1)],dp[i][j]);
                }
            }
        }
    }
}

int solve()
{
    vi top(0);
    for (int i=0;i<n;i++){
        use[i]=0;
    }
    for (int i=0;i<n;i++){
        if (!use[i]){
            dfs1(i,top);
        }
    }
    reverse(all(top));

    for (int i=0;i<len(top);i++){
        pos_in_top[top[i]]=i;
    }

    for (int i=0;i<n;i++){
        use[i]=0;
    }
    vector<pair<int,int>> comps(0);
    for (auto i:top){
        if (!use[i]){
            int num=len(comps);
            comps.pb(mp(1e9,num));
            dfs2(i,comps.back());
        }
    }
    sort(all(comps));
    for (auto i:comps){
        for (auto j:in_comp[i.sec]){
            what[j]=i.sec;
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<d;j++){
            dp[i][j]=-1e9;
        }
    }
    dp[0][0]=0;
    for (auto i:comps){
        upd_dp(i.sec);
    }

    int res=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<d;j++){
            res=max(res,dp[i][j]);
        }
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m>>d;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        reb[u].pb(v);
        rreb[v].pb(u);
    }
    for (int i=0;i<n;i++){
        cin>>s[i];
    }

    int ans=solve();

    cout<<ans<<"\n";
}