#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;
 
// #define int ll
 
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
 
 
void GG(){cout<<"No\n"; exit(0);}
 
ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}
 
ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}
 
const int maxn = 2e5+5;
 
struct trie{
    trie* c0=nullptr, *c1=nullptr;
    int sz = 0;
}pool[maxn*31], *ptr=pool;
 


void add(trie *at, int x, int val){
    trie* now = at;
    RREP(i, 30){
        if (x&(1<<i)){
            if (!now->c1) now->c1 = new(ptr++) trie;
            now = now->c1;
        }else{
            if (!now->c0) now->c0 = new (ptr++) trie;
            now = now->c0;
        }
        now->sz+=val;
    }
}
 
int close(trie *at, int x){
    trie* now = at;
    int re = 0;
    // cout<<"ALIVE"<<endl;
    RREP(i, 30){
        if (x&(1<<i)){
            if (now->c1 && now->c1->sz) now = now->c1;
            else now = now->c0, re += (1<<i);
        }else{
            if (now->c0 && now->c0->sz) now = now->c0;
            else now = now->c1, re += (1<<i);
        }
    }
    // cout<<"OUT"<<endl;
    return re;
}
 
int par[maxn];
 
//No union by rank 
void setUp (int n){
    for (int i=0; i<n; i++) par[i]=i; //From 0
}
 
int find(int x){
    if (x==par[x]) return x;
    return par[x] = find(par[x]);
}
 
void merge(int a, int b){
    par[find(a)]=par[find(b)];
}
 
vector<int> g[maxn];
 unordered_map<int, int> mp;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    setUp(n);
    vector<int> a(n);
    trie* head = new trie;
    
    REP(i,n) cin>>a[i], add(head, a[i],1), mp[a[i]]=i;
    // int it = log2(n)+1;
    ll re = 0;
    int edges = 0;
    while (edges<n-1){
        // g.clear();
        REP(i,n){
            g[find(i)].pb(i);
        }
        REP(i,n){
            if (!g[i].size()) continue; 
            vector<int> &v = g[i]; 
            ll bst = inf, bat = -1;
            for (int at: v){
                add(head, a[at], -1);
            }
            for (int at : v){
                int m = close(head, a[at]);
                if (m < bst){
                    bst = m; bat = a[at]^m;
                }
            }
            for (int at: v){
                add(head, a[at], 1);
            }
            if (find(v[0])!=find(mp[bat])){
                merge(v[0], mp[bat]);
                edges++;
                re += bst;
            }
            g[i].clear();
            // cout<<v[0]<<" -> "<<mp[bat]<<endl;
        }
        // debug(edges);
        // return 0;
    }
    cout<<re<<endl;
    
}