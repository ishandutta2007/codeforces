#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//#define int ll
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
const int BS = 200;

ll bck[10000000];
int cnt[100005 * 2];
int cnt2[BS * maxn * 2];

signed main(){
    IOS();

    for (int i = 1; i * (i-1) / 2 < 10000000; ++i) {
        bck[i*(i-1)/2] = i;
    }

//    clock_t t = clock();

    int n; cin>>n;
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i];
//        a[i] = rand() % 100000 + 1;

//        a[i] = 2222;
    }

    ll re = 1;

    for (int d = -BS; d <= BS; ++d) {
//        vector<int> tmp;
        if (d > 0) {
            REP(i,n) {
                MX(re, ++cnt2[a[i]+d*i]);
            }
            REP(i,n) {
                --cnt2[a[i]+d*i];
            }
        }else{
            REP(i,n) {
                MX(re, ++cnt2[maxn-a[i]-d*i]);
            }
            REP(i,n) {
                --cnt2[maxn-a[i]-d*i];
            }
        }

        bug(d);
    }


    int sec = (100002 / BS + 1) * 2;

    for (int s = 0; s < n; s += sec/2) {
        int l = s, r = min(n, s + sec+10);
//        vector<int> tmp;
//        memset(cnt, 0, sizeof cnt);
        for (int i = l; i<r; ++i) {
            int ha = 0;
            for (int j = l; j<i; ++j) {
                if ((a[j] - a[i]) % (j-i) == 0) {
                    MX(ha, ++cnt[((a[j] - a[i]) / (j-i)) + maxn]);
                }
            }
            for (int j = l; j<i; ++j) {
                if ((a[j] - a[i]) % (j-i) == 0) {
                    --cnt[((a[j] - a[i]) / (j-i)) + maxn];
                }
            }
            MX(re, ha+1);
        }
//        bug(ha);
//        assert(bck[ha] != 0);
//
//        MX(re, bck[ha]);
//        bug(s);
    }

    cout<<n-re<<endl;
//    bug((clock() - t) / (double)CLOCKS_PER_SEC);


}