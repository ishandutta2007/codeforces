#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define y1 zck_is_king
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

vector<pii> here[maxn];
ll dp[maxn][2];

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
//        vector<pii> seg(m);
        vector<ll> a(n+2);
        a[0] = -1e15; a.back() = 1e15;
        REP(i,n) {
            cin>>a[i+1];
        }
//        n += 2;
        sort(ALL(a));
        REP(i,n+2) here[i].clear();
        REP(i,m) {
            int l,r; cin>>l>>r;
            int at = lower_bound(ALL(a), l) - a.begin() - 1;
            if (r >= a[at+1]) continue;
            bug("Useful", l,r,a[at], a[at+1]);
            if (at == n+1) assert(0);
            here[at].pb({l,r});
        }
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i<=n+1; ++i) {
            vector<pair<pii, int> > fl, fr;
            for (pii p : here[i-1]) {
                fl.pb({p, SZ(fl)});
                fr.pb({p, SZ(fr)});
//                bug(fr.back().s);
            }
            sort(ALL(fl));
            if (i == 5) {
                for (auto pp : fl) bug(pp.f.f);
            }
            sort(ALL(fr), [&](pair<pii, int> a, pair<pii, int> b) {return a.f.s!=b.f.s?a.f.s>b.f.s:a.f.f>b.f.f;});
            bug(i);
            int k = SZ(fl);
            bug(k);
            REP(b, 2) { // i am b
                dp[i][b] = inf;
                REP(c,2) { // transfer from c
                    vector<int> cov(k,0);
//                    int ncov = k;
                    int j = SZ(fr)-1;
                    ll cost = (j==-1?0:a[i] - fr[j].f.s) * (b+1);
//                    bug(cost);
                    for (int I = 0; I<k; ++I) {
                        cov[fl[I].s] = 1;
                        while (j != -1 && cov[fr[j].s]) {
                            --j;
                        }
//                        if (i == 5) {
//                            ll yo = (j==-1?0:a[i] - fr[j].f.s) * (b+1) + (fr[I].f.f - a[i-1]) * ((c)+1);
//                            bug(I,j,yo, a[i-1], fl[I].f.f);
//                        }
                        MN(cost, (j==-1?0:a[i] - fr[j].f.s) * (b+1) + (fl[I].f.f - a[i-1]) * ((c)+1));
                    }
                    assert(j==-1);
//                    bug(i,b,c, cost);

                    MN(dp[i][b], dp[i-1][c^1] + cost);
                }
                bug(i,b,dp[i][b]);
            }

        }

        cout<<min(dp[n+1][0], dp[n+1][1])<<endl;


    }




}