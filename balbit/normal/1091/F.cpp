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

const int maxn = 1e6+5;


signed main(){
    IOS();
    bool wat = 0;
    int n; cin>>n;
    vector<ll> L(n); for (int i = 0; i<n; ++i ) cin>>L[i];
    string s; cin>>s;
    ll lava = 0;
    ll wfree =0, gfree=0; // two times the number of free water or grass available
    ll stam = 0;
    ll re = 0;
    for (int i =0 ; i<n; ++i) {
        if (s[i] == 'W') {
            wat = 1;
            re += L[i] * 3;
            stam += L[i];
            wfree += L[i];
        }
        if (s[i] == 'G') {
            re += L[i] * 5;
            stam += L[i];
            if (wfree) {
                int trans = min(wfree, L[i]);
                gfree += trans*2;
                wfree -= trans;
                L[i] -= trans;
            }
            gfree += L[i];
        }
        if (s[i] == 'L') {
            re += L[i];
            ll mo = min(L[i], stam);
            L[i] -= mo; stam -= mo;
            wfree -= mo;
            if (wfree < 0) {
                gfree += wfree;
                wfree = 0;
            }
            if (L[i] > 0) {
                if (wat) {
                    re += 3*L[i];
                }else{
                    re += 5*L[i];
                }
            }
        }
        if (!stam) {
            wfree = gfree = 0;
        }
    }
    bug(re, stam, gfree, wfree);
    if (stam) {
//        stam /= 2;
        bug(gfree, wfree);
        re -= gfree * (5-1)/2 + wfree * (3-1)/2;

    }
    cout<<re<<endl;
}