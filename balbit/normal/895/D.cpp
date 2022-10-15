#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int maxn = 1e6+5;

ll fac[maxn];
ll ifac[maxn];
int n;

ll nles(string &s, vector<int> a){
    ll re = 0;
    REP(i,n){ // Have followed pattern since 0...i-1
        ll mul = 1;
        REP(ch, 26){
            if (a[ch]) mul = (mul*ifac[a[ch]])%mod;  
        }
        REP(ch, s[i]-'a'){
            // cout<<"DID"<<endl;
            if (a[ch]){
                re += fac[n-i-1] * mul %mod * fac[a[ch]] % mod * ifac[a[ch]-1] % mod;
                re %= mod;
            }
        }
        if (a[s[i]-'a']) {
            a[s[i]-'a'] --;
        }else break;
    }
    return re;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a, b; cin>>a>>b;
    n = a.length();
    fac[0]=1; 
    FOR(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    FOR(i,1,maxn) ifac[i] = inv(fac[i]);
    ifac[0]=1;
    vector<int> v(26);
    REP(i,n){
        v[a[i]-'a']++;
    }
    ll B = nles(b,v); 
    ll A = nles(a,v);
    // debug(B); debug(A);
    cout<<(nles(b,v) - nles(a,v) - 1 + mod+mod)%mod << '\n';

    
}