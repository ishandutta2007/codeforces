#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
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
#ifdef BALBITe
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

#define ll __int128

ll MO;

void ass(bool x){
    if (!x) while(1);
}

inline ll divv(ll a, ll b) {
    return a/b - ((a^b)<0 && a%b);
}
pii exgcd(ll a, ll b) {
    if (a==0) {
        ass(b==1);
        return {0,1};
    }else{
        pii tmp = exgcd(b%a,a);
        return {((tmp.s-divv(b,a)*tmp.f)%MO+MO)%MO , (tmp.f)};
    }
}


signed main(){
    IOS();
//    pii tmp = exgcd(3,5);
//    bug(tmp.f, tmp.s);
    ll a1, b1, a2, b2, l, r;
    long long A1, B1, A2, B2, L, R;
    cin>>A1>>B1>>A2>>B2>>L>>R;
    a1=A1;b1=B1;a2=A2;b2=B2;l=L;r=R;
    ll g = __gcd(a1, a2);
    ll B = b2-b1;
//    if (g != 1) ass(0);
    if (B % g != 0) GG();
    a1 /= g; a2 /=g; B /=g;
    MO = a1*a2;

    pii S = exgcd(a1, (-a2+MO) % MO);
    bug(S.f, S.s);
    bug((-a2+MO) % MO);
    (S.f *= B) %= MO;
    if (S.f<0) S.f += MO;
    (S.s *= B) %= MO;
    if (S.s<0) S.s += MO;
    bug(S.f, S.s);

    MO *= g;
    ll start = (a1*g%MO * S.f + b1) % MO;
    ll s2 = (a2 * g % MO * S.s + b2) % MO;
    if (start < 0) start += MO;
    if (s2 < 0) s2 += MO;
    bug(start, s2);

    assert(start == s2);
    l = max(l, max(a1*g*0+b1, a2*g*0+b2));
//    r = max(r, a2*g*0+b2);
    ll getr = divv((r-start) , MO) + 1;
    ll getl = divv((l-1-start) , MO) + 1;
    cout<<(long long)max(getr-getl,(ll)(0))<<endl;
}