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

const int maxn = 3e3+5;

vector<int> a[maxn];
ll w[maxn], v[maxn];

int n,k;

ll re = 0;

void dfs(int l, int r, vector<ll> bk) {
    if (l == r) {
        ll vs = 0;
        for (int i = 1; i<k; ++i) {
            bk[i] = max(bk[i], bk[i-1]);
        }
        for (ll i = 0; i<min(k,SZ(a[l])); ++i) {
            vs += a[l][i];
            re = max(re, vs + bk[k-i-1]);
            bug(l, i, vs+bk[k-i-1]);
        }
        return;
    }
    vector<ll> npk = bk;
    ll mid = (l+r)/2;
    for (int i = l; i<=mid; ++i) {
        for (int j = k-1; j>=0; --j) {
            if (j-w[i] < 0) break;
            npk[j] = max(npk[j], npk[j-w[i]] + v[i]);
        }
    }
    dfs(mid+1, r, npk);
    npk = bk;
    for (int i = mid+1; i<=r; ++i) {
        for (int j = k-1; j>=0; --j) {
            if (j-w[i] < 0) break;
            npk[j] = max(npk[j], npk[j-w[i]] + v[i]);
        }
    }
    dfs(l, mid, npk);
}

signed main(){
    IOS();

    cin>>n>>k;
    for (int i = 0; i<n; ++i) {
        int t; cin>>t;
        w[i] = t;
        for (int j = 0; j<t; ++j) {
            int x; cin>>x;
            a[i].pb(x);
            v[i] += x;
        }
    }

    vector<ll> tmp(k, 0);
    dfs(0,n-1, tmp);
    cout<<re<<endl;
}