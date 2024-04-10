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

const int N=5e5+5, INF=1e9+5, mod=1e9+7;
int r[N], czy[N];
int Find(int v){
    if(r[v]==v)return v;
    return r[v]=Find(r[v]);
}
void Union(int u, int v){
    r[u]=v;
    if(czy[u])czy[v]=1;
}
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

    int m, n;
    cin>>m>>n;
    for(int i=0; i<N;i ++){
        r[i]=i;
    }
    vi V;
    for(int i=0; i<m;i ++){
        int k, u, v;
        cin>>k;
        if(k==1){
            cin>>v;
            v=Find(v);

            if(!czy[v]){
                czy[v]=1;
                V.pb(i);
            }
        }
        else{
            cin>>u>>v;
            u=Find(u);
            v=Find(v);

            if(u!=v){
                if((!czy[u])||(!czy[v])){
                    Union(v, u);
                    V.pb(i);
                }
            }
        }
    }
    cout<<pot(2, sz(V))<<" "<<sz(V)<<"\n";
    for(int i:V)cout<<i+1<<" ";
}