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
#ifndef LOCAL
#define endl '\n'
#endif
using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<":(\n"; exit(0);}

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

const int mm = 151;

int dp[mm][mm*(mm-1)/2];
int odp[mm][mm*(mm-1)/2];
int q[mm+1];
int k; int n; 



main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // REP(i,mm) REP(j,mm) REP(k,(mm-1)*mm/2) dp[i][j][k]=-1;
    cin>>n>>k; int S; cin>>S;
    REP(i,n) cin>>q[i];
    if (S >= mm * (mm-1) / 2) {
        sort(q, q+n); int re = 0; REP(i,k) re += q[i]; cout<<re<<endl; return 0;
    }
    int re = 0; REP(i,k) re += q[i]; 
    for (int at = k-1; at>=0; at--){
        FOR(b,k,n){
            REP(s,S+1){
                if (s-(b-at)>=0 && q[at]-q[b]>0){
                    MX(dp[b][s], odp[b-1][s-(b-at)] + q[at]-q[b]);
                }
                MX(dp[b][s], max(odp[b][s], dp[b-1][s]));
            }
        }
        FOR(b,k,n){
            REP(s,S+1){
                odp[b][s] = dp[b][s]; dp[b][s] = 0;
            }
        }
    }
    cout<<re-odp[n-1][S]<<'\n';
}