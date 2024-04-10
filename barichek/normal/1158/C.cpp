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

const int arr=2e6+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define arr (int)(5e5+10)

vi reb[arr*4];
int rev[arr*4];
int ended[arr*4];
bool use[arr*4];

void clear(int v,int l,int r)
{
    use[v]=0;
    ended[v]=0;
    reb[v].clear();
    if (l==r){
        ended[v]=l;
        rev[l]=v;
        return;
    }
    int m=(l+r)/2;
    reb[v].pb(v*2);
    reb[v].pb(v*2+1);
    clear(v*2,l,m);
    clear(v*2+1,m+1,r);
}

void push_smaller(int v,int l,int r,int tl,int tr,int from)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        reb[rev[from]].pb(v);
        return;
    }
    int m=(l+r)/2;
    push_smaller(v*2,l,m,tl,tr,from);
    push_smaller(v*2+1,m+1,r,tl,tr,from);
}

int nn[arr];
vi top;

void dfs(int now)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs(wh);
        }
    }
    top.pb(now);
}

void lol(int v,int l,int r)
{
    if (!use[v]){
        dfs(v);
    }
    if (l==r){
        return;
    }
    int m=(l+r)/2;
    lol(v*2,l,m);
    lol(v*2+1,m+1,r);
}

int pos_in_top[arr*4];
int ans[arr];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>nn[i];
    }
    clear(1,1,n);
    for (int i=1;i<=n;i++){
        if (nn[i]!=-1){
            if (nn[i]!=i+1){
                push_smaller(1,1,n,i+1,nn[i]-1,i);
            }
            if (nn[i]!=n+1){
                reb[rev[nn[i]]].pb(rev[i]);
            }
        }
    }
    top.clear();
    lol(1,1,n);
    reverse(all(top));
    for (int i=0;i<len(top);i++){
        pos_in_top[top[i]]=i;
    }
    bool ok=1;
    for (auto i:top){
        for (auto j:reb[i]){
            if (pos_in_top[j]<pos_in_top[i]){
                ok=0;
            }
        }
    }
    if (!ok){
        cout<<-1<<"\n";
        return;
    }
    int cur=n;
    for (auto i:top){
        if (ended[i]){
            ans[ended[i]]=cur;
            cur--;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}