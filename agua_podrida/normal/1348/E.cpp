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
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1000000000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

const int N = 501;
const int K = 501;
ll aux[N][K];
bool dp[K];
bool dp2[K];
ll a[N];
ll b[N];

void e(){
    ll n,k;
    cin>>n>>k;
    F1(i,n) cin>>a[i]>>b[i];

    F0(i,N) F0(j,K) aux[i][j] = false;
    F1(i,n){
        F0(j,k){
            if(j > a[i]) continue;
            ll rojo = a[i]-j;
            if(rojo%k == 0 or b[i]+(rojo%k) >= k) aux[i][j] = true;
        }
    }

    F0(j,K) dp[j] = false;
    dp[0] = true;
    F1(i,n){
        F0(j,k){
            dp2[j] = false;
            F0(jp,k){
                if(jp > a[i]) break;
                if(dp2[j]) break;
                dp2[j] |= dp[(j-jp+k)%k] and aux[i][jp];
            }
        }
        F0(j,k) dp[j] = dp2[j];
    }
    ll total = 0;
    F1(i,n) total += a[i];
    F1(i,n) total += b[i];
    ll res = 0;
    F0(j,k) {
        if(!dp[j]) continue;
        ll quedan = total-j;
        maxi(res,quedan/k);
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}