#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast", "unroll-loops")
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

vector<int> pf[maxn];
bitset<65> tch[maxn];
unordered_map<bitset<65>, int> mp;

const int maxtp=15000;
bitset<65> bat[maxtp];
ll bst[maxtp];
ll b2[maxtp];
ll bstp[maxtp];

const int SQUU = sqrt(100000);

bool here[100005];

signed main(){
    IOS();
    int nofsmol = 0;
    for (int i = 2; i<=(100000); ++i) {
        if (SZ(pf[i]) == 0) {
            for (int j = i; j<=100000; j += i) {
                pf[j].pb(i);
                if (i <= SQUU)
                tch[j][nofsmol] = 1;
            }
            if (i <= SQUU)
                ++nofsmol;
        }
    }
    int hi = 0;
    for (int i = 2; i<= 100000; ++i) {
        if (!mp.count(tch[i])) {
            mp[tch[i]] = hi;
            bat[hi] = tch[i];
            ++hi;
        }
    }
    bug(nofsmol);
    bug(SZ(mp));
    int n; cin>>n;
    vector<int> a;
    REP(i,n) {
        int x; cin>>x; here[x] = 1;
    }
    for (int i = 2; i<=100000; ++i) {
        for (int j = i; j<=100000; j +=i ) {
            if (here[j]) {a.pb(i); break;}
        }
    }
    SORT_UNIQUE(a);
    reverse(ALL(a));
    n = SZ(a);
    if (n == 0) {
        cout<<1<<endl; return 0;
    }
    REP(i, maxtp) bstp[i] = -i-1;
    ll re = a[0];
    for (int i = 0; i<n; ++i){
        int A = a[i]; if (A==1) continue;
        int me = mp[tch[A]];
        if (pf[A].back() > SQUU) {
            if (bst[me] == 0) {
                bst[me] = A; bstp[me] = pf[A].back();
            }else if (b2[me] == 0 && bstp[me] != pf[A].back()) {
                b2[me] = A;
            }
        }else{
            if (bst[me] == 0) {
                bst[me] = A;
            }else if (b2[me] == 0) {
                b2[me] = A;
            }
        }
        if (tch[A] == 0) {
            MX(re, bst[me] * b2[me]);
        }
    }
    bug("HI");

    for (int i = 0; i< hi; ++i) {
        for (int j = 0; j<i; ++j) {
            if (bst[i] * (ll) bst[j] > re) {
                if ((bat[i] & bat[j]) == 0) {
                    if (bstp[i] != bstp[j]) MX(re, bst[i] * (ll) bst[j]);
                    else {
                        MX(re, bst[i] * (ll) b2[j]);
                        MX(re, b2[i] * (ll) bst[j]);
                    }
                }
            }
        }
    }
    cout<<re<<endl;
}