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

const int maxn = 5e5+5;


signed main(){
    IOS();
    int n; cin>>n;
    vector<int> a(n);
    ll sig = 0;
    REP(i,n) {
        cin>>a[i];
        sig += a[i];
    }
    sort(ALL(a));
    priority_queue<ll, vector<ll>, greater<ll> > pack;
    int bigger = 0;
    int cnt = 0;
    ll re = 0;
    for (int i = n-1; i>=0; --i) { // go from expensive to cheap items
        ++cnt;
        if (i == 0 || a[i-1] != a[i]) {
            bug(a[i], cnt);
            // work with this package of cnt items with weight a[i] each
            bug (bigger, SZ(pack));
            int free = min(cnt, bigger - SZ(pack) * 2); // which ones are free
            vector<ll> upd;
            REP(j, free) {
                upd.pb(a[i]);
                re += a[i]; // just take it, why not? :P
            }
            REP(j, (cnt-free)/2) {
                // we consider the remaining ones in packs of 2
                if (pack.empty() || pack.top() >= a[i] * 2) break;
                ll t = pack.top(); pack.pop(); // we have a coupon for 2 free items, priced t
                if (t <= a[i]) {
                    // wow, this is cheap!!!! might as well replace it with a[i] * 2
                    re -= t;
                    re += a[i]*2;
                    upd.pb(a[i]);
                    upd.pb(a[i]);
                }
                else if (t < a[i]*2) {
                    re -= t;
                    re += a[i]*2;
                    // we might want to regret this decision though... those 2 a[i] items give 2 free items themselves, so the overall
                    // reverse operation is equal to a coupon of price (a[i]*2-t)!
                    upd.pb(t);
                    upd.pb(a[i]*2-t);
                }
            }
            if ((cnt - free) % 2) {
                if (!pack.empty() && pack.top() < a[i]) {
                    int t = pack.top(); pack.pop();
                    re -= t; re += a[i];
                    upd.pb(a[i]); // a free spot has opened up!
                }
            }
            for (ll x : upd) pack.push(x);
            bigger += cnt;
            cnt = 0;
        }
    }
    cout<<sig - re<<endl;
}

/*
6
1 3 5 5 5 5
*/