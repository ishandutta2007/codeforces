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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=0;
        vi V(n);
        for(int i=0; i<n; i++)cin>>V[i];
        for(int i=1; i<n; i++){
            if(V[i]<V[i-1])ans+=V[i-1]-V[i];
        }
        cout<<ans<<"\n";
    }
}