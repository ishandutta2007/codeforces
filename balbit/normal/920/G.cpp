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

const int maxn = 1e6+5;
// CHANGE LATER

vector<int> pfac[maxn];
bool prm[maxn];

void build(){
    // int npb = 0;
    fill(prm, prm+maxn, 1);
    FOR(i,2,maxn){
        if (prm[i]){
            for (int j = i; j<maxn; j+=i){
                prm[j]=0;
                pfac[j].pb(i);
                // MXTO(npb, pfac[j].size());
            }
        }
    }
    // cout<<npb<<endl;
}

ll nles(int x, int p){
    int m = pfac[p].size();
    ll re = 0;
    FOR(i,1, 1<<(m)){
        ll mul = 1;
        REP(j,m){
            if (i & (1<<j)) {
                mul *= pfac[p][j];
            }
        }
        mul = x/mul;
        if (__builtin_popcount(i)&1){ // Add
            re+=mul;
        }   else{
            re-=mul;
        }
    }
    return x-re;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    build();
    // cout<<"DONE"<<endl;
    int t; cin>>t;
    while (t--){
        ll x, p, k; cin>>x>>p>>k;
        int nx = nles(x,p);
        k += nx;
        ll l = 0, r = 10000000;
        while (l!=r){
            ll mid = (l+r)>>1;
            if (nles(mid, p) < k) {
                l = mid +1;
            }else{
                r = mid;
            }
        }
        cout<<r<<'\n';
    }

    
}