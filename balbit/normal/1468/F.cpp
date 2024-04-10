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

const int maxn = 1e5+5;

struct pt {
    ll x,y;
    ll operator ^(pt b) {
        return x * b.y - y * b.x;
    }
    pt operator - (pt b) {
        return {x-b.x, y-b.y};
    }
    pt operator + (pt b) {
        return {x+b.x, y+b.y};
    }
    bool operator < (const pt &b) const {
        return x!=b.x?x<b.x:y<b.y;
    }
    bool operator == (pt b) {
        return x==b.x && y == b.y;
    }
    void red(){
        ll g = __gcd(abs(x), abs(y));
        x/=g; y/=g;
    }
};

bool anglecmp (pt &a, pt &b) { // Sort by ccwise angle
    int o1 = (a.y>0 || (a.y==0 && a.x>0));
    int o2 = (b.y>0 || (b.y==0 && b.x>0));
    if (o1==o2) {
        return (a^b)>0;
    }else{
        return o1>o2;
    }
};

signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<pt> v;
        map<pt, int> st;
        ll re = 0;
        REP(i,n) {
            int a,b,c,d; cin>>a>>b>>c>>d;
            pt hi = pt{c-a,d-b};
            pt que = pt{a-c,b-d};
            hi.red(); que.red();
            re+=st[que];
            st[hi]++;
        }
        cout<<re<<endl;
    }
}