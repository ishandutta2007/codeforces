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

const int maxn = 1e3+5;

#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)


int last[500*500+1];

vector<int> go(vector<int> v, int T) {
    bug("lego", T);
    memset(last, -1, 4 * (T+2));
    bitset<500*500+1> ok; ok[0] = 1;
    REP(i, SZ(v)) {
        ok |= ok << v[i];
        REP1(j, T) {
            if (ok[j] && (last[j]==-1) ) {
                last[j] = i;
            }
        }
        if (ok[T]) {
            break;
        }
    }
    if (!ok[T]) {
        return {};
    }else{
        vector<int> re(SZ(v));
        for (int x = T; x != 0; x -= v[last[x]]) {
            bug(last[x]);
            bug(v[last[x]]);
            re[last[x]] = 1;
        }
        return re;
    }
}

signed main(){
    IOS();
    bug(sizeof (int));
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n;
        int H = 0, V = 0;
        vector<int> h(n);
        REP(i,n) {
            cin>>h[i]; H += h[i];
        }
        cin>>m;
        vector<int> v(m);
        REP(i,m) cin>>v[i], V += v[i];
        if (n != m || H &1 || V&1) {
            cout<<"No"<<endl; continue;
        }
        H/=2; V/=2;

        vector<int> ha = go(h, H);
        vector<int> va = go(v, V);
        if (!SZ(ha) || !SZ(va)) {
            cout<<"No"<<endl; continue;
        }
        int s1 = 0, s2 = 0;
        for (int x : ha) s1 += x;
        for (int x : va) s2 += x;
        if (s1 > n/2) for (int &x : ha) x ^= 1;
        if (s2 <= n/2) for (int &x : va) x ^= 1;
        vector<int> h1, v1;
        auto cmp = [&] (int a, int b) {
            return a>b;
        };
        {
            vector<int> h2;
            REP(i,n) {
                (ha[i]?h2:h1).pb(h[i]);
            }
            sort(ALL(h1));
            sort(ALL(h2));
            for (int x : h2) h1.pb(-x);
        }
        {
            vector<int> h2;
            REP(i,n) {
                (va[i]?h2:v1).pb(v[i]);
            }
            sort(ALL(v1), cmp);
            sort(ALL(h2), cmp);
            for (int x : h2) v1.pb(-x);
        }
        int x=0,y=0;
        cout<<"Yes\n";
        REP(i,n){
            y += v1[i]; cout<<x<<' '<<y<<'\n';
            x += h1[i]; cout<<x<<' '<<y<<'\n';
        }
    }


}