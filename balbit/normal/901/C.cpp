#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;

int par[maxn];
int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

ll s[maxn * 4], tg[maxn*4];
int gpar[maxn], pare[maxn];
vector<pii> g[maxn];

int n,m;

void push(int o, int l, int r) {
    if (tg[o] == 0) return;
    s[o] += tg[o] * (r-l+1);
    if (l != r) {
        tg[o*2] += tg[o];
        tg[o*2+1] += tg[o];
    }
    tg[o] = 0;
}

void MO(int L, int R, int o = 1, int l = 0, int r = n-1) {
    push(o,l,r);
    if (l > R || r<L) return;
    if (l>=L && r<=R) {
        tg[o] += 1;
//        bug("added",o,l,r);
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,o*2,l,mid);
    MO(L,R,o*2+1,mid+1,r);
    s[o] = s[o*2] + s[o*2+1];
}

ll QU(int L, int R, int o = 1, int l = 0, int r = n-1) {
    push(o,l,r);
    if (l > R || r<L) return 0;
    if (l>=L && r<=R) {
//        bug(o,l,r,s[o]);
        return s[o];
    }
    int mid = (l+r)/2;
    return QU(L,R,o*2,l,mid) + QU(L,R,o*2+1,mid+1,r);
}
bool seen[maxn];
bool done[maxn*2];
vector<int> col[maxn];
int C = 1;
void dfs(int v, int p=-1) {
    bug(v);
    gpar[v] = p;
    seen[v] = 1;
    for (pii ele : g[v]) {
        int u = ele.f;
        if (!done[ele.s]) {
            done[ele.s] = 1;
            if (!seen[u]) {
                pare[u] = ele.s;
                dfs(u,v);
            }else{
//                if (col[ele.s] != 0) continue;
                col[u] . pb (C);
                for (int x = v; x != u; x = gpar[x]) {
                    col[x] .pb (C);
                }
                C++;
            }
        }
    }
}

struct Q{
    int f, s, id;
};

int tot[maxn*2], nof[maxn*2];

signed main(){
    IOS();
    cin>>n>>m;
    for (int i = 0; i<m; i++) par[i] = i;
    vector<Q> que;
    vector<pii> ed;
    for (int i = 0; i<m; i++) {
        int a,b; cin>>a>>b; --a; --b;
        ed.pb({a,b});
        g[a].pb({b,i});
        g[b].pb({a,i});
    }
    bug("GOGOGO");
    for (int i = 0; i<n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i<n; i++) {
//        bug(i, col[i]);
        for (int x : col[i]) tot[x] ++;
    }
    int q; cin>>q;
    for (int i = 0; i<q; i++) {
        int l,r; cin>>l>>r; --l; --r;
        que.pb({l,r,i});
    }
    sort(ALL(que), [&](Q a, Q b) {return a.s < b.s;});
    int L = 0, R = -1; // The ones that are here
    vector<ll> ans(q);

    for (int i = 0; i<q; i++) {
        int r = que[i].s;
        while (R < r) {
            ++R;
            int nbad = 0;
            for (int x : col[R]) {
                nof[x]++;
                if(nof[x] == tot[x]) nbad++;
            }
//            int a = ed[R].f, b = ed[R].s;
            while (nbad) {
                for (int x : col[L]) {
                    if (nof[x] == tot[x]) nbad--;
                    nof[x] --;
                }
                ++L;
            }
            bug(L,R);
            MO(L,R);
        }
        ans[que[i].id] = QU(que[i].f, r);
//        bug(que[i].id, que[i].f, r, QU(que[i].f,r));
    }
    for (int i = 0; i<q; i++) {
        cout<<ans[i]<<endl;
    }
}