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

const int maxn = 5005;

struct pt{
    ll x, y;
    pt operator - (const pt &b) const {
        return {x-b.x,y-b.y};
    }
    pt operator + (const pt &b) const {
        return {x+b.x,y+b.y};
    }
    ll operator ^ (const pt &b) const {
        return x*b.y-y*b.x;
    }

};
vector<pt> cv;
int n;
ll Area(int i, int j, int k){
    return abs((cv[j]-cv[i])^(cv[k]-cv[i]));
}

inline int f(int x){
    if (x>=n) return x-n; return x;
}

signed main(){
    IOS();
    ll S; cin>>n>>S;
    vector<pt> v;
    for (int i = 0; i<n; i++){
        int x,y; cin>>x>>y;
        v.pb({x,y});
    }
    sort(ALL(v),[&](pt a, pt b){return a.x!=b.x?a.x<b.x:a.y<b.y;});

    vector<pt> stk;
    for (int i = 0; i<n; i++) {
        while (stk.size()>1) {
            if (((v[i]-stk.back()) ^  (stk[SZ(stk)-2]-stk.back())) <= 0) stk.pop_back();
            else break;
        }
        stk.pb(v[i]);
    }
    stk.pop_back();
    cv = stk;
    stk.clear();
    for (int i = n-1; i>=0; i--) {
        while (stk.size()>1) {
            if (((v[i]-stk.back()) ^  (stk[SZ(stk)-2]-stk.back())) <= 0) stk.pop_back();
            else break;
        }
        stk.pb(v[i]);
    }
    v.clear();
    stk.pop_back();
    for (auto x : stk) cv.pb(x);
#ifdef BALBIT
    for (auto x : cv) {
        bug(x.x,x.y);
    }
#endif
    n = SZ(cv);
    vector<int> ans = {-1,-1,-1};
    ll mxA = 0;
    for (int df = 1; df <= n/2; df++) {
        int k = 0+df;

        for (int i = 0; i<n; i++) {
            int j = f(i+df);
            if (f(k+1)==j) k = f(k+1);
            ll A = Area(i,j,k);
            while (f(k+1) != i && Area(i,j,f(k+1)) > A) {
                k=f(k+1);
                A = Area(i,j,k);
                if (A > mxA) {
                    mxA = A;
                    ans = {i,j,k};
                }
            }
        }
    }

    bug(ans[0],ans[1],ans[2]);
    for (int i = 0; i<3; i++) {
        pt P = (cv[ans[(i+2)%3]]-cv[ans[i]]);
        P = P +cv[ans[(i+1)%3]];
        cout<<P.x<<' '<<P.y<<endl;
    }
}
/*
5 10
0 0
0 2
2 0
2 2
1 1

*/