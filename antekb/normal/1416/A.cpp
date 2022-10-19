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
        vi V(n);
        for(int i=0; i<n; i++)cin>>V[i];
        vi prev(n+1);
        vi maks(n+1);
        for(int i=0; i<=n; i++)prev[i]=-1;
        for(int i=0; i<n; i++){
            maks[V[i]]=max(i-prev[V[i]], maks[V[i]]);
            prev[V[i]]=i;
        }
        for(int i=1; i<=n; i++){
            maks[i]=max(n-prev[i], maks[i]);
            maks[i]--;
        }
        vector<pii> V2;
        V2.push_back({-1, n+1});
        for(int i=1; i<=n; i++){
            V2.push_back(mp(maks[i], i));
        }
        //cout<<maks[2]<<maks[4]<<maks[1]<<maks[3]<<"\n";
        sort(all(V2));
        V2.push_back({n+1, 0});
        int wsk=0, ans=n+1;
        for(int i=0; i<n; i++){
            while(V2[wsk].st<=i){ans=min(ans, V2[wsk].nd);wsk++;}
            if(ans<n+1)cout<<ans<<" ";
            else cout<<"-1 ";
        }
        cout<<"\n";
    }
}