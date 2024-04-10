#include <bits/stdc++.h>
//#define int ll
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


struct pt{
    int x,y,c;
};

vector<int> xpos, ypos;

ll get(vector<pt> v, int top, int dl, int dr) {
    sort(ALL(v), [&](pt a, pt b) {return (a.x!=b.x)? (a.x < b.x) : ((a.c==dl)<(b.c==dl));});
    vector<pt> vy=v;
    sort(ALL(vy), [&](pt a, pt b) {return (a.y!=b.y)? (a.y < b.y) : ((a.c==dl)<(b.c==dl));});

    auto get = [&] (int Y, vector<pt> &VV){
        // answer for horizontal cut, for points strictly less than Y
        int numr = 0;
        for (pt p : VV) {
            if (p.y < Y) {
                // ok, consider
                if (p.c == dr) ++numr;
            }
        }
        int numl = 0;
        int re = 0;
        for (pt p : VV) {
            if (p.y < Y) {
                // ok, consider
                if (p.c == dr) --numr;
                if (p.c == dl) ++numl;
                MX(re, min(numr, numl));
            }
        }
        return re;
    };

    // binary search on position of ypos
    assert(SZ(vy)!=0);
    int l = vy[0].y, r = vy.back().y;
    bug(l,r);
    int ret = 0;


    while (l!=r) {
        int mid = (l+r)/2 - (((l+r)%2) && ((l+r)<0));
        int topans = max(get(mid, v), get(mid, vy));
        int tt = 0;
        for (pt p : v) {
            if (p.y >= mid) {
                if (p.c == top) ++ tt;
            }
        }
        MX(ret, min(tt, topans));
        if (tt >= topans) {
            // increasing mid would be good
            // increasing mid would decrease tt
            l = mid+1;
        }else{
            r = mid;
        }
    }

    {
        int topans = max(get(l, v), get(l, vy));
        int tt = 0;
        for (pt p : v) {
            if (p.y >= l) {
                if (p.c == top) ++ tt;
            }
        }
        MX(ret, min(tt, topans));
    }

    return ret;
}

int gocut(vector<pt> & v) {
    vector<int> hm = {1,2,3};
    int re = 0;
    do{
        MX(re, get(v, hm[0], hm[1], hm[2]));
    } while (next_permutation(ALL(hm)));
    return re;
}



signed main(){
    IOS();
    int n; cin>>n;
    vector<pt> v;


    REP(i,n) {
        int x,y,c; cin>>x>>y>>c;
        v.pb({x,y,c}); xpos.pb(x); ypos.pb(y);
    }

    SORT_UNIQUE(xpos);
    SORT_UNIQUE(ypos);

    REP(i,n) {
        v[i].x = lower_bound(ALL(xpos), v[i].x) - xpos.begin();
        v[i].y = lower_bound(ALL(ypos), v[i].y) - ypos.begin();
    }

    int re = 0;

    REP(r, 4) {
        MX(re, gocut(v));
        for (pt &p : v) {
            int nx = -p.y; int ny = p.x;
            p.x = nx; p.y = ny;
        }
    }

    cout<<re*3<<endl;

//    int g1 = yar(v);
//    REP(i,n) swap(v[i].x, v[i].y);
//    int g2 = yar(v);
//    cout<<max(g1, g2)*3<<endl;




}