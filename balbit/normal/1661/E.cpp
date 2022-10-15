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

const int maxn = 5e5+5;

bool a[3][maxn];
vector<pii> ask[maxn];

int pe[maxn], pv[maxn], pf[maxn], pf3[maxn];

int s[maxn];

ll QU(int e) {
    ll re = 0;
    for (++e; e>0; e-=e&-e) re += s[e];
    return re;
}

void MO(int e, int v) {
    for (++e; e<maxn; e+=e&-e) s[e] += v;
}
int ans[maxn];
signed main(){
    IOS();

    int n; cin>>n;
    REP(b,3) {
        REP1(i,n) {
            char c; cin>>c;
            a[b][i] = c == '1';
        }
    }

    int q; cin>>q;
    REP(i, q) {
        int l,r; cin>>l>>r; //--l; --r;
        ask[r].pb({l,i});
    }

    int lastsan = -1;

    REP1(R,n) {
        pv[R] = pv[R-1] + a[0][R] + a[1][R] + a[2][R];
        REP(b,3) pe[R-1] += (a[b][R-1]&&a[b][R]);
        pe[R] = pe[R-1] + (a[0][R]&&a[1][R]) + (a[1][R]&&a[2][R]);
        bug(pv[R], pe[R]);

        pf[R-1] += (a[0][R]&&a[0][R-1]&&a[1][R]&&a[1][R-1]);
        pf[R-1] += (a[2][R]&&a[2][R-1]&&a[1][R]&&a[1][R-1]);
        pf[R] = pf[R-1];

        if (!a[0][R] || !a[2][R]) {
            lastsan = -1;
        }

        bool san = a[0][R] && a[1][R] && a[2][R];

        if (san) {
            if (lastsan != -1 && lastsan < R-1) {
                MO(lastsan, 1);
                bug(lastsan, san);
            }
            lastsan = R;
        }

        for (auto P : ask[R]) {
            int l = P.f;
            int V = pv[R] - pv[l-1];
            int E = pe[R] - pe[l-1];

            int F = (pf[R] - pf[l-1]) + QU(R) - QU(l-1);
            bug(V,E,F);
            ans[P.s] = V-E+F;
        }
    }

    REP(i,q) cout<<ans[i]<<endl;

}


/*
6
111111
110001
111111
1
1 6

*/