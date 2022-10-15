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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

int test(ll msk, int n) {
    int re = 0;
    ll hbit = 1ll<<(n-1);
    ll now = (msk ^ hbit) << 1;
    if (now == 0) return 1;
    while (now != 2) {
        ++re;
        if (now & hbit) (now ^= msk);
        now <<= 1;
    }
    return re;
}

string getbin(int x){
    string re;
    while (x) {
        re.pb('0'+x%2); x/=2;
    }
    reverse(ALL(re)); return re;
}

ll onestep(ll F, ll msk, int n) {
    if (F & (1ll<<(n-2))) {
        return (F<<1)^msk;
    }else return F<<1;
}

ll getnext(ll F, ll G, ll msk, int n) {
    __int128 tmp = 0;
    REP(i,n) {
        if (F & (1ll<<i)) tmp ^= (__int128)G<<i;
    }
//    bug((ll)tmp);
    for (int r = n*2; r>=n-1; --r) {
        if (tmp & (((__int128)1)<<r)) {
//            bug("fff",r);
            tmp ^= (__int128)msk << (r-n+1);
        }
    }
    return tmp;
}

unordered_map<ll, int> ump;

ll trans[17];

const int BS = 200000;

signed main(){
    IOS();

    bug(getnext(1, 5, 13, 4));

    string s; cin>>s;
    while (SZ(s) && s.back() == '0') s.pop_back();

    int mo = 0;
    REP(i, SZ(s)) {
        if (s[i] == '1') {
            mo += 1ll<<(SZ(s)-1-i);
        }
    }
    if (mo == 0) {
        cout<<-1<<endl; return 0;
    }
    int n = __lg(mo)+1;
    bug(n);
    int pref = SZ(s) - n + 1;

    if (__builtin_popcountll(mo) == 1) {
        cout<<pref<<' '<<pref+1<<endl; return 0;
    }

    // build smol

    vector<ll> hi = {1};
    ump[1] = 0;

    REP1(round, BS) {
        ll nw = onestep(hi.back(), mo, n);
//        bug(nw);
        if (ump.count(nw)) {
            cout<<pref<<' '<<round-ump[nw]+pref<<endl;
            return 0;
        }
        ump[nw] = round;
        hi.pb(nw);
    }

    ll now = hi.back();
    int rnds = 1;
    while (1) {
        ++rnds;
        now = getnext(now, hi.back(), mo, n);
        if (ump.count(now)) {
            bug(rnds, ump[now]);
            ll ho = rnds * BS - ump[now];
            cout<<pref<<' '<<ho+pref<<endl;
            return 0;
        }
    }


}