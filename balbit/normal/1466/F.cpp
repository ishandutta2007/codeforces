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

int par[maxn];
bool ok[maxn];

int find(int x) {
    return x==par[x]?x:par[x]=find(par[x]);
}

signed main(){
    IOS();
    int m,n; cin>>m>>n;
    REP(i,n) par[i] = i;
    vector<int> re;
    REP(i,m) {
        int k; cin>>k;
        if (k == 1) {
            int a; cin>>a; --a;
            int A = find(a);
            if (ok[A]) continue;
            ok[A]=1;re.pb(i+1);
        }else{
            int a,b; cin>>a>>b; --a; --b;
            int A = find(a), B = find(b);
            if (A==B || (ok[A] && ok[B]) ){
                continue;
            }
            par[A] = B;
            ok[B] |= ok[A];
            re.pb(i+1);
        }
    }
    cout<<mpow(2,SZ(re))<<' '<<SZ(re)<<endl;
    for (int y : re) cout<<y<<' ';


}