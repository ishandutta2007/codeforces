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
const ll mod = 998244353ll;


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

ll omega[maxn];

void ntt(vector<ll> &a, bool rev) {
    int n = SZ(a);
    assert(__builtin_popcount(n)==1);
    for (int i = 1, j = 0; i < n; ++i) {
        for (int bit = n/2; bit >= 1; bit /= 2) {
            if ((j & bit) == 0) {
                j += bit; break;
            }
            j -= bit;
        }
        bug(i,j);
        if (i > j) swap(a[i], a[j]);
    }

    for (int B = 2; B <= n; B *= 2) {
        ll w0 = mpow(3, (mod-1)/B);
        if (rev) w0 = inv(w0);
        for(int i = 0; i<n; i += B) {
            ll w = 1;
            for (int j = 0; j<B/2; ++j) {
                ll u = a[i+j], v = a[i+j+B/2] * w % mod;
                a[i+j] = (u+v>=mod?u+v-mod:u+v);
                a[i+j+B/2] = (u-v<0?u-v+mod:u-v);

                w *= w0; w %= mod;
            }
        }
    }

    if (rev) {
        ll in = inv(n);
        REP(i,n) a[i] = a[i] * in % mod;
//        reverse(a.begin()+1, a.end());
    }
}

vector<ll> ntt(vector<ll> &a, vector<ll> &b) {
    ll n = 1;
    while (n < SZ(a) + SZ(b)) n *= 2;
    while (SZ(a) < n) a.pb(0);
    while (SZ(b) < n) b.pb(0);

    ntt(a, 0); ntt(b, 0);
    REP(i,n) {
        bug(a[i], b[i]);
        a[i] *= b[i]; a[i] %= mod;
    }

    ntt(a, 1);
//    REP(i,n) {
//        bug(i, a[i]);
//    }

    return a;
}

ll A[maxn*2], B[maxn*2], C[maxn*2];

void onlinefft(int l, int r) {

    // work with the range [l...r], making C[i+j] = sum prod (A[i] * B[j], s.t. i > j)

    if (r - l < 30) {
        // just brute
        for (int i = l; i<=r; ++i) {
            for (int j = l; j<i; ++j) {
                C[i+j] += A[i] * B[j] % mod;
            }
        }
        return;
    }
    vector<ll> a, b;
    int mid = (l+r)/2;

    for (int i = l; i<=r; ++i) {
        if (i>mid) a.pb(A[i]);
        else b.pb(B[i]);
    }

    vector<ll> yoi = ntt(a,b);
    REP(i, SZ(yoi)) {
        C[i + mid+1 + l] += yoi[i];
    }

    onlinefft(l, mid); onlinefft(mid+1,r);
}

ll ps[maxn];
ll sumA[maxn], sumB[maxn];

signed main(){
    IOS();

//    vector<ll> a = {3,1};
//    vector<ll> b = {1, 2, 10};
//    vector<ll> c = ntt(a,b);
//    for (int x : c) {
//        bug(x);
//    }
    int n, m; cin>>n>>m;
    vector<ll> wei(n+1); // one based!!
    REP1(i,n) cin>>wei[i];

    REP(i,m) {
        int x; cin>>x;
        ps[x]++;
    }
    REP(i,n+1) {
        if (i) ps[i] += ps[i-1];
        B[i] = mpow(2, ps[i]);
        A[i] = inv(B[i]);
    }

    onlinefft(0, n);

    for (int i = n; i>=1; --i) {
        sumA[i] = (A[i] + sumA[i+1]) % mod;
    }

    for (int i = 0; i<=n; ++i) {
        sumB[i] = ((i?sumB[i-1]:0) + B[i]) % mod;
    }

    ll re = 0;

    ll ivbn = inv(B[n]-1); // to scale back
    bug(B[n]);

    REP1(i,n) {
        int dst = min(i-1, n-i);
        int L = i-dst, R = i+dst;
        ll tot;
        if (L == 1) {
            // case R
            tot = (C[i + i-1] + sumA[R+1]) % mod;
            bug(i, C[2*i-1], sumA[R+1], tot * 4 % mod, "case R");
        }else{
            tot = (C[i+ i-1]  + sumB[L-2] * A[n]) % mod;
            bug(i, C[2*i-1], sumB[L-2], tot*4 % mod, "case L");
        }
        ll far = max(i-1, n-i) + 1; // how much the "nothing case" is counted
        tot = tot * B[n];
        tot -= far;   // minus 2^-m * far
        tot %= mod; if (tot < mod) tot += mod;
        tot = tot * ivbn % mod;
        bug(tot, tot* 12ll % mod);
//        tot --; // expected value should not be that big
        re += tot * wei[i] % mod;
    }

    bug(re * 3 % mod);
//    re = re * inv(B[n]-1) % mod;
    cout<<re % mod<<endl;




}