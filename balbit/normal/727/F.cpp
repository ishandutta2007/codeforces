#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
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

const int maxn = 750;

ll dp[maxn];
ll a[maxn];
int n, m; 

int can(ll ad){
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll at = ad;
    ll re= 0;
    REP(i,n){
        at += a[i];
        if (a[i] <0 ) pq.push(a[i]);
        if (at < 0){
            ll cpt = pq.top();
            at -= cpt;
            pq.pop();
            re++;
        }
    }
    return re;
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,n+1){
        ll l = 0, r = 750e9+1;
        while (l!=r){
            ll mid = l+r>>1;
            if (can(mid)>i){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        dp[n-i] = l;
    }
    dp[n+1 ] = inf;
    while (m--){
        ll x; cin>>x;
        cout<<n-(upper_bound(dp, dp+n+1, x) - dp-1)<<'\n';
    }
    
}