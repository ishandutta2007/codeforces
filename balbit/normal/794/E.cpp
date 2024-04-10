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

const int maxn = 3e5+5;

int n;
int a[maxn], ans[maxn]; // answer for this remaining length

signed main(){
    IOS();

    cin>>n;
    REP(i,n) {
        cin>>a[i];
    }

//    int cen = n/2;
    // case 1: odd number of nodes remaining: make 011 or 110 center, or only 1 in center

    REP(i,n) {

        int to = min(i, n-i-1) * 2 + 1;
        bug(i, to);
        if (to == 1) {
            MX(ans[to], a[i]);
        }else{
            MX(ans[1], a[i]);
            MX(ans[to], min(a[i], a[i-1]));
            MX(ans[to], min(a[i], a[i+1]));
        }
    }

    for (int i = n; i>=1; --i) {
        if (i % 2 == 1) {
            MX(ans[i], ans[i+2]);
            bug(i, ans[i]);
        }
    }

    // case 2: even number remaining: new cen = 1 or new cen = 101

    REP(i,n) {
        int to = min(i, n-i-1) * 2 + 1;
        ++to;
        if (to > n) to -= 2;
        bug(i, to);
        MX(ans[to], a[i]);
        if (i-1 >= 0 && i+1 < n) {
            MX(ans[to], min(a[i-1], a[i+1]));
        }
    }

    for (int i = n; i>=1; --i) {
        if (i % 2 == 0) {
            MX(ans[i], ans[i+2]);
            bug(i, ans[i]);
        }
    }

    REP(i, n) {
        cout<<ans[n-i]<<' ';
    }
    cout<<endl;

 // 6 4 1 3 2 5 6

}