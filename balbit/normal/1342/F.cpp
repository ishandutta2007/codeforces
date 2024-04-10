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

int nxtbit[1<<15][15]; // given this mask and this point, what is the next set bit in it

int dp[1<<15][15][15]; // mask remaining, last position, number taken
pii from[1<<15][15][15];
int sum[1<<15];
int a[maxn];

signed main(){
    IOS();

    REP(m, 1<<15) {
        REP(i,15) {
            nxtbit[m][i] = -1;
            for (int j = i; j<15; ++j) {
                if (m & (1<<j)) {
                    nxtbit[m][i] = j; break;
                }
            }
        }
    }

//    bug(nxtbit[3][0]);

    int _; cin>>_;
    while (_--) {
        int n; cin>>n;
        bool flip = 0;
        REP(i,n) {
            cin>>a[i];
            if (i && a[i-1] >= a[i]) flip = 1;
        }
        if (!flip) {
            cout<<0<<endl; continue;
        }
        REP(m,1<<n) {
            sum[m] = 0;
            REP(i,n) {
                if (m & (1<<i)) {
                    sum[m] += a[i];
                }
                REP(j,n) {
                    dp[m][i][j] = iinf;
                }
            }
        }
        dp[(1<<n)-1][0][0] = 0;
        for (int m = (1<<n)-1; m>0; --m) {
            REP(i,n) {
                REP(j,n) {
                    if (dp[m][i][j] < iinf) {
                        // yarrr
                        for (int s = m; s > 0; s = (s-1)&m) {

                            if (sum[s] > dp[m][i][j] && nxtbit[s][i] >= i && sum[s] < dp[m^s][nxtbit[s][i]][j+1]) {
//                                bug(m, s, i, j);
                                dp[m^s][nxtbit[s][i]][j+1] = sum[s];
                                from[m^s][nxtbit[s][i]][j+1] = {s,i};
                            }
                        }
                    }
                }
            }
        }

        int re = 0;
        int eye = -1;
        REP(i,n) REP(j,n) {
            if (dp[0][i][j] != iinf) {
                if (j > re) {
                    re = j;
                    eye = i;
                }
            }
        }
        int msk = 0;
        vector<pii> mv;
        vector<int> left;

        auto gp = [&](int x) {
            return find(ALL(left), x) - left.begin();
        };

        REP(i,n) left.pb(i);

        while (msk != (1<<n)-1) {
            pii ch = from[msk][eye][re];
            bug(msk, eye, re, ch.f, ch.s);
            REP(i,n) {
                if (ch.f & (1<<i)) {
                    if (i != eye) {
                        mv.pb({gp(i)+1, gp(eye)+1});
                        left.erase(left.begin()+gp(i));
                    }
                }
            }
            bug(msk, eye);
            msk ^= ch.f;
            re--;
            eye = ch.s;
        }
        cout<<SZ(mv)<<endl;
        for (auto e : mv) cout<<e.f<<' '<<e.s<<endl;
//        cout<<re<<endl;

    }

}