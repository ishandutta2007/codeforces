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

const int N=55, INF=1e9+5, mod=1e9+7;
int E[N][N];
int d[N], vis[N], par[N], zle[N];
int czy[N][N];
int n;
bool dfs(int v, int k){
    if(d[v]<k){
        E[v][par[v]]=1;
        d[v]++;
        return 1;
    }
    vis[v]=1;
    for(int i=0; i<n; i++){
        if(!vis[i] && E[v][i] && !czy[v][i]){
            par[i]=v;
            if(dfs(i, k)){
                E[v][i]=0;
                if(par[v]!=-1)E[v][par[v]]=1;
                else d[v]--;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        d[u]++;
        E[u][v]=1;
        czy[u][v]=czy[v][u]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(!czy[i][j]){
                E[i][j]=1;
                d[i]++;
            }
        }
    }
    while(true){
        int M=-1;
        for(int i=0; i<n; i++){
            if(!zle[i] && (M==-1 || d[i]>d[M]))M=i;
        }
        if(M==-1)break;
        par[M]=-1;
        if(!dfs(M, d[M]-1))zle[M]=1;
        for(int i=0; i<n; i++){
            vis[i]=par[i]=0;
        }
    }
    /*int ans=n*(n-1)*(n-2)/3;
    for(int i=0; i<n; i++){
        ans-=d[i]*(d[i]-1)/2;
    }
    cout<<ans;*/
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<E[i][j];
        }
        cout<<"\n";
    }
}