#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

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

int g[4][102];
vector<int> gd;
int n, m; 

int dfs(int at, vector<int> bst){
    int re = 0;
    if (at >= min(n,m)){
        REP(i,SZ(bst)) re += bst[i]; return re;
    }
    REP(s,n){ 
        vector<int> bb = bst;
        REP(i,n){
            MX(bb[i], g[(i+s)%n][gd[at]]);
        }
        MX(re, dfs(at+1, bb));
    }
    return re;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while (t--){
        cin>>n>>m;
        gd.clear();
        vector<pii> mx(m);
        // vector<vector<int> > g(n);
        REP(i,n) { 
            REP(j,m){
                cin>>g[i][j];
                MX(mx[j].f, g[i][j]); mx[j].s = j;
            }
        }
        sort(ALL(mx), greater<pii> ());
        REP(i,min(m,n)) gd.pb(mx[i].s);

        vector<int> vv;
        REP(i,n) vv.pb(0);
        cout<<dfs(0,vv)<<'\n';
    }

    
}