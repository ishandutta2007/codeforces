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

const int maxn = 1e6+5;

ll fac[maxn], ifac[maxn];

void build(){
    fac[0]=ifac[0]=1;
    for (int i = 1; i<maxn; ++i) fac[i] = fac[i-1] * (ll)i % mod, ifac[i] = inv(fac[i]);

}

ll C(int a, int b) {
    if (a == -1 && b == -1) return 1;
    if (b > a || b < 0 || a<0) return 0;
    return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

ll f(int L, int c00, int c01, int c10, int c11, bool bef = 0) {
    if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return 0;
    // To include the previous bit
    ++L;
    int n1 = c01 + c11+ (bef == 1), n0 = c00 + c10+ (bef==0);
    if (L != n1 + n0) {
        bug("wot");
        return 0;
    }
    int chg = bef + c01 - c10;
    if (chg < 0 || chg > 1) {
        return 0;
    }
    int por1 = c01 + (bef == 1), por0 = c10 + (bef==0);
    // porX is the number of portions X will be split into
    ll CC = C(n1-1, por1-1) * C(n0-1, por0-1) % mod;
    bug(L, CC, n1, por1, n0, por0);
    return CC;
}

ll gt(vector<int> &x, array<array<int, 2>,2> c) {



    int n = SZ(x);
    ll re = 0;
    if (c == array<array<int, 2>,2>{{{0,0},{0,0}}} && SZ(x) > 1) {
        re ++;
    }
    // Case 1: Following w/out leading zeroes
    {
        array<array<int, 2>,2> b = c;
        for (int i = 1; i<n; ++i) {
            if (x[i] == 1) {
                // decrease
                b[x[i-1]][0]--;
                re = re + f(n-i-1, b[0][0], b[0][1],b[1][0],b[1][1],0);
                re %= mod;
                b[x[i-1]][0]++;
            }
            b[x[i-1]][x[i]]--;
        }
    }
    // Case 2: Leading zeroes
    {
        for (int L = n-2; L > 0; -- L) {
            re += f(L, c[0][0], c[0][1], c[1][0], c[1][1], 1);
            re %= mod;
        }
    }
    bug(re);
    return re;
}

bool isok(vector<int> &x, array<array<int, 2> , 2 > c) {
    for (int i = 1; i<SZ(x); ++i) {
        c[x[i-1]][x[i]]--;
    }
    array<array<int, 2> , 2 > d = {{{0,0},{0,0}}};
    return c == d;
}

signed main(){
    IOS();
    build();
    string ra, rb; cin>>ra>>rb;
    vector<int> a,b;
    for (char c : ra) a.pb(c-'0');
    for (char c : rb) b.pb(c-'0');
    array<array<int, 2> , 2 > c;
    for (int i = 0; i<2; ++i) for (int j = 0; j<2; ++j) cin>>c[i][j];
    ll re = gt(b,c) - gt(a,c);
    bug(isok(a,c));
    re += isok(b,c);
    re = (re + 2*mod) % mod;
    cout<<re<<endl;

}