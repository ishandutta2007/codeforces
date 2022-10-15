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

int zisk[2 * maxn];

void build() {
  for (int i = maxn - 1; i > 0; --i) zisk[i] = max(zisk[i<<1] , zisk[i<<1|1]);
}

void modify(int p, int value) {
    for (zisk[p += maxn] = value; p > 1; p >>= 1) zisk[p>>1] = max(zisk[p] , zisk[p^1]);
}

int query(int l, int r) { // zuo bee you kai
    int res = 0;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, zisk[l++]);
        if (r&1) res = max(res, zisk[--r]);
    }
    return res;
}

int where[maxn]; // 0-based
int a[maxn];

int rb[maxn];

struct upd{
    int l,r;
    int m,b; // mx+b
};

vector<pii> here[maxn];
int leftbig[maxn], rightbig[maxn];

vector<upd> gogo[maxn];

pii tg[maxn*4], s[maxn*4];

void operator += (pii &a, pii b) {
    a.f += b.f; a.s += b.s;
}

void push(int o, int l, int r){
    if (tg[o].f || tg[o].s) {
        s[o].f += tg[o].f * (ll)(r-l+1);
        s[o].s += tg[o].s * (ll)(r-l+1);
        if (l!=r) {
            tg[o*2] += tg[o];
            tg[o*2+1] += tg[o];
        }
        tg[o] = {0,0};
    }
}
void MO(int L, int R, pii v, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l>R || r<L) return;
    if (l >= L && r <= R) {
        tg[o] += v;
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
    s[o] = s[o*2]; s[o] += s[o*2+1];
}

pii QU(int L, int R, int o=1, int l=0, int r=maxn-1) {
    push(o,l,r);
    if (l>R || r<L) return {0,0};
    if (l>=L && r<=R) {
        return s[o];
    }
    int mid = (l+r)/2;
    pii ra = QU(L,R,o*2,l,mid);
    ra += QU(L,R,o*2+1,mid+1,r);
    return ra;
}

vector<pii> ask[maxn];

signed main(){
    IOS();


    int n,q; cin>>n>>q;

    REP(i,n) {
        cin>>a[i];
        where[a[i]] = i;
        modify(i, a[i]);
    }

    vector<pii> seg;

    REP1(i,n) {
        for (int j = i+1; j*(ll)i <= n; ++j) {
            int a = where[i], b = where[j];
            int c = where[i*j];
            int L = min({a,b,c}), R = max({a,b,c});
            int qq = query(L,R+1);
            if (qq == i*j) {
                bug(a,b);
                here[c].pb({L,R});
            }
        }
    }

    vector<int> stk;

    REP(i,n) {
        while (!stk.empty() && a[i] > a[stk.back()]) stk.pop_back();
        leftbig[i] = stk.empty() ? -1 : stk.back();
        stk.pb(i);
    }

    stk.clear();

    RREP(i,n) {
        while (!stk.empty() && a[i] > a[stk.back()]) stk.pop_back();
        rightbig[i] = stk.empty() ? n + 1: stk.back();
        stk.pb(i);
        bug(i, leftbig[i], rightbig[i]);
    }

    REP(i,n) {
        sort(ALL(here[i]), [&](pii a, pii b){return a.s != b.s? a.s < b.s : a.f > b.f;});
        vector<pii> nw;
        for (pii p : here[i]) {
            if (SZ(nw) == 0 || p.f > nw.back().f) {
                bug(i, p.f, p.s);
                if (SZ(nw)) {
                    int l = nw.back().f, r = nw.back().s;
                    gogo[p.s].pb({leftbig[i]+1, l, -1, (p.s -1)});
                }
                nw.pb(p);
                int l = p.f, r = p.s;
                gogo[r].pb({leftbig[i]+1, l, 1, -r + 1});
            }
        }
        if (SZ(nw)) {
            int l = nw.back().f, r = nw.back().s;
            gogo[rightbig[i]].pb({leftbig[i]+1, l, -1, (rightbig[i] -1)});
        }
    }

    REP(ss, q) {
        int l,r; cin>>l>>r;
        --l; --r;
        ask[r].pb({l,ss});
    }

    vector<int> ans(q);

    REP(i, n) {
        bug(i);
        for (auto &u : gogo[i]) {
            bug(u.l, u.r, u.m, u.b);
            MO(u.l, u.r, {u.m, u.b});
        }
        for (pii p : ask[i]) {
            pii get = QU(p.f, i);
            bug(p.f, p.s, get.f, get.s);
            ans[p.s] = get.f * i + get.s;
        }
    }

    REP(i,q) {
        cout<<ans[i]<<endl;
    }

}