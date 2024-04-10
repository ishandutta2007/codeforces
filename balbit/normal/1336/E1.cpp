#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll mod = 998244353;


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

const int maxn = 4e5+5;

ll basis[36];
int sz=0;

ll iV(ll mask) {
	for (int i = 0; i < 36; i++) {
		if ((mask & (1ll << i)) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			++sz;
			return mask;
		}
		mask ^= basis[i];
	}
	return mask;
}

ll dp[37][37][(1<<15)];

signed main(){
    IOS();
    int n,bm; cin>>n>>bm;
    ll n0 = 0;
    vector<ll> B;
    for (int i = 0; i<n; ++i) {
        ll x; cin>>x;
        ll to = iV(x);
        bug(to);
        if (to == 0) ++n0;
    }
    for (int i = 0; i<36; ++i) {
        if (basis[i]) for (int j = 0; j<36; ++j) {
            if (j != i && (basis[j] & (1ll<<i)) > 0) {
                basis[j] ^= basis[i];
            }
        }
    }
    for (int i = 0; i<13; ++i) {
        bug(basis[i]);
    }

    vector<ll> ans(bm+1+100);
    for (int i = 0; i<36; ++i) {
        if (basis[i]) {
            B.pb(basis[i]);
        }
    }
    if (sz <= 21) {
//        assert(SZ(B) == sz);
        for (int msk = 0; msk < (1<<sz); ++msk) {
            ll xx = 0;
            for (int i = 0; i<sz; ++i) {
                if (msk & (1ll<<i)) {
                    xx ^= B[i];
                }
            }
            ans[__builtin_popcountll(xx)] ++;
        }

    }else{
//        cout<<"HI"<<endl; return 0;
        vector<int> tk(36);
        vector<ll> lft(36);
        for (int i = 0; i<36; ++i) {
            if (basis[i]) tk[i] = 1;
        }
        dp[0][0][0] = 1;
        int prv = 0;
        int biglft = bm - sz + 1;
        for (int i = 0; i<36; ++i) {
            if (basis[i]) {
                for (int j = 0; j<bm; ++j) {
                    if (!tk[j]) {
                        lft[i] *= 2; lft[i] += ((basis[i] & (1ll<<j)) != 0);
                    }
                }
                for (int j = 0; j<=bm; ++j) {
                    for (int msk = 0; msk < (1ll<<(biglft)); ++msk) {
                        dp[i+1][j][msk] = (j?dp[prv][j-1][msk ^ lft[i]]:0) + dp[prv][j][msk];
                        if (dp[i+1][j][msk] >= mod) dp[i+1][j][msk] -= mod;
                    }
                }
                prv = i+1;
            }
        }
        for (int j = 0;j<=bm;++j) {
            for (int msk = 0; msk < (1ll<<biglft); ++msk) {
                ans[j+__builtin_popcountll(msk)] = (ans[j+__builtin_popcountll(msk)] + dp[prv][j][msk])%mod;

            }
        }
    }

//    for (int m = 0; m < 36; ++m) {
//        ans[__builtin_popcount(m)] = (ans[__builtin_popcount(m)] + dp[prv][m]) % mod;
//    }
    ll bp = mpow(2, n0);
    for (int i = 0; i<=bm; ++i) {
        cout<<(ans[i] * bp) % mod<<' ';
    }

}