#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

ll seg[4 * (200005)];
//Simple Segment Tree
void modify(int o, int l, int r, int p, int val){
    if (l>p||r<p) return;
    if (l==r) {
        seg[o]+=val;
        return;
    }
    int mid=(l+r)/2;
    modify(o*2+1, l, mid, p, val);
    modify(o*2+2, mid+1, r, p, val);
    seg[o]=seg[o*2+1]+seg[o*2+2];
}

ll query(int o, int l, int r, int L, int R){
    if (l>R||r<L) return 0;
    if (l>=L&&r<=R) return seg[o];
    int mid=(l+r)/2;
    ll ql=query(o*2+1, l, mid, L, R);
    ll qr=query(o*2+2, mid+1, r, L, R);
    return ql+qr;
}

map<int, int> mp;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    map<int, vector<pii> > vert, hor;
    REP(i,n){
        int x0,y0,x1,y1; cin>>x0>>y0>>x1>>y1;
        if (x0>x1) swap(x0,x1);
        if (y0>y1) swap(y0,y1);
        if (x0==x1){//Vertical
            vert[x0].pb({y0,y1});
        }else{
            hor[y0].pb({x0,x1});
        }
    }
    vector<int> vecy, vecx;
    ll re = 0;
    vector<pair<int, pair<int, pii> > > event; // first: y position, query or modify, xpos1, xpos2
    for (auto &x : vert){
        vector<pii> &pp = x.s;
        sort(ALL(pp), [](pii a, pii b){if (a.f!=b.f) return a.f<b.f; return a.s>b.s;});
        ll lb=0, rb=-1e9-10;
        vector<pii> nw;
        REP(i,SZ(pp)){
            if (pp[i].f>rb+1){
                if (rb!=-1e9-10) nw.pb({lb,rb}), re += (rb-lb+1);
                lb = pp[i].f; rb = pp[i].s;
            }else{
                MXTO(rb, pp[i].s);
            }
        }
        if (rb!=-1e9-10) nw.pb({lb,rb}), re += (rb-lb+1);
        for (auto y : nw){
            event.pb({y.f,{-1,{x.f,x.f}}}); // Add
            event.pb({y.s+1,{-3,{x.f,x.f}}}); // Subtract
            // vecy.pb(y.f); vecy.pb(y.s+1);
            vecx.pb(x.f);
        }
    }
    for (auto &x : hor){
        vector<pii> &pp = x.s;
        sort(ALL(pp), [](pii a, pii b){if (a.f!=b.f) return a.f<b.f; return a.s>b.s;});
        ll lb=0, rb=-1e9-10;
        vector<pii> nw;
        REP(i,SZ(pp)){
            if (pp[i].f>rb+1){
                if (rb!=-1e9-10) nw.pb({lb,rb}), re += (rb-lb+1);
                lb = pp[i].f; rb = pp[i].s;
            }else{
                MXTO(rb, pp[i].s);
            }
        }
        if (rb!=-1e9-10) nw.pb({lb,rb}), re += (rb-lb+1);
        for (auto y:nw){
            event.pb({x.f, {0,{y.f,y.s}}});
            vecx.pb(y.f); vecx.pb(y.s);
            // vecy.pb(x.f);
        }
        x.s = nw;
    }
    SORT_UNIQUE(vecx);
    REP(i,SZ(vecx)){
        mp[vecx[i]]=i;
    }
    sort(ALL(event));
    // debug(re);
    for (auto & x : event){
        if (x.s.f==0){
            re-= query(0,0,SZ(vecx),mp[x.s.s.f],mp[x.s.s.s]);
        }else{
            x.s.f+=2;
            modify(0,0,SZ(vecx),mp[x.s.s.f],x.s.f);
        }
    }
    cout<<re<<'\n';
    
}