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

struct pt{
    ll x,y;
    pt operator - (pt o) {
        return {x-o.x, y-o.y};
    }
    pt operator - (const pt o) const {
        return {x-o.x, y-o.y};
    }
    ll operator ^ (pt o) {
        return x * o.y - y * o.x;
    }
    bool operator < (const pt &o) const{
        return x != o.x? x < o.x : y < o.y;
    }
    bool operator != (const pt &o) const{
        return x != o.x||y != o.y;
    }
};

struct hull : set<pt> {
    bool ontop(pt p){
        auto it = lower_bound(p);
        if (it == end()) return 0;
        if (it == begin()) return !(p < *begin());
        return ((*it-p) ^ (*prev(it)-p))<=0;
    }
    void ins(pt p) {
        if (ontop(p)) return;
        auto x = insert(p).f;
        while (x!=begin() && prev(x) != begin()) {
            auto y = prev(x);
            auto z = prev(y);
            if (((*x - *y) ^ (*z - *y)) <= 0) {
                x=(erase(y));
            }else break;
        }
        while (next(x)!=end() && next(next(x)) != end()) {
            auto y = next(x); auto z = next(y);
            if (((*z-*y) ^ (*x-*y)) <= 0) {
                x=prev(erase(y));
            }else break;
        }
    }
    void dump(){
        bug("yo");
        for (auto it = begin(); it != end(); ++it) {
            cout<<(it->x)<<' '<<(it->y)<<endl;
        }
    }
};

signed main(){
    IOS();

    int qq; cin>>qq;

    hull pos, neg;


    while (qq--) {
        int t,x,y; cin>>t>>x>>y;
//        x = x * 2000005 + y;

        pt P = {x,y}, N = {-x,-y};
        if (t == 1) {
            pos.ins(P); neg.ins(N);
        }else{
            bool hp = pos.ontop(P), hn = neg.ontop(N);
            bug(hp, hn);
            if (hp&&hn) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

//        pos.dump();
//        neg.dump();
    }

}