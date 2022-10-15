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

struct seg{
    int S[maxn*2];
    int QU(int e) {
        int re = 0;
        for (++e; e > 0; e -= e&-e) {
            re += S[e];
        }return re;
    }
    void MO(int e, int v) {
        for (++e; e<maxn*2; e+=e&-e) {
//            bug(e, v);
            S[e] += v;
        }
    }
    seg(){memset(S, 0, sizeof S);}
}tt[3];
vector<pii> clr[3];

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;
        int x = 0;
        ll re = 0;

        tt[0].MO(x+maxn, 1);
        clr[0].pb({x+maxn, -1});

        REP(i,n) {
            if (s[i] == '+') {
                --x;
            }else{
                ++x;
            }
            re += tt[(x%3+3)%3].QU(x+maxn);
            tt[(x%3+3)%3].MO(x+maxn, 1);
            clr[(x%3+3)%3].pb({x+maxn, -1});
        }

        REP(e,3) {
            for (pii p : clr[e]) {
                tt[e].MO(p.f, p.s);
            }
            clr[e].clear();
        }


        cout<<re<<endl;
    }

}