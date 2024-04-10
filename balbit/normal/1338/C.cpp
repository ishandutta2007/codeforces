#include <bits/stdc++.h>
#undef BALBIT
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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e6+5;

void b4(vector<int> &re, ll x, int len){
    while (len--) re.pb(x%4), x/=4;
    reverse(re.begin()+1, re.end());
}
ll ans(vector<int> x) {
    ll re = 0;
    for (int y : x) {
        re *= 4; re += y;
    }
    return re;
}

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        ll n; cin>>n; --n;
        ll N = n/3;
        int len = 0;
        for (len = 0;N>=pow(4,len);++len) {
            N -= pow(4,len);
        }
        bug(len);
        vector<int> s = {n%3+1};
        b4(s,N,len);
        bug(SZ(s));

        if (n % 3 == 0) {
            s[0] = 1;

        }
        if (n % 3 == 1) {
            vector<int> tmp = {0,2,3,1};
            s[0] = 2;
            for (int i = 1; i<s.size(); ++i) {
                s[i] = tmp[s[i]];
            }
        }
        if (n % 3 == 2) {
            vector<int> tmp = {0,3,1,2};
            s[0] = 3;
            for (int i = 1; i<s.size(); ++i) {
                s[i] = tmp[s[i]];
            }
        }
        cout<<ans(s)<<endl;

    }


}