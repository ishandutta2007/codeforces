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

const int maxn = 3e5+5;

const int thres = 1300;
int noc[maxn];
vector<int> spec;
int ps[(maxn/thres)+5][maxn];
//int close[(maxn/thres)+5][maxn];
int a[maxn];

int tmpmp[maxn]; // remember to clear after operations!!!!!

signed main(){
    IOS();
    int n,q; cin>>n>>q;
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
        noc[a[i]]++;
    }
    for (int Me = 1; Me<=n; ++Me) {
        if (noc[Me] >= thres) {
            for (int i = 1; i<=n; ++i) {
                ps[SZ(spec)][i] = ps[SZ(spec)][i-1] + (a[i-1] == Me);
            }
//            close[SZ(spec)][n] = n;
//            for (int i = n-1; i>=0; --i) {
//                if (a[i] == Me) close[SZ(spec)][i] = i;
//                else close[SZ(spec)][i] = close[SZ(spec)][i+1];
//            }
            spec.pb(Me);
        }
    }
    while (q--) {
        int l,r,k; cin>>l>>r>>k; --r; --l;
        int need = 1+((r-l+1)/k);
        bug(need);
        if (need >= thres) {
            int closest = n+1;
            int ans = -1;
            for (int i = 0; i<SZ(spec); ++i) {
                if (ps[i][r+1] - ps[i][l] >= need) {
//                    if (close[i][l] < closest) {
//                    closest = close[i][l];
                    ans = spec[i]; break;
//                    }
                }
            }
            cout<<ans<<endl;
        }else{
            int ans = -1;
            for (int i = l; i<=r; ++i) {
                tmpmp[a[i]]++;
                if (tmpmp[a[i]] >= need && (a[i] < ans || ans == -1)) {
                    ans = a[i];
                }
            }
            for (int i = l; i<=r; ++i) {
                tmpmp[a[i]]=0;
            }
            cout<<ans<<endl;
        }

    }

}