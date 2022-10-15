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

const int maxn = 1e6+5;
bool seen[maxn];
map<int, int> mp;
int n2=0;
void gt(vector<int> a){
    int n = SZ(a);
    REP(i,n) {
        if (!seen[i]) {
            int len = 0;
            for (int j = i; !seen[j]; j = a[j]) {
                seen[j] = 1; len++;
            }
           mp[len]++;
           n2 += len/2;
        }
    }
//    sort(ALL(re));
//    return re;
}
bitset<maxn> bs;
signed main(){
    IOS();
    int n,k; cin>>n>>k;
    bs[0] = 1;
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i]; --a[i];
    }
    gt(a);
    bug(n2);
    for (auto p : mp) {
        bug(p.f, p.s);
        int y;
        for ( y = 1; y<=p.s; y*=2) {
            p.s -= y;
            bs |= (bs << (p.f * y));
        }
        if (p.s) {
            bs |= (bs << (p.f * p.s));
        }
    }
    if (bs[k]) {
        cout<<k<<' ';
    }else{
        cout<<k+1<<' ';
    }
    int tot = 0;
    while (n2>0 && k > 0) {
        n2--; k--; tot+=2;
    }
    if (k > 0) tot += k;
    cout<<min(tot,n)<<endl;

}