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

const int iinf = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

int cnt[maxn][2];

struct state{
    int a[2][2];
    state(){
        memset(a, 0x3f, sizeof a);
    }
    void setpt(int p) {
        REP(frm, 2) {
            if (cnt[p][frm^1]) {
                a[frm][0] = a[frm][1] = 1;
            }else{
                a[frm][frm] = 0; a[frm][frm^1] = inf;
            }
        }
    }
};

state mrg(state a, state b) {
    state re;
    REP(st, 2) {
        REP(md, 2) {
            REP(fn, 2) {
                MN(re.a[st][fn], a.a[st][md] + b.a[md][fn]);
            }
        }
    }
    return re;
}

state s[maxn*4];

void build(int o, int l, int r) {
    if (l == r) {
        s[o].setpt(l);
        return;
    }
    int mid = (l+r)/2;
    build(o*2,l,mid); build(o*2+1, mid+1,r);
    s[o] = mrg(s[o*2+1], s[o*2]);
}

void MO(int p, int ar, int df, int o,int l, int r) {
    if (l > p || r < p) return;
    if (l == r) {
        cnt[p][ar] += df;
        s[o].setpt(l);
        return;
    }
    int mid = (l+r)/2;
    MO(p,ar,df,o*2,l,mid); MO(p,ar,df,o*2+1,mid+1,r);
    s[o] = mrg(s[o*2+1], s[o*2]);
}

state NOPE;

state QU(int L, int R, int o, int l, int r) {
    if (l > R || r < L) return NOPE;
    if (l >= L && r <= R) {
        return s[o];
    }
    int mid = (l+r)/2;
    state gl = QU(L,R,o*2,l,mid), gr = QU(L,R,o*2+1,mid+1,r);
    return mrg(gr, gl);
}

signed main(){
    IOS();
    NOPE.a[0][0] = NOPE.a[1][1] = 0;
    int n; cin>>n;
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i];
        if (a[i]) ++cnt[a[i]][1];
    }

    build(1,0,n+1);

    ll re = 0;

    REP(i,n) {
        if (a[i]) MO(a[i], 1, -1, 1, 0, n+1);
        if (i && a[i-1]) MO(a[i-1], 0, 1, 1, 0, n+1);
        if (a[i] == 0) continue;
        state yum = QU(0, a[i]-1, 1, 0, n+1);
        int tmp = inf;
        REP(x,2) REP(y,2) {
            MN(tmp, yum.a[x][y]);
        }
        bug(i, tmp);
        re += tmp+1;
    }

    cout<<re<<endl;

}