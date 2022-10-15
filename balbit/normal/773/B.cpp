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
#define REP1(i,n) FOR(i,1,n+1)
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

const int maxn = 125;

int slv[6];
int a[5], b[5];

int vl(double x) {
    int re = 0;
    while (re<3000 && x<=1) {
        re += 500;
        x*=2;
    }
    return re;
}

signed main(){
    IOS();
    int l = 0, r = 5;
    int n; cin>>n;
    REP(i,5) {
        cin>>a[i];
        if (a[i]!=-1) slv[i]++;
    }
    REP(i,5) {
        cin>>b[i];
        if (b[i]!=-1) slv[i]++;
    }
    REP(i,n-2) {
        REP(j,5) {
            int x; cin>>x;
            if (x!=-1) slv[j]++;
        }
    }
    bug(vl(0.3), vl(1));
    REP(mid,1000000){
//        int mid = (l+r)/2;
        int tot = n+mid;
        ll A = 0, B = 0;
        REP(i,5) {
            bool ad = 1;
            if (a[i]==-1 || b[i]==-1 || (b[i]!=-1 && b[i]>a[i])) ad = 0;
//            if (ad==1) bug("hi");
            ll v = vl ((slv[i]+(ad*mid))/(double)tot);
//            bug(v);
            if (a[i]!=-1) A += v- v/250 * a[i];
            if (b[i]!=-1) B += v- v/250 * b[i];
        }
        if (A>B) {
            cout<<mid<<endl; return 0;
        }
    }
    cout<<-1<<endl;
//    else cout<<l<<endl;

}