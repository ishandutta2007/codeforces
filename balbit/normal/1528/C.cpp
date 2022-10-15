#include <bits/stdc++.h>
#undef BALBIT
using namespace std;
#define ll long long
#define y1 zck_is_king
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

const int maxn = 3e5+5;

vector<int> g1[maxn], g2[maxn];
int s[maxn*4];

//int n;
void MO(int L, int R, ll v, int o=1, int l=0, int r=maxn-1) {
    if (l>R || r<L) {
        return;
    }
    if (l >= L && r <= R) {
        s[o] = v;
        bug("hey");
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
}

ll QU(int p, int o=1, int l=0, int r=maxn-1) {
    if (l>p || r<p) return -1;
    if (s[o] != -1 || l == r) return s[o];
    int mid = (l+r)/2;
    return max(QU(p,o*2,l,mid), QU(p,o*2+1,mid+1,r));
}

int L[maxn], R[maxn];
int IT = 0;
void dfs2(int v, int p) {
    L[v] = R[v] = IT++;
    for (int u : g2[v]) {
        if (u != p) {
            dfs2(u,v);
            R[v] = R[u];
        }
    }
}

int who[maxn];
int cnt= 0, re = 0;

void dfs1(int v, int p) {
    who[v] = QU(L[v]);
    if (who[v] != -1) {
        MO(L[who[v]], R[who[v]], -1);
        --cnt;
    }
    ++cnt;
    bug(cnt, v, who[v], L[v], R[v]);
    MX(re, cnt);
    MO(L[v], R[v], v);
    for (int u : g1[v]) {
        if (u!=p) {
            dfs1(u,v);
        }
    }
    --cnt;
    MO(L[v], R[v], -1);
    if (who[v] != -1) {
        ++cnt;
        MO(L[who[v]], R[who[v]], who[v]);
    }
}

signed main(){
    IOS();
    memset(who, -1, sizeof who);
    memset(s, -1, sizeof s);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
            IT = re = cnt = 0;
        REP(i,n) {
            g1[i].clear();
            g2[i].clear();
        }
        REP1(i,n-1) {
            int p; cin>>p; g1[p-1].pb(i);
        }
        REP1(i,n-1) {
            int p; cin>>p; g2[p-1].pb(i);
        }
        dfs2(0,-1);
        bug(L[0], R[0]);
        dfs1(0,-1);
        cout<<re<<endl;
    }

}