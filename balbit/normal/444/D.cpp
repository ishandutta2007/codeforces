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

string s; //cin>>s;
vector<int> here[600000+5];

int gethash(string t) {
    int re = 0;
    REP(i,4) {
        int c = i < SZ(t)? t[i] - 'a' : 26;
        re = re * 27 + c;
    }
    return re;
}

map<pii, int> mp;

int get (int a, int b, int lena, int lenb) {
    if (SZ(here[a])==0 || SZ(here[b]) == 0) return -1;
    if (SZ(here[a]) > SZ(here[b])) {
        swap(a,b); swap(lena, lenb);
    }
    if (mp.count({a,b})) return mp[{a,b}];
    int re = iinf;



    for (int p : here[a]) {
        // p is the smaller one

        auto upd = [&](int at) {
            bug(here[b][at], p, lenb, lena);
            MN(re, max(here[b][at]+lenb, p+lena) - min(here[b][at], p));
        };

        int at = lower_bound(ALL(here[b]), p) - here[b].begin();
        if (at < SZ(here[b])) {
            upd(at);
        }
        --at;
        if (at >= 0) {
            upd(at);
        }

    }

    if (re == iinf) re = -1;
    return mp[{a,b}] = re;
}

signed main(){
    IOS();
    cin>>s;
    REP(i,SZ(s)) {
        string t;
        for (int j = 0; j<4 && i+j<SZ(s); ++j) {
            t += s[i+j];
            here[gethash(t)].pb(i);
        }
    }

    int t; cin>>t;
    while (t--) {
        string a, b; cin>>a>>b;
        int ai = gethash(a), bi = gethash(b);
        bug(ai, bi);
        cout<<get(ai,bi,SZ(a), SZ(b))<<endl;
    }



}