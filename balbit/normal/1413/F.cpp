#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
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

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


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

const int maxn = 5e5+5;

vector<pii> g[maxn];
int A[maxn], B[maxn], C[maxn];
pii bst = {-1, -1};
int n;

void far(int v, int p, int d = 0) {
    bst = max(bst, {d, v});
    for (pii u : g[v]) {
        if (u.f != p) {
            far(u.f,v,d+1);
        }
    }
}

int bot[maxn];
int L[maxn], R[maxn];
bool tg[maxn*4];
int s[maxn*4][2];
int mydep[maxn];
int IT = 0;

void push(int o, int l, int r) {
    if (tg[o]){
        swap(s[o][0], s[o][1]);
        if (l!= r) {
            tg[o*2] ^= 1; tg[o*2+1] ^= 1;
        }
        tg[o] = 0;
    }
}

void FLIP(int L, int R, int o=1, int l=0, int r=maxn-1){
    push(o,l,r);
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tg[o] ^= 1;
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    FLIP(L,R,o*2,l,mid);
    FLIP(L,R,o*2+1,mid+1, r);
    s[o][0] = max(s[o*2][0], s[o*2+1][0]);
    s[o][1] = max(s[o*2][1], s[o*2+1][1]);
//    if (s[o][0] != 3 && s[o][0] != 0) bug(o, s[o][0]);
}

void build(int o, int l, int r){
    if (l == r) {
        if (l < n) {
            s[o][0] = mydep[l];
        }
        return;
    }
    int mid = (l+r)/2;
    build(o*2, l, mid);
    build(o*2+1, mid+1, r);
    s[o][0] = max(s[o*2][0], s[o*2+1][0]);
}

void initdfs(int v, int p, int d = 0) {
    mydep[IT] = d;
    L[v] = R[v] = IT++;
    for (pii u : g[v]) {
        if (u.f != p) {
            initdfs(u.f, v, d+1);
            bot[u.s] = u.f;
            R[v] = R[u.f];
        }
    }
}

vector<int> que;
int ANS[maxn];

void go(int rt) {
    memset(s, 0, sizeof s);
    memset(tg, 0, sizeof tg);
    IT = 0;
    initdfs(rt, -1);
    build(1, 0, maxn-1);
    for (int i = 0; i<n-1; ++i) {
        if (C[i]) {
            FLIP(L[bot[i]], R[bot[i]]);
        }
    }
    for (int i = 0; i<SZ(que); ++i){
        int x = que[i];
        FLIP(L[bot[x]], R[bot[x]]);
        bug(L[bot[x]], R[bot[x]]);
        ANS[i] = max(ANS[i], s[1][0]);
        bug(i, rt, s[1][0]);
    }
}

signed main(){
    IOS();
    cin>>n;
    for (int i = 0 ; i<n-1; ++i) {
        int a,b,c; cin>>a>>b>>c; --a; --b;
        tie(A[i], B[i], C[i]) = tie(a,b,c);
        g[a].pb({b,i});
        g[b].pb({a,i});
    }
    far(0, -1, 0);
    int S1 = bst.s;
    bst = {-1,-1};
    far(S1, -1, 0);
    int S2 = bst.s;
    bug(S1, S2);
    int q; cin>>q;
    while (q--) {
        int x; cin>>x; que.pb(x-1);
    }
    go(S2); go(S1);
    for (int i = 0; i<SZ(que); ++i){
        cout<<ANS[i]<<endl;
    }

}