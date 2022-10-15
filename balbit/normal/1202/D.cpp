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

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while (T--){
        ll x; cin>>x;
        vector<int> b;
        for (ll i = 100000; i>=2; i--){
            ll tmp = i * (i-1) / 2; 
            while ( tmp<=x ){
                x-=tmp; b.pb(i);
            }
        }
        b.pb(0);
        string s = "7";
        RREP(i, SZ(b)){
            if (i==0) break;
            if (b[i-1]==b[i]){
                s+='1'; continue;
            }
            REP(j, b[i-1]-b[i]){
                s+='3';
            }
            s+='1';
        }
        reverse(ALL(s));
        cout<<s<<'\n';
    }

    
}