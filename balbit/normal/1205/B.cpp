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

ll n; 
vector<ll> a;
vector<ll> b(maxn);
vector<int> g[maxn];

int cyc(int st){
    queue<int> qq;
    qq.push(st);
    vector<ll> dst(n,iinf);
    dst[st ] = 0;
    while (!qq.empty()){
        int x = qq.front(); qq.pop();
        for (int v : g[x]){
            if (dst[v]!=iinf && dst[v] != dst[x] -   1){
                return dst[v] + dst[x] + 1;
            }
            if (dst[v ] > dst[x] + 1){
                dst[v] = dst[x] + 1;
                qq.push(v);
            }
        }
    }
    return iinf;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    REP(i,n) {
        cin>>b[i]; if (b[i] != 0) a.pb(b[i]);
    }
    n = a.size();
    // debug(n);
    if (n*n*n<4e6){
        REP(i,n){
            REP(j,i){
                if ((a[i] & a[j]) != 0){
                    g[i].pb(j); g[j].pb(i);
                    // cout<<"HI"<<'\n';
                }
            }
        }
        ll re = iinf;
        REP(i,n){
            MNTO(re, cyc(i));
            // debug(cyc(i));
        }
        if (re == iinf) GG();
        cout<<re<<'\n';
        // cout<<ans(a)<<'\n';
    }else{
        cout<<3<<'\n';
    }

    
}