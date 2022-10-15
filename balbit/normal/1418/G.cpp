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

const int maxn = 1e6+5;

unsigned ll H[maxn][3];
int nof[maxn];

signed main(){
    IOS();
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin>>n;
    for (int i = 0; i< n; ++i) {
        H[i][0] = rng();
        H[i][1] = rng();
        H[i][2] = H[i][0] ^ H[i][1];
        bug(H[i][0], H[i][1]);
    }
    vector<int> a(n);
    vector<ull> h(n+1);
    vector<int> at(n);
    map<ull, int> mp;
    mp[0] = 1;
    int j = -1;
    ll re = 0;
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
        --a[i];
        h[i+1] = h[i] ^ H[a[i]][at[a[i]]];
        bug(h[i+1]);
        (++at[a[i]] ); at[a[i]] %= 3;
        ++nof[a[i]];
        while (nof[a[i]] > 3) {
            mp[h[++j]] --;
            nof[a[j]] --;
        }
        re += mp[h[i+1]];
        ++mp[h[i+1]];
    }
    cout<<re<<endl;
}