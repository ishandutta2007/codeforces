#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  3e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test=1, n, k, a[N], flag = 0, p[N], X[N], sz[N], ct[N], f[N];
ll parent[N], level[N], visited[N];
ll st[N][LEVEL];
vll adj[N];

void findparent(ll n, ll prev){
    visited[n] = 1;
    parent[n] = prev;
    if(prev != -1)
        level[n] = level[prev]+1;
    for(ll i = 0; i < adj[n].size(); i++){
        if(visited[adj[n][i]] == 0){
            findparent(adj[n][i],n);
        }
    }
}
 
void clearall(){
    for(ll i = 0; i < N; i++){
        parent[i] = -1;
        level[i] = -1;
        visited[i] = 0;
        for(ll j = 0; j < LEVEL; j++)
            st[i][j] = -1;
    }
}
 
void fillst(ll n){
    clearall();
    ll i,j;
    findparent(1,-1);
    for(j = 0; j < LEVEL; j++){
        for(i = 1; i <= n; i++){
            if(j == 0)
                st[i][j] = parent[i];
            if(st[i][j-1] != -1){
                st[i][j] = st[st[i][j-1]][j-1];
            }
        }
    }
}
 
ll lca(ll x, ll y){
    if(level[y] < level[x])
        swap(x,y);
    ll diff = level[y]-level[x];
    for(ll i = 0;i < LEVEL; i++){
        // Checks all set bits in diff
        if((diff>>i)&1){
            y = st[y][i];
        }
    }
    if(x == y)
        return x;
    for(ll i = LEVEL-1; i >= 0; i--){
        // First highest of x and y that are unequal
        if(st[x][i] != -1 && st[x][i] != st[y][i]){
            x = st[x][i];
            y = st[y][i];
        }
    }
    return st[x][0];
}

void make(ll n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(ll x){
    return (parent[x] == x)? x: parent[x] = find(parent[x]);
}

void merge(ll x, ll y){
    ll a = find(x);
    ll b = find(y);
    if(a != b){
        if(sz[a] >= sz[b]) swap(a,b);
        parent[a] = b;
        sz[b] += sz[a];
        ct[b] += ct[a];
    }
}

void assign(ll x, ll par){
    for(auto it : adj[x]){
        if(it == par) continue;
        assign(it,x);
        if(flag){
            if(a[x] != 0 and a[x] != flag){
                deb1(0)
                exit(0);
            }
            a[x] = flag;
        }
    }
    if(a[x]) flag = a[x];
    if(x == p[flag]) flag = 0;
}

ll rem(ll x, ll par){
    ll ch = a[x];
    for(auto it : adj[x]){
        if(it == par) continue;
        ch |= rem(it,x);
    }
    if(ch == 0) X[x] = 1;
    return ch;
}

void dfs(ll x, ll par){
   for(auto it : adj[x]){
        if(it == par) continue;
        if(X[x] != 1){
            if(a[x] != 0 and a[it] == 0) ct[it]++;
            dfs(it,x);
            if(a[it] != 0 and a[x] == 0) ct[x]++;
            if(a[x] == 0 and a[it] == 0){
                merge(it,x);
            }
        }
    }
}

ll mod_inverse(ll x, ll y = mod-2){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return f[n] * mod_inverse(f[r]) % mod * mod_inverse(f[n - r]) % mod;
}


void solve(){
    mset(X,0);
    mset(p,-1);
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fillst(n);
    for(int i = 1; i <= n; i++){
        if(a[i] == 0) continue;
        if(p[a[i]] == -1) p[a[i]] = i;
        else{
            p[a[i]] = lca(p[a[i]],i);
            if(a[p[a[i]]] == 0 or a[p[a[i]]] == a[i]) a[p[a[i]]] = a[i];
            else{
                deb1(0)
                return;
            }
        }
    }
    assign(1,0);
    rem(1,0);
    // for(int i = 1; i <= n; i++) cout<<a[i]<<" "; cout<<endl;
    // for(int i = 1; i <= n; i++) cout<<X[i]<<" "; cout<<endl;
    make(n);
    dfs(1,0);
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0 and find(i) == i){
            // deb3(i,sz[i],ct[i])
            ans = (ans*ncr(sz[i]+ct[i]-1,ct[i]-1))%mod;
        }
    }
    deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}