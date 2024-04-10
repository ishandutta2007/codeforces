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

const int N=2e5+5, INF=1e9+5, mod=1e9+7, K=60;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vl V(n);
        int ile[K];
        for(int i=0; i<K; i++){
            ile[i]=0;
        }
        for(ll &i:V){
            cin>>i;
            for(int j=0; j<K; j++){
                if(i&(1ll<<j)){
                    ile[j]++;
                }
            }
        }
        ll ans=0;
        for(ll i:V){
            ll s1=0, s2=0;
            for(int j=0; j<K; j++){
                if(i&(1ll<<j)){
                    s1+=((1ll<<j)%mod)*1ll*ile[j];
                    s2+=((1ll<<j)%mod)*1ll*n;
                }
                else{
                    s2+=((1ll<<j)%mod)*1ll*ile[j];
                }
            }
            s1%=mod;
            s2%=mod;
            ans+=s1*s2;
            ans%=mod;
        }
        cout<<ans<<"\n";
    }
}