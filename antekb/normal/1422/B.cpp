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
        int n, m;
        cin>>n>>m;
        vector<vector<vi>> V(n);
        for(int i=0; i<n; i++)V[i].resize(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x=i, y=j;
                x=min(x, n-x-1);
                y=min(y, m-y-1);
                int z;
                cin>>z;
                V[x][y].pb(z);
            }
        }
        ll ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(V[i][j].size()<2)continue;
                sort(all(V[i][j]));
                //debug(V[i][j][0],V[i][j][1], V[i][j][2], V[i][j][3]);
                if(V[i][j].size()>=4)ans+=V[i][j][3]-V[i][j][1];
                if(V[i][j].size()>=3)ans+=V[i][j][2]-V[i][j][1];
                if(V[i][j].size()>=2)ans+=V[i][j][1]-V[i][j][0];
                //ans-=V[i][j][0];
                //cout<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
}