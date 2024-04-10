#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 200005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

template<typename T>
struct node{
    int l,r;
    T mx,mn,sum,lazy;
};

template<typename T>
struct HLDSegTree{
    node<T> seg[4*MAXN];
    inline ll sz(int rt){return seg[rt].r-seg[rt].l+1;}
    inline void push_up(int rt){
        seg[rt].mx = max(seg[rt<<1].mx,seg[rt<<1|1].mx);
        seg[rt].mn = min(seg[rt<<1].mn,seg[rt<<1|1].mn);
        seg[rt].sum = seg[rt<<1].sum+seg[rt<<1|1].sum;
    }
    inline void push_down(int rt){
        seg[rt<<1].mx+=seg[rt].lazy, seg[rt<<1|1].mx+=seg[rt].lazy;
        seg[rt<<1].mn+=seg[rt].lazy, seg[rt<<1|1].mn+=seg[rt].lazy;
        seg[rt<<1].sum+=seg[rt].lazy*sz(rt<<1), seg[rt<<1|1].sum+=seg[rt].lazy*sz(rt<<1|1);
        seg[rt<<1].lazy+=seg[rt].lazy, seg[rt<<1|1].lazy+=seg[rt].lazy;
        seg[rt].lazy = 0;
    }
    void build(int l, int r, int rt){
        seg[rt].l = l, seg[rt].r = r, seg[rt].sum = seg[rt].lazy = 0, seg[rt].mn = INT_INF, seg[rt].mx = -INT_INF;
        if(l == r) return;
        int mid = (l+r)/2;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
    }
    void update(int l, int r, int rt, T val){
        if(l > r) return;
        if(seg[rt].l == l && seg[rt].r == r){
            seg[rt].mx+=val, seg[rt].mn+=val, seg[rt].lazy+=val;
            seg[rt].sum+=val*sz(rt);
            return;
        }
        if(seg[rt].lazy) push_down(rt);
        int mid = (seg[rt].l+seg[rt].r)/2;
        if(r <= mid) update(l,r,rt<<1,val);
        else if(l > mid) update(l,r,rt<<1|1,val);
        else update(l,mid,rt<<1,val), update(mid+1,r,rt<<1|1,val);
        push_up(rt);
    }
    T query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return seg[rt].sum;
        if(seg[rt].lazy) push_down(rt);
        int mid = (seg[rt].l+seg[rt].r)/2;
        if(r <= mid) return query(l,r,rt<<1);
        else if(l > mid) return query(l,r,rt<<1|1);
        return query(l,mid,rt<<1)+query(mid+1,r,rt<<1|1);
    }
};

template<typename T>
struct HLD{
    int sz[MAXN],heavy[MAXN],par[MAXN],head[MAXN],depth[MAXN],pos[MAXN],cnt=0;
    HLDSegTree<T> seg;
    vector<pair<int,ll>> connections[MAXN];
    vector<pair<pii,int>> paths[MAXN];
    inline void add_edge(int a, int b, ll val = 0){
        connections[a].pb(mp(b,val));
        connections[b].pb(mp(a,val));
    }
    int dfs(int node, int prev){
        sz[node] = 1;
        for(pair<int,ll> check:connections[node]){
            if(check.first == prev) continue;
            par[check.first] = node, depth[check.first] = depth[node]+1;
            int tmp = dfs(check.first,node);
            if(tmp > sz[heavy[node]]) heavy[node] = check.first;
            sz[node]+=tmp;
        }
        return sz[node];
    }
    void decompose(int node, int prev, int hh){
        head[node] = hh, pos[node] = ++cnt;
        if(heavy[node]) decompose(heavy[node],node,hh);
        for(pair<int,ll> check:connections[node]){
            if(check.first == prev || check.first == heavy[node]) continue;
            decompose(check.first,node,check.first);
        }
    }
    inline void init(){
        memset(heavy,0,sizeof heavy);
        memset(head,0,sizeof head);
        memset(depth,0,sizeof depth);
        memset(par,0,sizeof par);
        dfs(1,-1);
        decompose(1,-1,1);
        seg.build(1,cnt,1);
    }
    inline int lca(int a, int b){
        for(; head[a] != head[b]; b = par[head[b]])
            if(depth[head[a]] > depth[head[b]]) swap(a,b);
        if(depth[a] > depth[b]) swap(a,b);
        return a;
    }
    inline void update(int a, int b, T v){
        for(; head[a] != head[b]; b = par[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a,b);
            seg.update(pos[head[b]],pos[b],1,v);
        }
        if(depth[a] > depth[b]) swap(a,b);
        seg.update(pos[a],pos[b],1,v);
    }
    inline T query(int a, int b){
        T res = 0;
        for(; head[a] != head[b]; b = par[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a,b);
            res+=seg.query(pos[head[b]],pos[b],1);
        }
        if(depth[a] > depth[b]) swap(a,b);
        return res+seg.query(pos[a],pos[b],1);
    }
};

int N,M;
ll dp[MAXN],ch_sum[MAXN];
HLD<ll> hld,d;

void solve(int node, int prev){
    for(auto check:hld.connections[node]){
        if(check.first == prev) continue;
        solve(check.first,node);
        ch_sum[node]+=dp[check.first];
    }
    dp[node] = ch_sum[node];
    hld.update(node,node,ch_sum[node]);
    for(pair<pii,int> check:hld.paths[node]){
        ll val = hld.query(check.first.first,check.first.second)-d.query(check.first.first,check.first.second)+check.second;
        dp[node] = max(dp[node],val);
    }
    d.update(node,node,dp[node]);
}

int main(){
    fastio; cin >> N >> M;
    for(int i=2; i<=N; i++){
        int p; cin >> p;
        hld.add_edge(p,i);
        d.add_edge(p,i);
    }
    hld.init();
    d.init();
    for(int i=1; i<=M; i++){
        int a,b,c; cin >> a >> b >> c;
        hld.paths[hld.lca(a,b)].pb(mp(mp(a,b),c));
    }
    solve(1,-1);
    cout << dp[1] << endl;
}