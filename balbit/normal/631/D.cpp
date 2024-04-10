#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+87;


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

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 2e6+5;
const ll B = 2000003;
ll pB[maxn];
#define pic pair<ll, char>
signed main(){
//    IOS();
    int n, m; scanf("%d %d",&n,&m);
    vector<pic> s, t;
    REP(i,n) {
        int l; char c;
        scanf("%d-%c", &l, &c);
        if (s.empty() || s.back().s!=c) s.pb({l,c});
        else s.back().f+=l;
    }
    REP(i,m) {
        int l; char c;
        scanf("%d-%c", &l, &c);
        if (t.empty() || t.back().s!=c) t.pb({l,c});
        else t.back().f+=l;
    }
    n = SZ(s); m = SZ(t);
    if (n<m) GG();
    bug(n,m);
    pB[0]=1;
    FOR(i,1,maxn) {
        pB[i] = pB[i-1] * B % mod * B % mod;
    }
    if (m==1 ) {
        ll re = 0;
        REP(i,n) {
            if (s[i].s == t[0].s) re += max(0ll,s[i].f-t[0].f+1);
        }
        cout<<re<<endl;
    }else{
        ll nh = 0;
        ll th = 0;
        FOR(j,1,m-1) {
            nh = nh * B % mod * B % mod;
            nh = (nh + s[j].f*B+(s[j].s-'a'+1)) % mod;
            th = th * B % mod * B % mod;
            th = (th + t[j].f*B+(t[j].s-'a'+1)) % mod;
        }
        bug(th);
        bug(nh);
        ll re = 0;
        REP(i,n-m+1) {
            if (s[i].s == t[0].s && s[i].f >= t[0].f && s[i+m-1].s == t[0+m-1].s && s[i+m-1].f >= t[0+m-1].f) {
                if (nh == th) re ++;
            }
            nh = nh * B % mod * B % mod;
            nh += s[i+m-1].f*B+(s[i+m-1].s-'a'+1);
            nh %= mod;
            nh-=pB[m-2] * (s[i+1].f*B%mod+(s[i+1].s-'a'+1)) % mod;
            if (nh<0) nh += mod;
            bug(nh);
        }
        cout<<re<<endl;
    }
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}
/*
10 4

1-a 3-b 2-c 1-d

*/