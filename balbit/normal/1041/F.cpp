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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t t = clock();
    int n, foo; cin>>n>>foo;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int m; cin>>m>>foo;
    vector<int> b(m);
    REP(j,m) cin>>b[j];

    
    int re = 0;
    {
        int a1 = 0, a2 = 0;
        REP(i,n){
            if (a[i]&1) a2++;
            else a1++;
        }
        REP(i,m){
            if ((b[i])&1) a1++;
            else a2++;
        }
        re = max(a1, a2);
    }

    while ((clock() - t) / CLOCKS_PER_SEC < 1.9){
        int x = a[rng() % n];
        int y = b[rng() % m];
        if (x==y) {
            int ans = 0;
            REP(i,n){
                if ((a[i] - x) == 0) ans ++;
            }
            REP(i,m){
                if ((b[i] - y) == 0) ans ++;
            }
            MXTO(re, ans); continue;
        }
        int d = abs(x-y);
        int dst = 1;
        while (d%2==0){
            dst<<=1; d>>=1;
        }
        // d is number of times the bounce occurs
        int ans = 0;
        REP(i,n){
            if ((a[i] - x) % (2*dst) == 0) ans ++;
        }
        REP(i,m){
            if ((b[i] - y) % (2*dst) == 0) ans ++;
        }
        MXTO(re, ans);
    }
    cout<<re<<'\n';
}