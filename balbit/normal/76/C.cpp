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

ll F[1<<22]; // updating all supermasks!
ll v[23][23];
ll rem[23];

void upd(int msk, int a, int b) {
    // stuff highlighted in mask have to be deleted
    // a and b have to NOT be deleted
    bug(msk, a, b);
    assert((msk & (1<<a)) == 0);
    assert((msk & (1<<b)) == 0);
    if (1) { // should be applicable to all cases (?)
        F[msk] += v[a][b];
        F[msk | (1<<a)] -= v[a][b];
        F[msk | (1<<b)] -= v[a][b];
        F[msk | (1<<a) | (1<<b)] += v[a][b];
    }
}

signed main(){
    IOS();

    int n,k,t; cin>>n>>k>>t;
    vector<int> a;
    int allpos = 0;
    REP(i,n) {
        char c; cin>>c; a.pb(c - 'A');
        allpos |= (1<<a.back());
    }
    REP(i,k) cin>>rem[i];
    REP(i,k) {
        REP(j,k) {
            cin>>v[i][j];
        }
    }
    vector<int> now;
    REP(i,n) {
        int msk=0; // mask of stuff you have to delete
        for (int j = SZ(now)-1; j>=0; --j) {
            upd(msk, now[j], a[i]); // order MATTERS
            if (now[j] == a[i]) break; // cannot go any further
            msk += 1<<(now[j]);
        }
        for (int j = 0; j<SZ(now)-1; ++j) {
            if (now[j] == a[i]) {
                swap(now[j], now[j+1]);
            }
        }
        if (SZ(now) == 0 || now.back() != a[i]) now.pb(a[i]);
        bug(i);
//        for (int x : now) cout<<x<<' ';
//        cout<<endl;
    }

    for (int i = 0; i<k; ++i) {
        REP(m, (1<<k)) {
            if (m & (1<<i)) {
                F[m] += F[m ^ (1<<i)];
            }
        }
    }
    int re= 0 ;
    REP(m, (1<<k)) {
        if ((m | allpos) > allpos) continue;
        REP(i,k) {
            if (m & (1<<i)) {
                F[m] += rem[i];
            }
        }
        bug(m, F[m]);
        if ((m&allpos) != allpos)
            re += F[m] <= t;
    }
    cout<<re<<endl;
}

/*
2 2 3
AB
2 3
1 3
3 1

*/