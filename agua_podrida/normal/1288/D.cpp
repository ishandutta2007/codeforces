#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    ll n,d;
    cin>>n>>d;
    ll mejor = (n/2 +1) * ((n+1)/2);
    if(mejor >= d) cout<<"YES\n";
    else cout<<"NO\n";
}

void b(){
    ll a,b;
    cin>>a>>b;
    ll mul = 0;
    ll nueves = 9;
    while(nueves <= b){
        mul++;
        nueves *= 10;
        nueves += 9;
    }
    cout<<a*mul<<'\n';
}

void c(){
    int n,m;
    cin>>n>>m;
    m--;
    vvll dp(n+1,vll(n+1));
    vvll q(n+1,vll(n+1));
    F1(i,n) F1(j,n) if(i <= j) dp[i][j] = 1;
    while(m--){
        F1(j,n) q[n][j] = (q[n][j-1] + dp[n][j])%mod;
        F1R(i,n-1) F1(j,n) q[i][j] = (q[i+1][j] + q[i][j-1] - q[i+1][j-1] + dp[i][j] + mod) % mod;
        dp = q;
    }
    ll res = 0;
    F1(i,n) F1(j,n) res = (res+dp[i][j])%mod;
    cout<<res<<'\n';
}

int n,m;
int resi, resj;

bool sePuede(vvi& a, int mid){
    vi bitmap(1<<m,-1);
    F0(i,n){
        int bitcode = 0;
        F0(j,m){
            if(a[i][j] >= mid) bitcode |= (1<<j);
        }
        bitmap[bitcode] = i;
    }

    F0(i,(1<<m)) F0(j,(1<<m)) {
            if((i | j) < (1<<m)-1) continue;
            if(bitmap[i] != -1 and bitmap[j] != -1) {
                resi = bitmap[i]; resj = bitmap[j];
                return true;
            }
        }
    return false;
}

void d(){
    cin>>n>>m;
    vvi a(n,vi(m));
    F0(i,n) F0(j,m) cin>>a[i][j];

    int lo = 0;
    int hi = 1000000001;
    while(lo+1 != hi){
        int mid = (lo+hi)/2;
        if(sePuede(a,mid)) lo = mid;
        else hi = mid;
    }

    cout<<resi+1<<' '<<resj+1<<'\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    d();
    return 0;
}