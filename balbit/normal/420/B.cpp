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
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 1e5+5;

bool on[maxn];
bool seen[maxn];
bool pos[maxn];

signed main(){
    IOS();
    int non = 0;
    vector<pair<int, bool> > v;
    int n, q; cin>>n>>q;
    fill(pos, pos+maxn, 1);
    REP(i,q) {
        char x; int t;
        cin>>x>>t; v.pb({t, x=='+'});
        if (x=='-' && !seen[t]) on[t] = 1, non ++;
        seen[t] = 1;
    }
    bug(non);
    REP(i,q) {
        non += v[i].s?1:-1;
        if ((v[i].s == 0 && non > 0) || (v[i].s==1 && non > 1)) {
            pos[v[i].f] = 0;
        }
        if (v[i].s && i && v[i-1].f != v[i].f) pos[v[i].f] = 0;
        if (!v[i].s && i!=q-1 && v[i+1].f != v[i].f) pos[v[i].f] = 0;
    }
    vector<int> re;
    REP1(i,n) {
        if (pos[i]) re.pb(i);
    }
    cout<<SZ(re)<<endl;
    for (int x : re) cout<<x<<' ';
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}