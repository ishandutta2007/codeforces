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

ll P;

struct seg{
    int l,r;
    int c,a;
    int befthis; int befval;
    seg(int L, int R): l(L), r(R) {
        c=a=befthis=befval=-1;
    }

    int gt(int x) {
        if (x < befthis) return befval;
        assert(c!=-1 || a != -1);
        return c + (x-a)/P - ((x-a)%P && (((x-a)^(P))<0));
    }
    bool operator < (const seg & B) const {
        return l!=B.l?l<B.l:r<B.r;
    }
};

vector<seg> v;
int eval(int x) {
    int at = upper_bound(ALL(v), seg(x,2e9)) - v.begin() - 1;
    if (at != -1 && v[at].a == -1) --at;
    bug(x, at);
    if (at == -1) return 0;
    return v[at].gt(min(x, v[at].r));
}



signed main(){
    IOS();
    int L, n, t; cin>>L>>n>>P>>t;
    REP(i,n) {
        int l,r; cin>>l>>r;
        if (r-l < P) continue;
        v.pb(seg(l,r));
    }
    sort(ALL(v));
    for (seg &s : v) {
//        int none = eval(s.l);
        {
            int l = s.l, r = s.l + P;
            int getL = eval(s.l-t);
            bug(getL);
            while (l!=r) {
                // find first point better than get(s.l)
                int mid = (l+r)/2;
                if (mid >= s.l+P || eval(mid-t) > getL) {
                    // ok, this mid works
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            s.c = getL+1;
//            assert(l == s.l+P || (eval(l-t) == getL+1));
            s.a = l;

            bug(s.l, s.r, s.c, s.a);
            bug(s.gt(s.r));
        }

        {
            int none = eval(s.l-1);
            int l = s.l, r = s.r+1;
            while (l!=r) {
                int mid = (l+r)/2;
                if (s.gt(mid) > none) {
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            s.befthis = l; s.befval = none;
            bug(none, s.befthis, s.l);
        }
    }

    if (SZ(v)==0) cout<<0<<endl;
    else{
        cout<<v.back().gt(v.back().r)<<endl;

    }



}