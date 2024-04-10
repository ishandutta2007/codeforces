#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 998244353;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 6e5+5;

int wp[maxn]; // which P is this connected to, -1 if not applicable
int col[maxn]; // 1 for connecting to black edge, 0 for white
ll p2[maxn];

inline void ADD(ll &a, ll b) {
    a += b; if (a >= mod) a-= mod;
}

ll rehsh = 0;

struct pth{
    int u, v;
    vector<int> B, W; // black and white edges
    ll hsh, tothsh; // hsh is the sum of stuff in B
    void flip(){
        B.swap(W);
        rehsh -= hsh;
        hsh = (tothsh - hsh+mod)%mod;
        rehsh += hsh;
        rehsh = (rehsh%mod + mod) % mod;
        col[u] ^= 1; col[v] ^= 1;
    }
    void ad(int id, bool toB, bool trans = 0) {
        (toB?B:W).pb(id);
        if (toB) {
            ADD(hsh, p2[id]);
            if (!trans) ADD(rehsh, p2[id]);
        }
        ADD(tothsh, p2[id]);
    }
    pth(int a, int b, int i) {
        u=a; v=b;
        B.pb(i);
        col[u] = col[v] = 1;
        hsh = tothsh = p2[i];
        ADD(rehsh, p2[i]);
    }
    pth(){
        u=v=hsh=tothsh = 0;
    }
};

vector<pth> P;
bool dead[maxn];

void add(int a, int b, int id) {
    if (wp[a] > wp[b]) swap(a,b);
    if (wp[a] == -1 && wp[b] == -1) {
        // new path
        wp[a] = wp[b] = SZ(P);
        P.pb(pth(a,b,id));
    }else if (wp[a] == -1 && wp[b] != -1) {
        // expand wp[b]
        pth &yo = P[wp[b]];
        wp[a] = wp[b];
        col[a] = col[b] ^ 1;
        yo.ad(id, col[a]);
        wp[b] = -1;
        if (yo.u == b) yo.u = a;
        else yo.v = a;
    }else if (wp[a] == wp[b]){
        pth &yo = P[wp[a]];
        yo.ad(id, col[a] ^ 1);
        wp[a] = wp[b] = -1;
    }else{
        // merge.......
        // log
        if (SZ(P[wp[a]].B) < SZ(P[wp[b]].B)) swap(a,b); // merge b into a
        pth & ya = P[wp[a]], &yb = P[wp[b]];
        if (col[b] != col[a]) {
            yb.flip();
        }
        ya.ad(id, col[a] ^ 1);
        for (int x : yb.B) ya.ad(x, 1, 1);
        for (int x : yb.W) ya.ad(x, 0, 1);
        int oth = yb.u ^ yb.v ^ b;
        if (ya.u == a) ya.u = oth;
        else ya.v = oth;
        dead[wp[b]] = 1;
        wp[oth] = wp[a];
        wp[b] = wp[a] = -1;
    }
}

signed main(){
    IOS();
    memset(wp, -1, sizeof wp);
    p2[0] = 1;
    for (int i = 1; i<maxn; ++i) {
        p2[i] = p2[i-1] * 2 % mod;
    }
    int N1, N2, m;
    cin>>N1>>N2>>m;
    REP(i,m) {
        int a,b; cin>>a>>b; --a; --b;
        b += N1;
        add(a,b,i+1);
    }
    int q; cin>>q;
    int edgenow = 0;
    REP(cnt, q) {
        int tp; cin>>tp;
        if (tp == 1) {
            int a,b; cin>>a>>b; --a; --b;
            b += N1;
            add(a,b,edgenow + m + 1);
            cout<<rehsh<<endl<<flush;
            ++edgenow;
        }else{
            vector<int> ree;
            REP(i, SZ(P)) {
                if (!dead[i]) {
                    for (int x : P[i].B) {
                        ree.pb(x);
                    }
                }
            }
            cout<<SZ(ree)<<' ';
            sort(ALL(ree));
            for( int x : ree ) {
                cout<<x<<' ';
            }
            cout<<endl<<flush;
        }
    }
}