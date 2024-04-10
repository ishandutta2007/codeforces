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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

bool okay(vector<int> s, vector<int> p) {
    if (SZ(p) == 1) {
        sort(ALL(s)); return s[0] == s.back();
    }
    int n = SZ(s);
    bug(n, SZ(p));
    {
        int Y = p.back(), X = n/Y;
        bug(X,Y);
        vector<vector<int> > tmp(X, vector<int> (Y,0));

        REP(it, n) {
            int x = it % X, y = it % Y;
            tmp[x][y] = s[it];
        }
//        REP(x,X) REP(y,Y) {
//            cout<<tmp[x][y]<<" \n"[y==Y-1];
//        }
        REP(x,X) RREP(y,Y) {
            tmp[x][y] -= tmp[x][0];
        }
//        REP(x,X) REP(y,Y) {
//            cout<<tmp[x][y]<<" \n"[y==Y-1];
//        }
        if (SZ(p) == 2) {
            REP(x,X) {
                if (tmp[x] != tmp[0]) return 0;
            }
            return 1;
        }else{
            vector<vector<int> > go(Y);
            REP(it, n) {
                int x = it % X, y = it % Y;
                if (y) {
                    go[y].pb(tmp[x][y]);
                }
            }
            p.pop_back();
            REP1(y,Y-1) {
                if (!okay(go[y], p)) {
                    return 0;
                }
            }
            return 1;
        }
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    vector<int> s;
    REP(i,n) {
        char c; cin>>c;
        s.pb(c-'0');
        bug(s.back());
    }
    int over = 1;
    vector<int> pfac;
    int at = n;
    for (int ty = 2; ty <= n; ++ty) {
        if (at % ty == 0) {
            pfac.pb(ty); at/=ty;
            while (at%ty == 0) {
                at/=ty; over *= ty;
            }
        }
    }
    bug(over);
    bug(SZ(pfac));
    REP(mo, over) {
        vector<int> go;
        for (int tk = 0; tk < n; tk += over) {
            go.pb(s[tk+mo]);
            bug(s[tk+mo], tk, mo);
        }
        bool ha = okay(go, pfac);
        if (!ha) {
            cout<<"NO"<<endl; return 0;
        }
    }
    cout<<"YES"<<endl;
}