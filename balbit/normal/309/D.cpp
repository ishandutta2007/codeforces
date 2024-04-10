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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;


signed main(){
    IOS();
    int n,m; cin>>n>>m;
    ll re = 0;
    int n1 = n+1;
    int midway = 1+(n)/2;
    for (int x = m+1; x<(midway); x++) {
        int b = n-m; // next possible
        for (int a = m+1; a<n1-m; ++a) {
            while (b>m && (((n1-x)<<1) -b )*(ll)(a-(x<<1) ) + 3*a*b >= 0) {
                --b;
            }
//            bug(x,a,b);
            if (b <= m) break;
            re += b-m;
        }
    }
    bug(midway);
    re <<=1;
    if (n & 1) {
        int x = (midway);
        int b = n-m; // next possible
        for (int a = m+1; a<n1-m; ++a) {
            while (b>m && (((n1-x)<<1) -b )*(ll)(a-(x<<1) ) + 3*a*b >= 0) {
                --b;
            }
//            bug(x,a,b);
            if (b <= m) break;
            re += b-m;
        }
    }
    cout<<re*3<<endl;
}