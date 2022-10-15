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

const int maxn = 1e5+5;

priority_queue<pii, vector<pii>, greater<pii> > here[maxn]; // for each leaf, stores {height, weight}
ll mn[maxn*4]; // seg tree

int h,w,n;

void build(int o=1, int l=0, int r=maxn-1) {
    if (l == r) {
        if (l < w) {
            here[l].push({h+1, 1});
        }
        mn[o] = (SZ(here[l]) ? (here[l].top().f) : inf);
        return;
    }
    int mid = (l+r)/2;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
    mn[o] = min(mn[o*2], mn[o*2+1]);
}

ll bgsz = 0;
void ADD(int p, pii val, int o=1, int l=0, int r=maxn-1) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        here[l].push(val);
        mn[o] = here[l].top().f; // i know there's something
        return;
    }
    int mid = (l+r)/2;
    ADD(p,val, o*2,l,mid); ADD(p,val,o*2+1,mid+1,r);
    mn[o] = min(mn[o*2], mn[o*2+1]);
}

bool KILL (int L, int R, int H, int o=1, int l=0, int r=maxn-1) { // kill something with height <= H
    if (l > R || r < L || mn[o] > H) return 0;
    int mid = (l+r)/2;
    if (l == r) {
        assert(here[l].top().f == mn[o]);
        bgsz += here[l].top().s;
        here[l].pop();
        mn[o] = (SZ(here[l]) ? (here[l].top().f) : inf);
        return 1;
    }
    if (l >= L && r <= R) {
        // definitely will find
        bool bat = 0;
        if (mn[o*2] <= H) {
            // it's in the left
            bat = KILL(L,R,H,o*2,l,mid);
        }else{
            bat = KILL(L,R,H,o*2+1,mid+1,r);
        }
        assert(bat);
        mn[o] = min(mn[o*2], mn[o*2+1]);
        return 1;
    }
    bool tryleft = KILL(L,R,H,o*2,l,mid);
    if (tryleft) return 1;
    return KILL(L,R,H,o*2+1,mid+1,r);
}

struct barr{
    int u,l,r,s; // be careful of +1 -1 for s
};

signed main(){
    IOS();
    memset(mn, 0x3f, sizeof mn);
    cin>>h>>w>>n;
    build();
    vector<barr> ev(n+1);
    REP(i,n) {
        cin>>ev[i].u>>ev[i].l>>ev[i].r>>ev[i].s;
        --ev[i].l; --ev[i].r;
    }
    ev.back().u = 0; ev.back().l=0; ev.back().r=w-1; ev.back().s=1e9+10;
    sort(ALL(ev), [&](barr a, barr b){return a.u > b.u;});
    for (barr B : ev) {
        bug(B.u, B.l, B.r);
        // kill everything <= height B.u + B.s;
        bgsz = 0;
        while (KILL(B.l, B.r, B.u+B.s)) {
            bug(bgsz);
        }
        bgsz %= mod;

        if (B.s == 1e9+10) {
            // the end
            bug("Yarr");
            cout<<bgsz<<endl; return 0;
        }

        ADD((B.l==0?B.r+1:B.l-1), make_pair(B.u, bgsz));
        ADD((B.r==w-1?B.l-1:B.r+1), make_pair(B.u, bgsz));
    }

}