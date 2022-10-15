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

int which = 0;

int ask(int x) {
    ++which;
    cout<<"? "<<x+1<<endl<<flush;
    int r; cin>>r; return r-1;
}

bool done[maxn];
bool seen[maxn];
int a[maxn];

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        which = 0;
        REP(i,n) {
            done[i] = seen[i] = 0;
        }

        REP(i,n) {
            if (!seen[i]) {
                vector<int> cyc;
                int sh = which;
                int wherei = -1;
                while (1) {
                    int t = ask(i);
                    if (seen[t]) break;
                    if (t == i) {
                        wherei = SZ(cyc);
                    }
                    cyc.pb(t);
                    seen[t] = 1;
                }

                bug(i);
                #ifdef BALBIT
                for (int x : cyc) cout<<x<<' ';
                cout<<endl;
                #endif // BALBIT

                assert(wherei != -1);

                int toi = ((-sh + 1) % SZ(cyc) + SZ(cyc)) % SZ(cyc);
                bug(i, toi);

                REP(j, SZ(cyc)) {
                    int at = (j + wherei) % SZ(cyc);
                    a[cyc[at]] = cyc[toi];
                    toi = (toi + 1) % SZ(cyc);
                }
            }
        }

        cout<<"! ";
        REP(i,n) cout<<a[i]+1<<' ';
        cout<<endl<<flush;

    }


}