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

struct line{
    ll m,b,id; // not actual id, but L[v]
    bool operator < (line &o) {
        return m!=o.m?m<o.m:b<o.b;
    }
};

struct maxhull{
    vector<line> L; // ok, taking the abs of the slope now i guess
    vector<line> og;
    bool sorted = 0;
    int at = 0;
    // mx +b
    ll div(ll a, ll b) {
        return a/b-((a%b) && ((a^b)<0));
    }
    ll con(line &a, line &b) {
        assert(a.m != b.m);
        return div(a.b-b.b, b.m-a.m);
    }
    void build(){
        at = 0;
        if (!sorted){
            sort(ALL(og));
            sorted = 1;
        }
        vector<line> cv;
        for (line p : og) {
            while (SZ(cv) && cv.back().m == p.m) {
                if (p.b > cv.back().b)
                    cv.pop_back();
                else {
                    goto nope;
                }
            }
            while (SZ(cv) >= 2 && con(p, cv[SZ(cv)-2]) <= con(cv.back(), cv[SZ(cv)-2])) {
                cv.pop_back();
            }
            cv.pb(p);
            nope:;
        }
        L = cv;
    }
    void MO(int l, int r, ll chg) {
        for (line &li : og) {
            if (li.id >= l && li.id <= r) {
                li.b += li.m * chg;
                bug(li.b, li.m);
            }
        }
        build();
    }
    ll QU(int l, int r, ll pt) {
        ll re = 0;
        for (line &li : og) {
            bug(li.m, li.b, li.id, l, r);
            if (li.id >= l && li.id <= r) {
                MX(re, li.m * pt + li.b);
                bug(li.m, li.b, pt);
            }
        }
        return re;
    }
    ll eval(line & p, ll x) {
        return p.m * x + p.b;
    }

    ll get(ll pt) {
        // pt should be increasing
        while (at+1 < SZ(L) && eval(L[at+1], pt) >= eval(L[at], pt)) ++at;
        return abs(eval(L[at], pt));
    }
};


vector<int> g[maxn];
int L[maxn],R[maxn];
ll siga[maxn], sigb[maxn];
int ora[maxn], orb[maxn];
int IT = 0;
void dfs(int v, int p) {
    L[v] = R[v] = IT++;
    siga[v] += ora[v];
    sigb[v] += orb[v];
    for (int u : g[v]) {
        if (u != p) {
            siga[u] += siga[v];
            sigb[u] += sigb[v];
            dfs(u,v);
            R[v] = R[u];
        }
    }
}

const int BS = 150;
maxhull up[maxn/BS+10], down[maxn/BS+10];
ll anow[maxn/BS+10];

void work(int l, int r, ll chg) {
    while (l <= r) {
        int to = min(r, -1 + l + BS - (l%BS));
        int blo = l/BS;
        bug(l, to);
        if (l%BS != 0 || (to % BS) != BS-1) {
            // special change
            up[blo].MO(l,r,chg);
            down[blo].MO(l,r,chg); // not sure if i need to reverse signs
        }else{
            anow[blo] += chg;
        }
        l = to+1;
    }
    assert (l == r+1);
}

ll get(int l, int r) {
    ll re = 0;
    bug(l,r);
    while (l <= r) {
        int to = min(r, -1 + l + BS - (l%BS));
        int blo = l/BS;
        if (l%BS != 0 || (to % BS) != BS-1) {
            bug("yo?");
            MX(re, up[blo].QU(l,r,anow[blo]));
            MX(re, down[blo].QU(l,r,anow[blo])); // no sign reversal (?)
        }else{

            MX(re, up[blo].get(anow[blo]));
            MX(re, down[blo].get(anow[blo]));
        }
        l = to+1;
    }
    return re;
}

signed main(){
    IOS();
    int n,q; cin>>n>>q;
    REP1(i,n-1) {
        int p; cin>>p; --p;
        g[p].pb(i);
    }
    REP(i,n) cin>>ora[i];
    REP(i,n) cin>>orb[i];
    dfs(0, -1);
    REP(i,n) {
        int j = L[i];
        up[j/BS].og.pb({sigb[i], siga[i]*sigb[i],j});
        down[j/BS].og.pb({-sigb[i], -siga[i]*sigb[i],j});
        bug(i, siga[i], sigb[i]);
    }
    REP(i,n/BS+2) {
        if (!up[i].sorted) {
            bug("build!");
            up[i].build(); down[i].build();
        }
    }
    while (q--) {
        int tp; cin>>tp;
        if (tp == 1) {
            int v,x; cin>>v>>x;
            --v;
            work(L[v], R[v], x);
            bug("updating", L[v], R[v]);
        }else{
            int v; cin>>v; --v;
            cout<<get(L[v], R[v])<<endl;
        }
    }


}