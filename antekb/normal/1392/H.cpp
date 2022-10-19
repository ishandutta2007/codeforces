#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
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
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=4e6+5, INF=1e9+5, mod=998244353;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
int odw(ll a){return pot(a, mod-2);}
int fact[N], fact2[N];
int npok(int _n, int _k){
    return (((fact[_n]*1ll*fact2[_k])%mod)*1ll*fact2[_n-_k])%mod;
}

int main(){
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*1ll*i)%mod;
    }
    fact2[N-1]=odw(fact[N-1]);
    for(int i=N-2; i>=0; i--)fact2[i]=(fact2[i+1]*1ll*(i+1))%mod;
    int n, m;
    cin>>n>>m;
    ll nxt=0, sumw=1, S=0;
    for(int k=n-1; k>=0; k--){
        ll t=npok(m+n-k-1, m-1);
        nxt=(((sumw+t+S)%mod)*odw(sumw))%mod;
        sumw+=t;
        S+=t*nxt;
        S%=mod;
        sumw%=mod;
        //cout<<t<<" "<<sumw<<" "<<S<<" "<<nxt<<"\n";
    }
    cout<<(((nxt*(m+n+1))%mod)*odw(m+1))%mod;
}