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

const int N=2e5+5, INF=1e9+5, mod=1e9+7, K=100;
vector<pii> E[N];
int in[N][K];
int czy[K][K], czy2[K];
int tab[K], cnt=0, k, n;
vector<int> zle;
void gen(int l){
    //cout<<l<<"a\n";

    if(l==k+1){
        //cout<<tab[1]<<tab[2]<<tab[3]<<tab[4]<<"\n";
        /*int u=1;
        for(int i=0; i<n; i++){
            u=E[u][tab[E[u].size()]].nd;
            if(u==1){
                if(i==n-1)cnt++;
                else break;
            }
        }*/
        cnt++;
        return;
    }
    if(!czy2[l]){
        gen(l+1);
        return;
    }
    for(int i=0; i<l; i++){
        int t=l*k+i;
        bool c=0;
        for(int j:zle)if(czy[j][t]){c=1;break;}
        if(czy[t][t])c=1;
        //cout<<t<<"\n";
        if(!c){
            //cout<<"+"<<t<<"\n";
            zle.push_back(t);
            tab[l]=i;
            gen(l+1);
            zle.pop_back();
            //cout<<"-"<<t<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        E[u].push_back({w, v});
    }
    for(int i=1; i<=n; i++){
        czy2[E[i].size()]=1;
        sort(all(E[i]));
        for(int j=0; j<E[i].size(); j++){
            in[E[i][j].nd][j+k*E[i].size()]++;
        }
    }
    for(int i=1; i<=n; i++){
        //if(in[i].size()==0){cout<<"0"; return 0;}
        vi V;
        for(int j=0; j<K; j++){
            if(in[i][j])V.pb(j);
            if(in[i][j]>1)V.pb(j);
        }
        for(int j=0; j<V.size(); j++){
            for(int c=j+1; c<V.size(); c++){
                czy[V[j]][V[c]]=1;
            }
        }
    }
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            if(czy[i][j])czy[j][i]=1;
        }
    }
    //for(int i=0; i<15; i++)for(int j=0; j<15; j++)cout<<czy[i][j]<<" \n"[j==14];
    gen(1);
    for(int i=1; i<=k; i++){
        if(!czy2[i])cnt*=i;
    }
    cout<<cnt;
}