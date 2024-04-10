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

const int maxn = 1e6+5;
#define int ll
map<ll, pair<int, int> > big;
map<ll, pair<int, int> > ids;
map<ll, ll> sho;
map<ll, ll> sid;

ll dp[200005][2];
int frm[200005][2];

signed main(){
    IOS();
    int n; cin>>n;
    vector<pair<ll, ll> >v;
    for (int i = 0; i<n; ++i) {
        int c,s; cin>>c>>s;
        sho[s] = c; sid[s] = i+1;
    }
//    sort(ALL(v));
    int m; cin>>m;
    for (int i = 0; i<m; ++i) {
        int d,l; cin>>l>>d;
        if (l > big[d].f) {
            ids[d].s = ids[d].f;
            big[d].s = big[d].f;
            ids[d].f = i+1;
            big[d].f=l;
        }
        else if (l > big[d].s) big[d].s = l, ids[d].s = i+1;
    }
    int i = 1;
    ll prevs = -3;
    vector<pair<int, int> > th (200005);
    vector<pair<int, int> > th2 (200005);
    vector<pair<int, int> > buyid(200005);
    for (auto & tt : big) {
        ll s = tt.f;
        if (prevs != s-1 && i != 1) {
            dp[i][0] = dp[i][1] = dp[i-1][1];
//            frm[i][0]=frm[i][1] = 0;
            ++i;
        }
        prevs = s;
        ll a = tt.s.f, b = tt.s.s;
        bug(i,s,a,b);
        ll L = (sho.count(s)?sho[s]:0), R = (sho.count(s+1)?sho[s+1]:0);
        buyid[i] = {ids[s].f, ids[s].s};
        if (a >= max(L,R) && b >= min(L,R)) {
            dp[i][1] = dp[i-1][0] + L + R;
            frm[i][1] = 3;
        }
        if (a >= L) {
            MX(dp[i][0], dp[i-1][0]+L);
            frm[i][0] = 1;
        }
        if (a >= R) {
            if (dp[i-1][1] + R > dp[i][1]) {
                MX(dp[i][1], dp[i-1][1] + R);
                frm[i][1] = 2;
            }
        }
        if (dp[i-1][1] > dp[i][0]) {
            dp[i][0] = dp[i-1][1];
            frm[i][0]= 0;
        }
        if (dp[i][0] > dp[i][1]) {
            MX(dp[i][1], dp[i][0]);
            frm[i][1] = frm[i][0];
        }
        th[i] = {sid[s], sid[s+1]};
        th2[i] = th[i];
        if (L < R) {
            swap(L,R);
            swap(th2[i].f, th2[i].s);
        }
        ++i;
    }
    cout<<dp[i-1][1]<<endl;
    vector<pii> ret;
    int wan = 1;
    for (int at = i-1; at >=0; --at) {
        bug(frm[at][wan], at, wan);
        if (frm[at][wan] == 3) {
            ret.pb({buyid[at].f, th2[at].f});

            ret.pb({buyid[at].s, th2[at].s});
            bug(buyid[at].f, buyid[at].s);
        }else if (frm[at][wan] == 2) {
            ret.pb({buyid[at].f, th[at].s});
        }else if (frm[at][wan] == 1) {
            ret.pb({buyid[at].f, th[at].f});
        }
        wan = 1^(frm[at][wan] & 1);
    }
    vector<pii> re;
    for (auto x : ret) if (x.f && x.s) re.pb(x);
    cout<<SZ(re)<<endl;
    for (auto & x : re) cout<<x.f<<' '<<x.s<<endl;
}