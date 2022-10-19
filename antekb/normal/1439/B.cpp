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

const int N=1e5+5, INF=1e9+5, mod=1e9+7;
unordered_set<int> E[N];
int d[N];
bool check(int v){
    vi V;
    for(auto &i:E[v])V.pb(i);
    for(int i=0; i<sz(V); i++){
        for(int j=i+1; j<sz(V); j++){
            if(E[V[i]].find(V[j])==E[V[i]].end())return 0;
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            d[u]++;
            d[v]++;
            E[v].insert(u);
            E[u].insert(v);
        }
        vi zle;
        for(int i=1; i<=n; i++){
            if(d[i]<k)zle.pb(i);
        }
        for(int i=0; i<zle.size(); i++){
            int v=zle[i];
            for(int u:E[v]){
                if(d[u]--==k)zle.pb(u);
            }
        }
        if(zle.size()<n){
            cout<<"1 "<<n-zle.size()<<"\n";
            for(int i=1; i<=n; i++){
                if(d[i]>=k)cout<<i<<" ";
            }
            for(int i=1; i<=n; i++){
                d[i]=0;
                E[i].clear();
            }
            cout<<"\n";
            continue;
        }
        zle.clear();
        vi V;
        for(int i=1; i<=n ;i++){
            if(E[i].size()<k-1){
                zle.pb(i);
            }
            if(E[i].size()==k-1)V.pb(i);
        }
        while(zle.size()||sz(V)){
            while(zle.size()){
                int v=zle.back();
                zle.pp();
                for(int u:E[v]){
                    E[u].erase(E[u].find(v));
                    if(E[u].size()==k-1){
                        V.pb(u);
                    }
                    if(E[u].size()==k-2){
                        zle.pb(u);
                    }
                }
                E[v].clear();
            }
            if(V.size()){
                int v=V.back();
                V.pp();
                if(E[v].size()<k-1)continue;
                if(check(v)){
                    cout<<2<<"\n";
                    cout<<v<<" ";
                    for(int i:E[v])cout<<i<<" ";
                    cout<<"\n";
                    V.pb(0);
                    break;
                }
                else zle.pb(v);
            }
        }
        if(!sz(V))cout<<"-1\n";
        for(int i=1; i<=n; i++){
            d[i]=0;
            E[i].clear();
        }
    }
}