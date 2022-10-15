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

const int maxn = 3e5+5;

bool sn[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n, m; cin>>n>>m;
        vector<vector<pii>> g(n*3);
        
        REP(i,m){
            int a, b; cin>>a>>b;
            a--; b--; g[a].pb({b,i+1}); g[b].pb({a,i+1});
        }
        fill(sn, sn+n*3, 0);
        vector<int> mch;
        REP(i,n*3){
            if (sn[i]) continue;
            for (auto xx : g[i]){
                int v = xx.f;
                if (!sn[v]) {
                    sn[i]=1; sn[v]=1;
                    mch.pb(xx.s);
                    break;
                }
            }
        }
        if (mch.size()>=n){
            cout<<"Matching"<<'\n';
            REP(i,n) cout<<mch[i]<<' ';
            cout<<'\n';
        }else{
            cout<<"IndSet\n";
            int cnt = n;
            REP(i,n*3){
                if (!sn[i]){
                    cout<<i+1<<' '; cnt--; if (cnt==0) break;
                }
                
            }
            cout<<'\n';
        }
    }

    
}