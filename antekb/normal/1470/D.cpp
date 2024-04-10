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

const int N=3e5+5, INF=1e9+5, mod=1e9+7;
vi E[N];
int vis[N], czy[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            E[u].pb(v);
            E[v].pb(u);
        }
        vi V;
        V.pb(1);
        vis[1]=1;
        for(int i=0; i<sz(V); i++){
            int v=V[i];
            if(czy[v]==0){
                czy[v]=1;
                for(int u:E[v]){
                    czy[u]=-1;
                }
            }
            for(int u:E[v]){
                if(!vis[u]){
                    vis[u]=1;
                    V.pb(u);
                }
            }
        }
        bool b=(sz(V)==n);
        V.clear();
        for(int i=1; i<=n; i++){
            vis[i]=0;
            if(czy[i]==1)V.pb(i);
            czy[i]=0;
            E[i].clear();
        }
        if(!b)cout<<"NO\n";
        else{
            cout<<"YES\n"<<sz(V)<<"\n";
            for(int i:V)cout<<i<<" ";
            cout<<"\n";
        }
    }
}