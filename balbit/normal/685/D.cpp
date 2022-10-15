#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

map<int, vector<pii> > mp;
//gp_hash_table<int, int> val;
int val[30000005];
int nownum[maxn];
ll re [maxn];



signed main(){
    IOS();

    int n,k; cin>>n>>k;
    vector<int> stuffs; stuffs.reserve(30000001);
    for (int i = 0; i<n; ++i) {
        int X,Y;
        cin>>X>>Y;
        mp[X].pb({Y, 1});
        mp[X].pb({Y+k, -1});
        mp[X+k].pb({Y, -1});
        mp[X+k].pb({Y+k, +1});
        for (int j = Y; j<Y+k; j++) {
            stuffs.pb(j);
        }
    }
    SORT_UNIQUE(stuffs);
    int prevx = 0;
    int biggest = 0;
    for (auto & stuff : mp) {
        int xp = stuff.f;
        while (biggest > 0 && nownum[biggest] == 0) --biggest;
        for (int j = 1; j<=biggest; ++j) {
            re[j] += nownum[j] * (xp - prevx);
//            if (j==1) bug(xp, re[j]);
        }
//        biggest = 0;
        vector<pii> &upd = stuff.s;
        sort(ALL(upd));
        int nowsum = 0;
        int last = -1000000001;

        for (auto & p : upd) {
            if (nowsum) {
                int lv = lower_bound(ALL(stuffs), last) - stuffs.begin();
                for (; last < p.f; ++last, ++lv) {

                    if (val[lv] > 0) nownum[val[lv]]--;
                    val[lv] += nowsum;
                    if (val[lv] > 0){
                        nownum[val[lv]]++;
                        MX(biggest, val[lv]);
                    }
//                    if (val[lv] == 0)
//                        val.erase(lv);
                }
            }
            last = p.f;
            nowsum += p.s;
        }
        prevx = xp;
//        bug("layer", prevx);
//        for (int i = 1; i<=n; ++i) {
//            cout<<nownum[i]<<' ';
//        }
//        cout<<endl;
    }
    for (int i = 1; i<=n; ++i) {
        cout<<re[i]<<' ';
    }
}