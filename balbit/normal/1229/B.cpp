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


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

ll a[maxn];
vector<int> g[maxn];
map<int, int> mp [maxn];
ll re = 0;
void dd(int u, int p){
    mp[u][a[u]] ++;
    if (p!=-1)for (auto & xx : mp[p]){
        ll gg = gcd(xx.f,a[u]);
        mp[u][gg]+=xx.s; if (mp[u][gg]>=mod) mp[u][gg]-=mod;
    }
    for (auto & xx : mp[u]){
        re += (xx.s*(xx.f%mod)); re %= mod;
    }
    for (int v : g[u]){
        if (v!=p){
            dd(v,u);
        }
    }
    
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n) cin>>a[i];
    REP(i, n-1){
        int x, y; cin>>x>>y; g[x-1].pb(y-1); g[y-1].pb(x-1);
    }
    dd(0,-1);
    cout<<re<<endl;
    
}