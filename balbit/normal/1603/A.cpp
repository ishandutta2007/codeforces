#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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

const int maxn = 5e5+5;

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {

        int n; cin>>n;
        vector<int> a(n);
        vector<int> need(n);
        queue<int> ok;
        set<pii> hm;bool dead = 0;
        REP(i,n) {
            cin>>a[i];
            while (a[i]%(i+2-need[i]) == 0) {
                ++need[i];
                if (i-need[i] < 0) {
                     dead = 1;
                     break;
//                    cout<<"NO"<<endl;
                }
            }
            bug(i, need[i]);
            if (need[i]) {
                hm.insert({i, need[i]});
            }else ok.push(i);
        }
        if (dead) {
            cout<<"NO"<<endl; continue;
        }
        while (!ok.empty()) {
            int t = ok.front(); ok.pop();
            auto it = hm.end();
            if (it == hm.begin()) continue;
            it--;
            vector<pii> toad;
            while (1) {
                if (it->f > t) {
                    pii to = {it->f, it->s-1};
                    if (to.s == 0) {
                        ok.push(it->f);
                    }else{
                        toad.pb(to);
                    }
                    it = hm.erase(it);
                    if (it == hm.begin()) break;
                    it--;
                }else break;
            }
            for (pii p: toad) hm.insert(p);

        }


        if (hm.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;




        die:;

    }

}