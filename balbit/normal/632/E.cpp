#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353 ;


void GG(){cout<<"No\n"; exit(0);}



ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}
const int maxn = 5e6+1;

const double PI = acos(-1.0);
#define cd complex<double>

void FFT(vector<cd> &a, bool rev=0){
    int n = SZ(a); 
    for (int i = 1, j = 0; i<n; i++){
        int bit = n>>1;
        while (j>=bit) j-=bit, bit>>=1; j+=bit;
        if (i<j) swap(a[i], a[j]);
    }
    for (int B = 2; B<=n; B*=2){
        double ang = 2 * PI / B * (rev?-1:1);
        cd w0 (cos(ang), sin(ang));
        for (int i = 0; i<n; i+=B){
            cd w (1,0);
            for (int j = 0; j<B/2; j++){
                cd u = a[i+j], v = w*a[i+j+B/2];
                a[i+j] = u+v, a[i+j+B/2] = u-v;
                w *= w0;
            }
        }
    }
    if (rev) REP(i,n) a[i] /= n;
}

vector<ll> mul (vector<ll> a, vector<ll> b){
    int n = 1; while (n < SZ(a) + SZ(b)) n*=2;
    vector<cd> x(n), y(n);
    REP(i, SZ(a)) x[i] = cd(a[i],0); REP(j, SZ(b)) y[j] = cd(b[j],0);
    FFT(x); FFT(y);
    REP(i, n) x[i] *= y[i];
    FFT(x,1);
    vector<ll> re(n);
    REP(i,n) re[i] = min((ll)(round(x[i].real())),1ll);
    while (re.size()>1 && re.back()==0) re.pop_back(); return re;
}

// template <typename Tod>
vector<int> mpow(vector<int> &a, ll n){ // a^n % mod
    vector<int> re={1};
    while (n>0){
        if (n&1) re = mul(re,a) ;
        a = mul(a,a);
        n>>=1;
    }
    return re;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int> poly(1001);
    REP(i,n){
        int x; cin>>x; poly[x] = 1;
    }
    while(SZ(poly)>1 && poly.back()==0) poly.pop_back();
    vector<int> c = mpow(poly,k);
    REP(i, SZ(c)){
        if (c[i]) cout<<i<<' ';
    }
}