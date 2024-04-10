//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int N=2e5+5, INF=1e9+5, mod=998244353;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
int odw(int x){return pot(x, mod-2);}
ll pref[N], suf[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;
    vi V(n);
    for(int i=0; i<n; i++)cin>>V[i];
    sort(all(V));
    for(int i=0; i<n; i++){
        pref[i+1]=(pref[i]+V[i])%mod;
    }
    for(int i=n-1; i>=0; i--){
        suf[i]=(suf[i+1]+V[i])%mod;
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        int k=lower_bound(all(V), b)-V.begin();
        ll ans=0, l=n-k;
        ans=(((((l-a)*1ll*suf[k])%mod))*1ll*odw(l))%mod;
        ans+=((pref[k]*1ll*odw(l+1))%mod)*1ll*(l-a+1);
        if(l<a){ans=0;}
        cout<<(ans%mod)<<"\n";
    }
}