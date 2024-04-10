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

int fa[18][maxn];
int dep[maxn];

int lca(int u,int v){
  if(dep[u] < dep[v])swap(u,v);
  for(int i=18-1;i>=0;i--){
    if(dep[fa[i][u]] >= dep[v]) u = fa[i][u];
  }
  if(u==v)return u;

  for(int i=18-1;i>=0;i--){
    if(fa[i][u] != fa[i][v]) {
      u = fa[i][u];
      v = fa[i][v];
    }
  }

  return fa[0][u];
}
int node[maxn], permu[maxn];
int n;

int anc(int x, int k) {
    if (k < 0) return -1;
    for (int i = 0; i<18; ++i) {
        if (k & (1<<i)) x = fa[i][x];
    }
    return x;
}

inline bool in(int A, bool B, int C, int p) {
    if (dep[p] < dep[C]) return 0;
    if (B || anc(A, dep[A] - dep[p]) == p) return 1;
    return 0;
}

pii MRGE(pii p1, pii p2) {
    if (p1.f == -1 || p2.f == -1) return {-1, -1};
    if (dep[p1.s] > dep[p2.s] ) {
        swap(p1, p2);
    }
    int E = p2.s;
    vector<int> tmp = {p1.f, p1.s, p2.f};
    vector<int> lft;
    array<bool, 3> rr;
    REP(i,3) {
        rr[i] = anc(E,dep[E]-dep[tmp[i]]) == tmp[i];
        if (!rr[i]) {
            lft.pb(tmp[i]);
        }
    }
//    bug(SZ(lft));
    if (SZ(lft) == 0) {
        sort(ALL(tmp), [&](int a, int b) {return make_pair(dep[a],a) > make_pair(dep[b],b);});
        return {tmp.back(), E};
//        lft.pb(tmp.back());
    }
    sort(ALL(lft), [&](int a, int b) {return make_pair(dep[a],a) > make_pair(dep[b],b);});
    REP(i,1) {
        bool ok = 1;
        int C = lca(E, lft[i]);
        REP(j,3) {
            if (lft[i] != tmp[j]) {
                if (!in(lft[i], rr[j], C, tmp[j])) {
                    ok = 0; break;
                }
            }
        }
        if (ok) {
            return {lft[i], E};
        }
    }
    return {-1,-1};
}

pii s[maxn*4];

void build(int o=1,int l=0,int r=maxn-1) {
    if (l == r) {
        if (l < n) {
            s[o] = {node[l], node[l]};
        }else s[o] = {-1,-1};
        return;
    }
    int mid = l+r>>1;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
    s[o] = MRGE(s[o*2], s[o*2+1]);
//    if (s[o].f != -1) {
//        bug(l,r,s[o].f, s[o].s);
//    }
}

bool MO(int p, int v, int o=1, int l=0, int r=maxn-1) {
    if (l > p || r < p) return 0;
    if (l == r) {
        s[o] = {v,v}; return 1;
    }
    int mid = l+r>>1;
    bool chg = MO(p,v,o*2,l,mid) || MO(p,v,o*2+1,mid+1,r);
    if (chg) {
        pii old = s[o];
        s[o] = MRGE(s[o*2], s[o*2+1]);
        if (s[o] != old) return 1;
    }
    return 0;
}

signed main(){
    IOS();
    cin>>n;
    REP(i,n) {
        cin>>permu[i]; node[permu[i]] = i;
    }
    for (int i = 1; i<n; ++i) {
        int p; cin>>p; --p;
        dep[i] = dep[p] + 1;
        fa[0][i] = p;
    }
    for (int i = 1; i<18; ++i) {
        REP(j,n) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
    build();
    int q; cin>>q;
    while (q--) {
        int TP; cin>>TP;
        if (TP == 2) {
            int re = 0;
            pii now = {node[0], node[0]};
            int o=1,l=0,r=maxn-1;
            while (l!=r) {
                pii ty = MRGE(now, s[o*2]);
//                bug(ty.f, ty.s);
                int mid = l+r>>1;
                if (ty.f != -1) {
                    now = ty; l = mid+1; o = o*2+1;
                }else{
                    r = mid; o = o*2;
                }
            }
            cout<<r<<endl;
        }else{
            int a,b; cin>>a>>b; --a; --b;
            int A = permu[a], B = permu[b];
            MO(A,b);
            MO(B,a);
            swap(node[A], node[B]);
            swap(permu[a], permu[b]);
        }
    }


}