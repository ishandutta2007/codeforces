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

const int maxn = 2e5+5;

int n,m;
vector<vector<char> > C;
vector<int > g[maxn];

int L[maxn], R[maxn];
array<int, 2> it;

inline int id(int i, int j) {
    return i*m + j;
}

bool seen[maxn];

bool nowpar = 0; // current parity of i+j

void dfs(int v) {
    if (seen[v]) return;
    seen[v] = 1;
    L[v] = R[v] = ++it[nowpar];
    for (int u : g[v]) {
        dfs(u);
        R[v] = max(R[v], R[u]);
    }
}

bool parof[maxn];

int mn[maxn<<2], nummn[maxn*4], s[maxn*4], tg[maxn*4]; // s is number of nonzero elements

void push(int o, int l, int r) {
    if (tg[o] == 0) return;
    if (mn[o] == 0 && tg[o] > 0) s[o] += nummn[o];
    mn[o] += tg[o];
    if (mn[o] == 0 && tg[o] < 0) s[o] -= nummn[o];
    if (l!=r) {
        tg[o*2] += tg[o];
        tg[o*2+1] += tg[o];
    }
    tg[o]=0;
}



void MO(int L, int R, int v, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l>=L && r <= R) {
        tg[o] += v;
        push(o,l,r);
        return;
    }
    int m = (l+r)/2;
    MO(L,R,v,o*2,l,m);
    MO(L,R,v,o*2+1,m+1,r);
    if (mn[o*2] == mn[o*2+1]) {
        mn[o] = mn[o*2]; nummn[o] = nummn[o*2] + nummn[o*2+1];
    }
    else{
        tie(mn[o], nummn[o]) = min(tie(mn[o*2], nummn[o*2]), tie(mn[o*2+1], nummn[o*2+1]));
    }
    s[o] = s[o*2] + s[o*2+1];
}

void build(int o=1, int l=0, int r = maxn-1) {
    nummn[o] = (r-l+1);
    if (l==r) return;
    int mid = l+r>>1;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
}
struct ev{
    int y, l, r, val;
};

signed main(){
    IOS();
    build();
    cin>>n>>m;
    C = vector<vector<char> > (n, vector<char> (m));
    vector<int> st;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            parof[id(i,j)] = (i+j)%2;
            cin>>C[i][j];
            if (C[i][j] == 'U') {
                if (i+2 < n) g[id(i+2,j)].pb(id(i,j));
                else st.pb(id(i,j));
            }
            if (C[i][j] == 'D') {
                if (i-2 >=0) g[id(i-2,j)].pb(id(i,j));
                else st.pb(id(i,j));
            }
            if (C[i][j] == 'L') {
                if (j+2 < m) g[id(i,j+2)].pb(id(i,j));
                else st.pb(id(i,j));
            }
            if (C[i][j] == 'R') {
                if (j-2 >=0) g[id(i,j-2)].pb(id(i,j));
                else st.pb(id(i,j));
            }
        }
    }

    for (int v : st) {
        nowpar = parof[v];
        dfs(v);
    }
    vector<ev> E;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            int frd = -1, me = id(i,j);
            if (C[i][j] == 'U') {
                frd = id(i+1,j);
            }
            if (C[i][j] == 'L') {
                frd = id(i,j+1);
            }
            if (frd != -1) {
                if (parof[frd] == 0) swap(frd, me);
                // add new rectangle
                E.pb({L[frd], L[me], R[me], 1});
                E.pb({R[frd]+1, L[me], R[me], -1});
            }
        }
    }
    sort(ALL(E), [&](ev a, ev b){return a.y < b.y;});
    ll prevy = 0;
    ll re = 0;
    for (ev e : E) {
        bug(e.y, prevy, s[1]);
        re += (e.y-prevy) * (s[1]);
        MO(e.l,e.r,e.val);
        bug(e.l,e.r,e.val);
        prevy = e.y;
    }
    bug(s[1]);
    cout<<re<<endl;
}