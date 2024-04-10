#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=998244353;
int fact[N];
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
int npok(int _n, int _k){
    return (((fact[_n]*1ll*pot(fact[_k], mod-2))%mod)*1ll*pot(fact[_n-_k], mod-2))%mod;
}
int main(){
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*1ll*i)%mod;
    }
    int n;
    cin>>n;
    ll ans=0;
    //cout<<npok(1, 0)*npok(3,1)<<" ";
    for(int k=n&1; k<=n; k++,k++){
        ans+=npok((n-k)/2+k-1, k-1);
        ans=ans%mod;
    }
    ans=ans*pot((mod+1)/2, n);
    ans=ans%mod;
    cout<<ans;
}