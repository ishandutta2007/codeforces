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

int a[maxn], b[maxn];

vector<pii> get(int *e, int n) {
    vector<pii> re;
    REP(i, n) {
        int x = e[i], y = e[i+1];
        if (x > y) swap(x,y);
        re.pb({x,y});
    }
    sort(ALL(re)); return re;
}

void run() {
    int n; cin>>n;


    a[0] = b[0] = n+1;
    a[n+1] = b[n+1] = n+2;

    REP1(i,n) {
        cin>>a[i];
    }

    REP1(i,n) {
        cin>>b[i];
    }

    vector<pii> va = get(a,n), vb = get(b,n);

    if (va != vb) {
        cout<<"NO"<<endl; return;
    }

    assert(a[1] == b[1] && a[n] == b[n]);

    vector<pii> re;

    auto flip = [&](int l, int r) {
        if (l >= r) return;
        assert(a[l] == a[r]);
        for (int i = l; i<r; ++i) {
            int j = r - (i-l);
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        re.pb({l,r});
    };

    for (int fix = 2; fix < n; ++fix) {
        if (a[fix] == b[fix]) continue;

        vector<int> use;

        for (int ty = fix; ty <= n; ++ty) {
            if (a[ty] == a[fix-1] && a[ty-1] == b[fix]) {
                flip(fix-1, ty);
                break;
            }
            if (ty < n && a[ty] == a[fix-1] && a[ty+1] == b[fix]) {
                use.pb(ty);
            }
        }
        if (a[fix] == b[fix]) continue;

        if (SZ(use) == 0) {
            cout<<"What"<<endl<<flush; exit(0);
        }
//        assert(SZ(use));

        for (int u : use) {
            for (int l = fix; l <= u; ++l) {
                for (int r = u+1; r <= n; ++r) {
                    if (a[l] == a[r]) {
                        flip(l,r);
                        goto over;
                    }
                }
            }
        }
        over:;

        for (int ty = fix+1; ty <= n; ++ty) {
            if (a[ty] == a[fix-1] && a[ty-1] == b[fix]) {
                flip(fix-1, ty);
                break;
            }
        }

        assert(a[fix] == b[fix]);
    }

    cout<<"Yes"<<endl;
    cout<<SZ(re)<<endl;
    for (pii p : re) cout<<p.f<<' '<<p.s<<endl;
}



signed main(){
    IOS();

    int t; cin>>t; while (t--) run();


}