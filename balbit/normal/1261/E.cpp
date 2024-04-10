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

const int maxn = 1e3+5;

char g[maxn][maxn];
//vector<int> at[maxn];

signed main(){
    IOS();

    int n; cin>>n;
    vector<int> a(n);
    vector<pii> pp;
    REP(i,n) cin>>a[i], pp.pb({a[i], i});
    sort(ALL(pp));
    sort(ALL(a));

    REP(i,n+1) {
        REP(j,n) {
            if (i == 0) g[i][j] = '1';
            else {
                g[i][j] = (i-1==j)?'0':'1';
            }
        }
    }
    REP(i,n) {
        REP(j, n-a[i]) {
            g[(i+2+j) % (n+1)][i] = '0';
        }
    }
    vector<string> out;
    REP(i,n+1) {
        string tmp = "";
        bool hi = 0;
        REP(j,n) {
            if (g[i][j] != '0') hi = 1;
            tmp += g[i][j];
        }
        if (hi) {
            if (SZ(out) && tmp == out[0]) {
                bug(tmp);
                for (string & y : out) {
                    bool ok = 1;
                    REP(j,n) {
                        if (tmp[j]=='1' && y[j] == '1') {
                            ok = 0; break;
                        }
                    }
                    if (ok) {
                        bug(tmp);
                        bug(y);
                        REP(j,n) {
                            if (tmp[j] == '1') y[j] = '1';
                        }
                        break;
                    }
                }
            }else{
                out.pb(tmp);
            }
        }
    }
    cout<<SZ(out)<<endl;
    for (string s : out) {
        vector<char> hi(n);
        REP(i, n) {
            hi[pp[i].s] = s[i];
        }
        for (char c : hi) cout<<c;

        cout<<endl;
    }
}