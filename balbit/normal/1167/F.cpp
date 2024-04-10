#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

struct BIT{
    vector<ll> s;
    int MX=0;
    ll QU(int e){
        ll re = 0; e ++;
        while (e>0) {
            re+=s[e]; e-=e&(-e);
        }return re;
    }
    void MO(int e, ll v){
        e++; while (e<MX){
            s[e]+=v; e+=e&(-e);
        }
    }
    BIT(int _mx){
        MX = _mx; s.resize(MX+1);
    }
};

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<ll> a(n);
    map<ll, int> imat;
    REP(i,n) cin>>a[i], imat[a[i]] = i;
    vector<ll> b = a; 
    sort(ALL(b));
    BIT fo ( n+1) ; BIT nele(n+1);
    ll re = 0;
    REP(i,n){
        ll at = imat[b[i]];
        // cout<<at<<" : ";
        ll sm = fo.QU(at-1)%mod;
        ll sf = (fo.QU(n-1) - fo.QU(at)) % mod;
        // cout<<sf<<' ';
        sf = (n+1) * ((nele.QU(n-1)-nele.QU(at)) % mod) -sf;
        // cout<<sm<<' '<<sf<<'\n';
        re += a[at] * (sm * (n-at)% mod + sf * (at+1) % mod ) % mod; 
        re += a[at] * (at+1) % mod * (n-at) % mod;
        fo.MO(at, at+1);
        nele.MO(at, 1);
        re%=mod;
        // sf -= nele ()

    }
    cout<<re<<'\n';

    
}