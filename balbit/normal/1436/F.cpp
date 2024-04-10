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
const ll MOD = 998244353;


void GG(){cout<<"0\n"; exit(0);}


const int maxn = 1e5+5;

vector<pii> here[maxn];

template <ll mod>
struct Modint{
    ll val;
    Modint(ll _val=0){val=_val;}
    operator ll() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(ll b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, ll b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define mint Modint<MOD>
mint mpow(mint a, ll n, ll mo = MOD){ // a^n % MOD
    mint re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

mint inv (ll b, ll mo = MOD){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const mint i4 = inv(4);
const mint i2 = inv(2);

mint go(ll x) {
    bug(x);
    mint oth2 = 0;
    mint oth1 = 0;
    mint oth0 = 1;
    mint siga = 0;
    ll sigf = 0;

    for (pii & p : here[x]) {
        mint a = p.f, f = p.s;
        mint mf = mpow(2,f);
        oth2 = mf * oth2 + oth0 * a * a * mf * i4 * f * (f+(mint)1) + oth1 * (mint)2 * a * mf * i2 * f;
        siga += a*f; sigf += f; sigf %= (MOD-1);
        mint m2 = mpow(2,sigf);
        oth1 = siga * m2 * i2;
        oth0 = m2;
    }
    mint mpowsigf = mpow(2,sigf);
    bug(oth2, oth1, oth0);
    mint re = 0;
    for (pii & p : here[x]) {
        mint a = p.f, f = p.s;
        mint have1 = siga * mpowsigf * i4 + a * mpowsigf * inv(4);
        mint two = a*a*mpowsigf*i2+oth2+oth1*(mint)2*a- (mint)2 * a * have1;
        two *= i2;
        bug(two);
        re += two * f;
    }

    bug(re);
    return re - oth2;
}

int mob[maxn];
bool np[maxn];

signed main(){

    IOS();


    int n; cin>>n;
    for (int i = 0; i<n; ++i) {
        int a,f; cin>>a>>f;
        for (int j = 1; j<=sqrt(a); ++j) {
            if (a%j == 0) {
                here[j].pb({a,f});
                if (j*j != a) {
                    here[a/j].pb({a,f});
                }
            }
        }
    }
    fill(mob, mob+maxn-1, 1);
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            mob[i] = -1;
            for (int j = i+i; j<maxn; j += i) {
                mob[j] = -mob[j]; np[j] = 1;
            }
            if (i * i <= maxn)
                for (int j = i*i; j<maxn; j+= i*i) {
                    mob[j] = 0;
                }
        }
    }
    ll re = 0;
    for (int i = 0; i<maxn; ++i) {
//        bug(i, mob[i]);
        if (mob[i] && SZ(here[i])) {
            re += mob[i] * go(i);
            re %= MOD;
        }
    }
    cout<<(re+MOD)%MOD <<endl;


}