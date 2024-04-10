#include <bits/stdc++.h>
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

const int maxn = 5e3+5;

int par[maxn],s[maxn],to[maxn];
int find(int x) {return x == par[x]?x:par[x] = find(par[x]);}
void mg(int a, int b) {
    a=find(a); b=find(b);
    par[a]=b; to[b]=max(to[b], to[a]);
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        REP(i,n) {
            cin>>s[i]; par[i] = i; to[i] = i;
        }
        to[n]=par[n]=n;
        REP(i,n) {
            if (s[i] == 1) {
                mg(i,i+1);
            }
        }
        ll re = 0;
        while(to[find(0)]!=n) {
            int tt = to[find(0)];
            if (tt + s[tt] >= n+1) {
                int tk = tt+s[tt]-n;
                s[tt] -= tk; re += tk;
                bug(s[tt]);
                if (s[tt] == 1) mg(tt, tt+1);
                continue;
            }
            int at = to[find(0)];
                ++re;
            while (at < n) {
                bug(at);
                assert(s[at] != 1);
                --s[at];
                if (s[at] == 1) mg(at, at+1);
                at=at+s[at]+1;
                if (at >= n) break;
                at = to[find(at)];
            }
        }
        cout<<re<<endl;

    }

}