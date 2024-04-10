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

vector<ll> a[4];

vector<ll> even, odd;
vector<ll> eps, ops;

ll poss(ll w){
    if (w<0) return -inf;
    ll re = 0;
    if (w&1 && a[1].size()>0){
        re += a[1][0];
        re += ops[min((w-1)/2, (ll)ops.size()-1)];
        return re;
    }else{
        re += eps[min(w/2, (ll)eps.size()-1)];
        return re;
    }


}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    REP(i,n){
        int w; ll c; cin>>w>>c;
        a[w].pb(c);
    }
    
    a[1].pb(0);
    REP(i,4){
        sort(ALL(a[i]), greater<ll> ()); 
    }
    even = odd = a[2];
    eps.pb(0); ops.pb(0);

    if (a[1].size()){
        for (int i = 1; i+1 < SZ(a[1]); i+=2){
            odd.pb(a[1][i] + a[1][i+1]); 
        }
    }
    for (int i = 0; i+1 < SZ(a[1]); i+=2){
        even.pb(a[1][i]+a[1][i+1]); 
    }
    sort(ALL(even), greater<ll>());
    sort(ALL(odd), greater<ll> ());
    REP(i, SZ(odd)){
        ops.pb(ops.back() + odd[i]);
    }
    REP(i, SZ(even)) {
        eps.pb(eps.back() + even[i]);
    }

    ll re = 0;
    ll s3 = 0;
    REP(i, SZ(a[3])+1){
        MXTO(re, s3 + poss(m - 3 * i));
        if (i!=SZ(a[3])){
            s3 += a[3][i];
        }
    }
    cout<<re<<'\n';
    
}