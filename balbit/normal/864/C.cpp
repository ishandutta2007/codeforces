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

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    int a, b, f, k; cin>>a>>b>>f>>k;
    int d1 = 2*f, d2 = 2*(a-f);
    int B = b;
    int re = 0;
    REP(i,k+1){
        int d;
        if (i==0){
            d = f;
        }else if (i==k){
            if (i%2==1) d = a-f;
            else d = f;
        }else if (i&1){
            d = d2;
        }else{
            d=d1;
        }
        // debug(d);
        // debug(b);
        if (b-d<0){
            if (i==0) GG();
            re++;
            b=B; b-=d; 
            if (b<0) GG();
        }else b-=d;
    }
    cout<<re<<'\n';

    
}