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

const int maxn = 1e3+5;

int steps = 0;

vector<pii> re;

int A[maxn];

void te(pii &i, pii &j) {
    // i increases
    assert (j.f >= i.f);
    ++steps;
    A[j.s] -= A[i.s];
    A[i.s] *= 2;
    j.f -= i.f; i.f*=2;
    re.pb({i.s,j.s});
}


bool yum(pii &a, pii &b, pii &c, int to) {
    if (a.f == b.f) {
        te(a,b); return 1;
    }
    if (b.f == c.f) {
        te(b,c); return 1;
    }
    if (a.f == c.f) {
        te(a,c); return 1;
    }
    assert(b.f%a.f == to);
    if (b.f == to) return to == 0;

    if ((b.f-a.f) % (2*a.f) == to) {
        te(a,b);
    }else{
        te(a,c);
    }
    return yum(a,b,c,to);
}


void go(pii &a, pii &b, pii &c) {
//    if (steps > 3000) {
//        bug(steps);
//        bug(a.f,b.f,c.f); assert(0);
//    }
//    bug(a,b,c);
    ++steps;
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    if (a.f == b.f) {
        te(a,b);
        return;
    }
    if (b.f == c.f) {
        te(b,c);
        return;
    }
//    bug(a.f, b.f, c.f, b.f%a.f);
    if (!yum(a,b,c,b.f%a.f))
        go(a,b,c);
}



signed main(){
    IOS();

//    REP(j, 1000) {
//        ll a = rand()%1000000+1;
//        ll b = rand()%1000000+1;
//        ll c = rand()%1000000+1;
////        a=122;b=123994;c=479186;
//        if (a > b) swap(a,b);
//        if (b > c) swap(b,c);
//        if (a > b) swap(a,b);
//        steps = 0;
//        go({a,0},{b,1},{c,2});
//        bug(steps);
//        if (steps > 1000)
//            bug(steps);
////        bug(a,b,c,steps);
//    }
    int n; cin>>n;
    vector<pii> v;
    REP(i,n) {
        int x; cin>>x;
        A[i+1] = x;
        if (x != 0) {
            v.pb({x, i+1});
        }
    }
    if (SZ(v) <= 1) {
        cout<<-1<<endl; return 0;
    }
    if (SZ(v) == 2) {
        cout<<0<<endl; return 0;
    }
    vector<pii> now;
    while (SZ(v)) {
        while(SZ(now) < 3) {
            now.pb(v.back()); v.pop_back();
        }

        bug(now[0].f, now[1].f, now[2].f);

        go(now[0], now[1], now[2]);
        REP(i,3) {
            bug(i, now[i].f, now[i].s);
            if (now[i].f == 0) {
                now.erase(now.begin()+i);
                break;
            }
        }
        assert(SZ(now) == 2);
    }
    assert(SZ(re) <= 1000000);
    cout<<SZ(re)<<endl;
    for (pii p : re) {
        cout<<p.f<<' '<<p.s<<endl;
    }
    #ifdef BALBIT
    REP1(i,n) {
        cout<<A[i]<<' ';
    }
    cout<<endl;
    #endif // BALBIT

}

/*
3
2 9 100
*/
// 122 123994 479186