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

const int maxn = 1e5+5;

ll sx[maxn*4], sy[maxn*4], s[maxn*4], tx[maxn*4], ty[maxn*4];
int ok[maxn*4];

void push(int o, int l, int r) {
    if (tx[o]) {
        tx[o] %= mod;
        s[o] += tx[o] * sy[o];
        sx[o] += tx[o] * (ll)(ok[o]);
        if (l != r) tx[o*2] += tx[o], tx[o*2+1] += tx[o];
        tx[o] = 0;
        s[o] %= mod; sx[o] %= mod;
    }
    if (ty[o]) {
        ty[o] %= mod;
        s[o] += ty[o] * sx[o];
        sy[o] += ty[o] * (ll)(ok[o]);
        if (l != r) ty[o*2] += ty[o], ty[o*2+1] += ty[o];
        ty[o] = 0;
        s[o] %= mod; sy[o] %= mod;
    }
}

inline void add(ll &a, ll b, ll c){
    a = (b+c >= mod?b+c-mod:b+c);
}

void pull(int o) {
    add(sx[o] , sx[o*2] , sx[o*2+1]);
    add(sy[o] , sy[o*2] , sy[o*2+1]);
    add(s[o] , s[o*2] , s[o*2+1]);
    add(ok[o] , ok[o*2] , ok[o*2+1]);
}

void MO(int L, int R, int xd, int yd, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tx[o] += xd; ty[o] += yd; push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,xd,yd,o*2,l,mid);
    MO(L,R,xd,yd,o*2+1,1+mid, r);
    pull(o);
}

void MO0(int L, int R, ll xd, ll yd, bool okadd, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        sx[o] = xd; sy[o] = yd; s[o] = xd * yd % mod; ok[o] = okadd;
        return;
    }
    int mid = (l+r)/2;
    MO0(L,R,xd,yd,okadd,o*2,l,mid);
    MO0(L,R,xd,yd,okadd,o*2+1,1+mid, r);
    pull(o);
}

int a[maxn];
int lcnt[maxn], rcnt[maxn];

struct BIT{
    ll s[maxn];

    ll QU(int e) {
        ll re = 0;
        for (++e; e>0; e-=e&-e) add(re,re,s[e]);
        return re;
    }

    void MO(int e, int v) {
        for (++e; e<maxn; e+=e&-e) add(s[e],s[e], v);
    }

    void MO(int l, int r, ll v) {
        v %= mod; if (v < 0) v += mod;
        MO(l, v); MO(r+1,mod-v);
    }

    BIT(){memset(s, 0, sizeof s);}

};



int segl[maxn], segr[maxn];
int tp[maxn];
int on[maxn];

BIT xbit, ybit;

void tog(int x) {
    xbit.MO(tp[x]+1, segr[a[x]], on[x] * lcnt[x]);
    ybit.MO(segl[a[x]], tp[x]-1, on[x] * rcnt[x]);

    if (on[x] == 1) {
        ll xnow =xbit.QU(tp[x]), ynow = ybit.QU(tp[x]);
        MO0(tp[x],tp[x],xnow,ynow, 1);
        bug(xnow, ynow);
        bug("ado");
    }else{
        MO0(tp[x],tp[x],0,0, 0);
    }

    MO(tp[x]+1, segr[a[x]], (mod+on[x] * lcnt[x])%mod, 0);
    MO(segl[a[x]], tp[x]-1, 0, (mod + on[x] * rcnt[x])%mod);


    on[x] = -on[x];
}

signed main(){
    IOS();
    int n; cin>>n;
    vector<int> hi;
    REP(i,n) {
        cin>>a[i]; hi.pb(a[i]);
    }
    sort(ALL(hi));
    hi.resize(unique(ALL(hi)) - hi.begin());
    BIT invbit;
    REP(i,n) {
        a[i] = lower_bound(ALL(hi), a[i]) - hi.begin();
        lcnt[i]=invbit.QU(a[i]);
        invbit.MO(a[i], 1);
    }
    memset(invbit.s, 0, sizeof invbit.s);
    vector<pii> rep; // a[i], i
    memset(segl, 0x3f, sizeof segl);
    RREP(i,n) {
        rcnt[i] = invbit.QU(a[i]);
        invbit.MO(a[i], 1);
        rep.pb({a[i], i});
    }
    sort(ALL(rep));
    REP(i,n) {
        MN(segl[rep[i].f], i);
        MX(segr[rep[i].f], i);
        tp[rep[i].s] = i;
        bug(i, lcnt[i], rcnt[i]);
    }
    bug(segl[0], segr[0]);
    fill(on, on+maxn, 1);
    REP(i,n) tog(i);
    bug(s[1]);

    int q; cin>>q;
    while (q--) {
        int foo, x; cin>>foo>>x; --x;
        tog(x);
        cout<<(mod+s[1]%mod)%mod<<endl;
        bug(ok[1]);
    }


}