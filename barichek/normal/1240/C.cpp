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

#define arr (int)(5e5+10)

int k;
vector<pii> reb[arr];

int get_int(const vector<pii>& a,int cnt)
{
    if (len(a)<cnt){
        int res=0;
        for (auto i:a){
            res+=max(i.fir,i.sec);
        }
        return res;
    }

    /// len(a)>=cnt
    int res=0;
    for (int i=0;i<cnt;i++){
        res+=max(a[i].fir,a[i].sec);
    }
    for (int i=cnt;i<len(a);i++){
        res+=a[i].fir;
    }
    return res;
}

pii get_pair(vector<pii>& res)
{
    sort(all(res),[&](pii a,pii b){
        return max(a.fir,a.sec)-a.fir>max(b.fir,b.sec)-b.fir;
    });
    return make_pair(get_int(res,k),get_int(res,k-1));
}

pii dfs(int now,int pred)
{
    vector<pii> res;
    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            res.pb(dfs(wh.fir,now));
            res.back().sec+=wh.sec;
        }
    }
    return get_pair(res);
}

void solve()
{
    int n;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        reb[i].clear();
    }
    for (int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        reb[u].pb(mp(v,w));
        reb[v].pb(mp(u,w));
    }
    pii res=dfs(1,-1);
    cout<<max(res.fir,res.sec)<<"\n";
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