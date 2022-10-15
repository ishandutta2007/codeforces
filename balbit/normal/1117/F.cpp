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

const int maxn = 1e5+5;


bool bad[17][17][1<<17];
bool A[17][17];
int nof[17];
bool ok[1<<17];
int v[maxn];

signed main(){
    IOS();
    int n,p; cin>>n>>p;
    for (int i = 0; i<n; ++i) {
        char c; cin>>c;
        v[i] = c-'a';
//        bug(i, v[i]);
        ++nof[v[i]];
    }
    for (int i = 0; i<p; ++i) for (int j = 0; j<p; ++j) cin>>A[i][j];
    for (int i = 0; i<p; ++i) {
        for (int j = i; j<p; ++j) {
            if (!A[i][j]) {
                int M = -1;
                int last = -1;
                for (int k = 0; k<n; ++k) {
                    if (v[k] == i || v[k] == j) {
                        if (M != -1) {
//                            bug(i,j,M);
                            if (last != v[k] || i==j) bad[i][j][M] = 1;
                        }
                        last = v[k];
                        M = 0;
                    }else{
                        if (M != -1) M |= (1<<v[k]);
                    }
                }
                for (int msk = 1; msk <(1<<p); ++msk) {
                    for (int it = 0; it<p; ++it) {
                        if (msk&(1<<it)) {
                            bad[i][j][msk] |= bad[i][j][msk ^ (1<<it) ];
                        }
                    }
//                    if (bad[i][j][msk]) {
//                        bug(i,j,msk);
//                    }
                }
            }
        }
    }
    int re = 0;
    for (int msk = 0; msk < (1<<p); ++msk) {
        // Test for bad state
        bool flag = 1;
        for (int i = 0; i<p; ++i) {
            for (int j = i; j<p; ++j) {
                if (!(msk & (1<<i)) && !(msk & (1<<j))) {
                    if (bad[i][j][msk]) {
                        flag = 0; break;
                    }
                }
            }
        }
        if (!flag) continue;
//        bug(msk, flag);

        if (msk) {
            flag = 0;
            for (int i = 0; i<p; ++i) {
                if (msk & (1<<i)) {
                    flag |= ok[msk ^ (1<<i)];
                }
            }
        }

        if (flag) {
            ok[msk] = 1;
            int ans = 0;
            for (int i = 0; i<p; ++i) {
                if (msk & (1<<i)) ans += nof[i];
            }
            bug(msk, ans);
            re = max(re, ans);
        }

    }
    cout<<n-re<<endl;


}