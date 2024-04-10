//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define arr (int)(3e5+10)

vi reb[arr];
int dp[arr];
int c[arr];

int ans;

void dfs(int now,int pred)
{
    vi a(0);
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
            a.pb(dp[wh]-1);
        }
    }
    sort(all(a));
    if (len(a)>=2){
        ans=max(ans,c[now]+a[len(a)-1]+a[len(a)-2]);
    }
    else if (len(a)==1){
        ans=max(ans,c[now]+a[len(a)-1]);
    }

    dp[now]=c[now];
    for (auto i:a){
        dp[now]=max(dp[now],i+c[now]);
    }
//    cout<<"dp["<<now<<"] :: "<<dp[now]<<"\n";
}

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        reb[i].clear();
        c[i]=0;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
        c[u]++;
        c[v]++;
    }
    ans=0;
    dfs(1,-1);
    cout<<ans+1<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int q;
    cin>>q;
    while (q--){
        solve();
    }
}