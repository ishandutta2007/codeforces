#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define piiii pair<pii, pii>
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

int dp[103][2025];
int t[103];
int d[103];
int val[103];
bool dir[103][2025];
int id[103];

bool cmp(piiii a, piiii b){
     return a.f.f + a.s.f>b.s.f + b.f.f;
    // return a.f.f>b.f.f;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<piiii> v;
    REP(i,n){
        int tt, dd, p; cin>>tt>>dd>>p;
        v.pb({{dd-tt,i+1},{tt,p}});
    }
    sort(ALL(v), cmp);
    REP(i,n){
        t[i+1]=v[i].f.f;
        id[i+1]=v[i].f.s;
        d[i+1]=v[i].s.f;
        val[i+1]=v[i].s.s;
    }

    FOR(i,1,n+1){ // One based
        REP(j,2001){
            MXTO(dp[i][j],dp[i-1][j]);
            if (j<t[i]){
                int xx = dp[ i - 1 ][ j + d[i] ] + val[i];
                if (xx > dp[i][j]) {
                    dp[i][j]=xx;
                    dir[i][j]=1;
                }
            }
            
        }
    }
    
    int j = 0;
    int tk = 0;
    vector<int> took;
    int vl = 0;
    for (int i = n; i>=1; i--){
        if (dir[i][j]==1){
            tk++;
            j += d[i];
            took.pb(id[i]);
            vl+=val[i];
        }
    }
    assert(vl == dp[n][0]);
    cout<<dp[n][0]<<'\n';
    cout<<tk<<'\n';
    REP(i,SZ(took)){
        cout<<took[i]<<' ';
    }
}