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

int p[arr];
int s[arr];
int dp[arr];
vi reb[arr];
int ans=0;

void dfs(int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
        }
    }
    if (s[now]==-1){
        dp[now]=md;
    }
    else{
        dp[now]=s[now];
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            dp[now]=min(dp[now],dp[wh]);
        }
    }
//    cout<<"dp["<<now<<"] :: "<<dp[now]<<"\n";
}

void dfs2(int now,int pred,int cur=0)
{
    if (s[now]==-1){
        if (dp[now]!=md){
            if (dp[now]<cur){
                cout<<-1<<"\n";
                exit(0);
            }
            ans+=dp[now]-cur;
            cur=dp[now];
        }
    }
    else{
        if (s[now]<cur){
            cout<<-1<<"\n";
            exit(0);
        }
        ans+=s[now]-cur;
        cur=s[now];
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs2(wh,now,cur);
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=2;i<=n;i++){
        cin>>p[i];
        reb[i].pb(p[i]);
        reb[p[i]].pb(i);
    }
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    dfs(1,1);
    dfs2(1,1);
    cout<<ans<<"\n";
}