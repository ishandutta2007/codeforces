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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e6+5;

inline ll ev(int x, int y, int z) {
    return (x-y) * (ll)(x-y) + (x-z) * (ll)(x-z) + (z-y) * (ll)(z-y);
}

ll ans(vector<int> &A, vector<int> &B, vector<int> &C, int a, int b, int c) {
    int j = 0, k = 0 , k2=0;
    ll re = 3e18+5;
    for (int i = 0; i<a; ++i) {
        while (k2+1 < c && C[k2+1] <= A[i]) ++k2;
        while (j +1 < b && B[j+1] <= min(C[k2], A[i])) ++j;
        if (B[j] > A[i] || B[j] > C[k2]) continue;
        while (k+1 < c && ev(A[i], B[j], C[k+1]) <= ev(A[i], B[j], C[k])) {
            ++k;
        }
        re = min(re, ev(A[i], B[j], C[k]));
    }
    return re;
}

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        array<int, 3> n; cin>>n[0]>>n[1]>>n[2];
        array<vector<int>, 3> A;
        for (int i = 0; i<3; ++i) A[i].resize(n[i]);
        for (int i = 0; i<3; ++i) {
            for (int j = 0; j<n[i]; ++j) {
                cin>>A[i][j];
            }
            sort(ALL(A[i]));
        }
        ll re = 3e18 + 5;
        for (int i1 = 0; i1<3; ++i1) {
            for (int i2 = 0; i2<3; ++i2) {
                if (i1!=i2) {
                    int i3 = 1+2-i1-i2;
                    re = min(re, ans(A[i1], A[i2], A[i3], n[i1], n[i2], n[i3]));
                }
            }
        }
        cout<<re<<endl;
    }



}