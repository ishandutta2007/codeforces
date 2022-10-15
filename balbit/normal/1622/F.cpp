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

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

ull H[maxn];
bool np[maxn];
ull val[maxn];
int n;

void RET(vector<int> no) {
    vector<int> yay(n+1);
    for (int t : no) yay[t] = 1;
    cout<<n-SZ(no)<<endl;
    REP1(i,n) {
        if (!yay[i]) cout<<i<<' ';
    }
    cout<<endl; exit(0);
}

signed main(){
    IOS();

    mt19937_64 rnd(time(0));

    REP(i,maxn) {
        val[i] = rnd();
    }

    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {

            for (int j = i; j<maxn; j+=i) {
                if (j!=i) np[j] = 1;
                int r = j;
                while (r % i == 0) {
                    r /= i; H[j] ^= val[i];
                }
            }
        }
    }
    cin>>n;

//    REP1(i,n) bug(i, H[i]);

    for (int i = 1; i<maxn; ++i) H[i] ^= H[i-1];



    ull all = 0;
    for (int i = 1; i<=n; ++i) all ^= H[i];

//    bug(all);

    if (all == 0) {
        RET({});
    }

    for (int i = 1; i<=n; ++i) {
//        bug(i, H[i], H[i]^all);
        if (H[i] == all) {
            RET({i});
        }
    }

    vector<pair<ull, int> > v;
    REP1(i,n) {
        v.pb({H[i],i});
    }
    sort(ALL(v));

    REP1(i,n) {
        int at = lower_bound(ALL(v), pair<ull, int>{H[i]^all,i+1}) - v.begin();
        if (at < SZ(v) && (v[at].f == (H[i]^all))) {
//            bug(H[i], H[i]^H[v[at].s], all);
            RET({i, v[at].s});
        }
    }

    assert(n % 2 == 1);
    RET({n, n/2, 2});

}