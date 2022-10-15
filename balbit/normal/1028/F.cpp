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

struct pt{
    ll x,y;
    bool operator < (const pt & oth) const {
        return tie(x,y)<tie(oth.x,oth.y);
    }
    bool operator == (const pt & oth) const {
        return tie(x,y)==tie(oth.x,oth.y);
    }
};

pt reduce(pt P) {
    ll x = P.x, y = P.y;
    ll g = __gcd(abs(x), abs(y));
    x /= g; y/=g;
    if (y < 0) y = -y, x = -x;
    if (y == 0 && x < 0) x = -x;
    return pt{x,y};
}

map<ll, vector<pt> > mp;
map<pt, ll> cnt;

inline void go(pt a, pt b, ll fac) { // fac is 1 or -1
    pt c = reduce(pt({a.x+b.x,a.y+b.y}));
    cnt[c] += fac;
}



signed main(){
    IOS();
    int q; cin>>q;
    int tot = 0;
    while (q--) {
        int TP; cin>>TP;
        pt p; cin>>p.x>>p.y;
        ll D = p.x * p.x + p.y * p.y;
        if (TP == 1) ++tot;
        if (TP == 2) --tot;
        if (TP == 1 || TP == 2) {
            if (TP == 1) mp[D].pb(p);
            for(pt & o : mp[D]) {
                go(p,o,(TP==1?1:-1) * (o==p?1:2));
            }
            if (TP == 2) mp[D].erase(find(ALL(mp[D]), p));
        }
        if (TP == 3) {
            cout<<tot-cnt[reduce(p)]<<endl;
        }
    }
}