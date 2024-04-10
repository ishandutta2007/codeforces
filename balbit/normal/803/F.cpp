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

int mo[maxn];
bool np[maxn];

void build(){
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            // is prime
            mo[i] = -mo[i];
            for (int j = i+i; j<maxn; j+=i) {
                mo[j] = -mo[j];
                np[j] = 1;
            }
            for (int j = i*i; j<maxn; j+=i*i) {
                mo[j] = 0;
            }
        }
    }
}

int hv[maxn];

signed main(){
    IOS();
    int n; cin>>n;

    fill(mo, mo+maxn, 1);
    build();
    for (int i = 0; i<n; ++i) {
        int x; cin>>x;
        for (int s = 1; s<=sqrt(x); ++s) {
            if (x%s == 0) {
                hv[s]++;
                if (s*s!=x)
                    hv[x/s]++;
            }

        }
    }
//    mo[1]=-mo[1];
    ll re = 0;
    for (int i = 1; i<maxn; ++i) {
        if (hv[i])
            re += (mpow(2, hv[i])-1) * mo[i] % mod;
        if (re < 0) re += mod;
    }
    cout<<(re % mod+mod)%mod<<endl;


}