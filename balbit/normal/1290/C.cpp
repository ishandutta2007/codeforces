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

bool arr[maxn];
int par[maxn];
int cst[maxn], c0[maxn], c1[maxn]; // Cost of this chunk
int dir[maxn]; // Direction of this node
bool def[maxn]; // Definitely True?
int n, k;
ll re = 0;
void setup(){
    REP(i,k) {
        par[i] = i;
        c0[i]=1;
    }
}
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
vector<pair<int, bool> > g[maxn];

void dfs(int v, int p=-1) {
    for (pair<int, bool> u : g[v]) {
        if (u.f!=p) {
            dir[u.f] = dir[v]^u.s; dfs(u.f,v);
        }
    }
}
void setto(int a, bool x) {
    if (dir[a] == x) return;
    dir[a] = x; dfs(a);
    int A = find(a);
    swap(c0[A], c1[A]);
}
void Merge(int a, int b, bool TP) {
    int A = find(a), B = find(b);
    if (A==B || (def[A] && def[B]) ) return;
    bug(A,B, def[A], def[B]);
    if (def[A]!=def[B]) {
        if (def[A]) {
            swap(A,B); // B is definite
            swap(a,b);
        }
//        if (dir[a]!=dir[b]^TP) {
            setto(a, dir[b]^TP);
            re += (c1[A]-min(c0[A], c1[A]));

    }
    else if (!def[A] && !def[B]) {
        if (c0[A] + c1[A] > c0[B] + c1[B]) {
            swap(A,B); swap(a,b);
        }
        setto(a,dir[b]^TP);
        re -= min(c0[A],c1[A]) + min(c0[B],c1[B]);
    }
    c0[B] += c0[A]; c1[B] += c1[A];
    if (!def[A] && !def[B]) {
        re += min(c0[B], c1[B]);
    }
    par[A] = B;
    g[a].pb({b,TP});
    g[b].pb({a,TP});

}

vector<int> in[maxn];

signed main(){
    IOS();
    cin>>n>>k;
    setup();
    REP(i,n) {
        char c; cin>>c; arr[i] = c=='1';
    }
    REP(cnt, k) {
        int m; cin>>m;
        REP(i,m) {
            int x; cin>>x; x--; in[x].pb(cnt);
        }
    }
    REP(i,n) {
        bug(i);
        if (SZ(in[i]) == 1){
            setto(in[i][0],arr[i]^1);
//            bug(in[i][0],arr[i]^1);
            int fi = find(in[i][0]);
            if (!def[fi]) {
                def[fi] = 1;
                re += (c1[fi]-min(c0[fi], c1[fi]));
            }
        }else if (SZ(in[i]) == 2) {
//            bug("merge prep" );
//            bug(in[i][0],in[i][1],arr[i] ^ 1);
            Merge(in[i][0],in[i][1], arr[i] ^ 1);
        }
//        REP(i,k) cout<<dir[i];
//        cout<<endl;
        cout<<re<<endl;
    }
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}