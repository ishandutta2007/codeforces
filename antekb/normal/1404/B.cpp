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
vi E[N];
int d[N];
void dfs(int v){
    for(int i:E[v]){
        if(!d[i]){
            d[i]=d[v]+1;
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, a, b, da, db;
        cin>>n>>a>>b>>da>>db;
        for(int i=1; i<n; i++){
            int x, y;
            cin>>x>>y;
            E[x].pb(y);
            E[y].pb(x);
        }
        d[a]=1;
        dfs(a);
        int M=1;
        for(int i=1; i<=n; i++){
            if(d[i]>d[M])M=i;
        }
        int c=0;
        if(d[b]-1<=da)c=1;
        for(int i=1; i<=n; i++){
            //cout<<d[i]<<" ";
            d[i]=0;
        }
        //cout<<M<<"\n";
        d[M]=1;
        dfs(M);
        for(int i=1; i<=n; i++){
            //cout<<d[i]<<" ";
            if(d[i]>d[M])M=i;
        }
        int diam=d[M]-1;
        //cout<<diam<<"\n";
        if(diam>2*da && db>2*da && !c){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
        for(int i=1; i<=n; i++){
            E[i].clear();
            d[i]=0;
        }
    }
}