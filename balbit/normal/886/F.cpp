#include <bits/stdc++.h>
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

const int maxn = 1e5+5;

struct pt{
    ll x, y;
    pt operator + (pt & b) {return {x+b.x, y+b.y};}
    bool operator < (const pt & b) const {return x!=b.x?x<b.x:y<b.y;}
    bool operator != (const pt & b) const {return x!=b.x||y!=b.y;}
};

#define L __int128
//map<pt, int> mp;
bool in[maxn];

signed main(){
    IOS();
    ll n; cin>>n;
    vector<pt> v;
    ll cx = 0, cy = 0;
    REP(i,n) {
        ll x,y; cin>>x>>y; cx += x; cy += y; x*=n; y*=n;
        v.pb({x,y});
    }
    bug(cx, cy);
    REP(i,n) {
        v[i].x -= cx; v[i].y -= cy;
        bug(v[i].x, v[i].y);
    }
//    vector<pt> stuff;
    fill(in, in+n+1, 1);
    REP(i,n) {
        if (in[i])
            REP(j,n) {
                if (in[j] && v[i].x == -v[j].x && v[i].y == -v[j].y) {
                    in[i] = in[j] = 0; break;
                }
            }
    }
    vector<pt> nv;
    REP(i,n) {
        if (in[i]) nv.pb(v[i]);
    }
    bug(SZ(v));
    v.swap(nv);
    if (SZ(v) == 0) {
        cout<<-1<<endl; return 0;
    }
    n = SZ(v);
    vector<pt> mp;
    REP(i,n) {
        vector<pt> have;
        REP(j,n) {
            ll nx = v[i].x + v[j].x;
            ll ny = v[i].y + v[j].y;
            ll g = __gcd(abs(nx), abs(ny));
            nx /= g; ny /= g;
            if (nx < 0 || (nx == 0 && ny < 0)) {
                nx = -nx; ny = -ny;
            }
            pt pp = pt{nx,ny};
            have.pb(pp);
        }
        sort(ALL(have));
        REP(j,n) {
            if (j==0 || have[j] != have[j-1]) {
                mp.pb(have[j]);
            }
        }
    }
    bug(n);
    int re =0;
    sort(ALL(mp));
    vector<pt> tat;
    bug(SZ(mp));
    for (int i = 0; i<=SZ(mp); ++i) {
        if (i == SZ(mp) || (i>0 && mp[i] != mp[i-1])) {
            pt P = mp[i-1];
            if (SZ(tat) >= n) {
                bug(P.x, P.y);
                vector<pt> tmp = v;
                sort(ALL(tmp), [&](pt a, pt b) {return a.x*(L)P.y-a.y*(L)P.x < b.x*(L)P.y-b.y*(L)P.x;});
                bool ok = 1;
                REP(j, SZ(tmp)/2+1) {
                    pt hi = tmp[j] + tmp[SZ(tmp)-1-j];
                    bug(hi.x, hi.y, tmp[j].x, tmp[j].y);
                    if (hi.x * (L)P.y - hi.y * (L)P.x != 0) {
                        ok = 0; break;
                    }
                }
                bug(SZ(tmp), P.x, P.y, ok);
                re += ok;
            }
            tat.clear();
        }
        if (i < SZ(mp)) {
            tat.pb(mp[i]);
        }
    }

    cout<<re<<endl;
}