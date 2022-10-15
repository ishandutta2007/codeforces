#include <bits/stdc++.h>
#define int ll
//#undef BALBIT
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

const int maxn = 1e5+5;


map<pii, int> mp;

int B = 100000000;

vector<int> xl, yl;

int get(int x, int y) {
    #ifdef BALBIT
    int ret = B*3;
    for (int X : xl) MN(ret, abs(X-x));
    for (int Y : yl) MN(ret, abs(Y-y));
    return ret;
    #endif // BALBIT
    if (mp.count({x,y})) {
        return mp[{x,y}];
    }
    cout<<"0 "<<x<<' '<<y<<endl<<flush;
    cin>>mp[{x,y}];
    if (mp[{x,y}] == -1) {
        assert(0);
    }
    return mp[{x,y}];
}

array<vector<int>, 2> ret;

//int reps = 0;
//
//void run(array<int, 2> at, int y, int dir, int T, int prvdst) {
//    // dir = 1 or -1
//    // y is 1 if i'm working with y
//    bug(at[0], at[1],y,dir);
//    ++reps;
////    if (reps > 100) return;
//    if (min(at[0], at[1]) < -B || max(at[0], at[1]) > B) return;
//    int ga = get(at[0], at[1]);
//    if (ga >= T) {
//        // big move time
//        at[y] += dir * T;
//        run(at, y,dir,T,T);
//        return;
//    }
//    if (ga >= prvdst) {
//        // technically only equals, but the > is for hax
//        assert(ga == prvdst); // nvmind, no hax
//        at[y] += dir * prvdst;
//        run(at, y, dir, T, prvdst*2);
//        return;
//    }
//    // yay! finally here!
//    {
//        at[y] += dir * ga;
////        assert(get(at[0], at[1]) == 0); // shouldn't do this in actual sub, wasting queries
//        ret[y].pb(at[y]);
//        at[y] += dir;
//        bug(at[y]);
//        run(at, y, dir, T, 1);
//        return;
//    }
//}

int nox, noy;

void go(int x, int y, int targ) {
//    bug(x,y);
    if (SZ(ret[0]) == 10000 && SZ(ret[1]) == 10000) return;
    if (x > B || y > B) return;
    int ya = get(x,y);
    x += ya; y += ya;
    bug(x,y,ya,targ);
    if (x > B || y > B) return;
    if (ya >= targ) {
        go(x,y,targ*2);
        return;
    }
//    bug(get(x,noy));
    if (SZ(ret[0]) < 10000 && get(x,noy)==0) {
        ret[0].pb(x);
    }
    if ((mp.count({x,noy}) && mp[{x,noy}]!=0) || (SZ(ret[1]) < 10000 && get(nox,y)==0) ) {
        ret[1].pb(y);
    }
    go(x+1,y+1,1);
}

signed main(){
    IOS();

    mt19937 rnd(time(0));

    xl = {-99984228, 4,5,6, -99974110};
    yl = {1,2,3,4,5,6};

    pair<int, pii> bst;
    bst = {-1, {0,0}};
    REP(rar, 5000) {
        int x,y;
        x = rnd() % (2*B+1)-B;
        y = rnd() % (2*B+1)-B;
        if (get(x,y) > 0) {
            nox = x; noy = y;
            break;
        }
    }

    bug(nox, noy);

    int T = bst.f;
    int X = bst.s.f, Y = bst.s.s;

    bug(X,Y,T);
    go(-B,-B,B*2+2);

    swap(ret[1], ret[0]);
    if (min(SZ(ret[0]), SZ(ret[1])) == 0) {
        assert(0);
    }
    cout<<"1 "<<SZ(ret[1])<<' '<<SZ(ret[0])<<endl<<flush;
    sort(ALL(ret[1]));
    sort(ALL(ret[0]));
    REP(i,SZ(ret[1])) cout<<ret[1][i]<<' '; cout<<endl;
    REP(i,SZ(ret[0])) cout<<ret[0][i]<<' '; cout<<endl;
    cout<<flush;
}