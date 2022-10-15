#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
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

const int maxn = 1e5+5;



signed main(){
    IOS();
#ifdef BALBIT
freopen("input.in","r",stdin);
#endif // BALBIT
    double Sy, A, B;
    cin>>Sy>>A>>B; Sy = -Sy;
    int n; cin>>n;
    vector<pii> v;
    vector<ll> ps(n+2);
    REP(i,n) {
        ll l, r; cin>>l>>r; v.pb({l,r});
        ps[i+1] = ps[i] + (r-l);
        bug(ps[i+1]);
    }
    ps[n+1] = ps[n];
    int Q; cin>>Q;
    cout<<fixed<<setprecision(10);
    auto cmp1=[&](pii a,pii b){return a.f!=b.f?a.f<b.f:a.s<b.s;};
    auto cmp2=[&](pii a,pii b){return a.s!=b.s?a.s<b.s:a.f<b.f;};
    while (Q--) {
        double x, y; cin>>x>>y;
        double X = A + (x-A)/(double)(Sy+y)*Sy;
        double Y = B + (x-B)/(double)(Sy+y)*Sy;
        bug(X,Y);
        double ans1 = 0;
        int it1 = upper_bound(ALL(v),make_pair(-1,ceil(Y)),cmp2)-v.begin()-1;
        ans1 = ps[it1+1];
        if (it1!=n-1) {
            ans1 += max((double)0,Y-v[it1+1].f);
        }
        bug(it1);
        double ans2 = 0;
        it1 = upper_bound(ALL(v),make_pair(-1,ceil(X)),cmp2)-v.begin()-1;
        bug(it1);
        ans2 = ps[it1+1];
        if (it1!=n-1) {
            ans2 += max((double)0,X-v[it1+1].f);
        }
        bug(ans1, ans2);
        cout<<(ans1-ans2)/(Y-X)*(B-A)<<endl;
    }
}