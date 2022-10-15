#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 3e5+5;

struct trie{
    array<int, 26> ch;
    int sz=0;
    trie(){
        sz = 1;
        fill(ALL(ch),0);
    }
}T[1000000+5];

void add(int a, int b) {
    // Add trie b to trie a
    if (T[b].sz == 1) return;
    REP(c,26) {
        if (!T[b].ch[c]) continue;
        if (!T[a].ch[c]) {
            T[a].ch[c] = T[b].ch[c];
            T[a].sz += T[T[b].ch[c]].sz;
        }else{
            T[a].sz -= T[T[a].ch[c]].sz;
            add(T[a].ch[c], T[b].ch[c]);
            T[a].sz += T[T[a].ch[c]].sz;
        }
    }
}

ll TAT = 1;
ll cst[maxn];
string s;
int n;
vector<int> g[maxn];
int siz[maxn];

int tof[maxn]; // Trie id of v
ll mxre = 0, mxcnt = 0;
void dfs(int v, int p = -1) {
    siz[v] = 1;
    vector<int> head(26,-1);
    for (int u : g[v]) {
        if (u!=p) {
            dfs(u,v);
            siz[v] += siz[u];
            if (head[s[u]-'a']==-1 || siz[u] > siz[head[s[u]-'a']]) {
                head[s[u]-'a']=u;
            }
        }
    }
    tof[v] = TAT ++;
    trie & mn = T[tof[v]]; // Main trie to be dealt with now
    REP(i,26) {
        if (head[i] !=-1) {
            mn.ch[i]=tof[head[i]];
        }
    }
    for (int u : g[v]) {
        if (u!=p){
            if (head[s[u]-'a'] != u) {
                add(mn.ch[s[u]-'a'], tof[u]);
            }
        }
    }
    REP(i,26) {
        if (mn.ch[i]) mn.sz += T[mn.ch[i]].sz;
    }
    bug(v+1, mn.sz);
    ll myn = mn.sz + cst[v];
    if (myn == mxre) mxcnt++;
    else if (myn > mxre) mxre = myn, mxcnt = 1;
}

signed main(){
    IOS();
    T[0].sz = -10000000;
    cin>>n;
    REP(i,n) cin>>cst[i];
    cin>>s;
    REP(i,n-1) {
        int a,b;cin>>a>>b;g[a-1].pb(b-1);g[b-1].pb(a-1);
    }
    dfs(0);
    cout<<mxre<<'\n'<<mxcnt<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}