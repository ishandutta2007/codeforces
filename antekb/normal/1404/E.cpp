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

const int N=205, M=1e5+5, mod=1e9+7;
int tab[N][N], R[N][N], D[N][N], d[M], anc[M], match[M];
vi E[M];
int ans=0;
int bfs(int s){
    d[s]=1;
    anc[s]=0;
    vi V={s};
    for(int i=0; i<sz(V); i++){
        int v=V[i];
        if(!(d[v]&1)){
            if(match[v]){
                V.pb(match[v]);
                d[match[v]]=d[v]+1;
                anc[match[v]]=v;
            }
            else{
                while(v!=0){
                    match[v]=anc[v];
                    match[anc[v]]=v;
                    v=anc[anc[v]];
                }
                return 1;
            }
        }
        else{
            for(int u:E[v]){
                if(!d[u]){
                    d[u]=d[v]+1;
                    anc[u]=v;
                    V.pb(u);
                }
            }
        }
    }
    return 0;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m;j++)tab[i][j]=(s[j]=='#');
    }
    int wsk=1, wsk2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            wsk2+=tab[i][j];
            if((i<n-1)&&tab[i][j]&&tab[i+1][j])D[i][j]=wsk++;
            if((j<m-1)&&tab[i][j]&&tab[i][j+1])R[i][j]=wsk++;
            if(R[i][j]&&D[i][j]){E[wsk-1].pb(wsk-2); E[wsk-2].pb(wsk-1);}
            if(j&&D[i][j]&&R[i][j-1]){
                E[D[i][j]].pb(R[i][j-1]);
                E[R[i][j-1]].pb(D[i][j]);
            }
            if(i&&D[i-1][j]&&R[i][j]){
                E[D[i-1][j]].pb(R[i][j]);
                E[R[i][j]].pb(D[i-1][j]);
            }
            if(j&&i&&D[i-1][j]&&R[i][j-1]){
                E[D[i-1][j]].pb(R[i][j-1]);
                E[R[i][j-1]].pb(D[i-1][j]);
            }
        }
    }
    /*for(int i=1; i<wsk; i++){
        cout<<i<<": ";
        for(int u:E[i])cout<<u<<" ";
        cout<<"\n";
    }*/
    for(int i=1; i<wsk; i++){
        if(!match[i] && !bfs(i)){
            for(int j=1; j<wsk; j++)d[j]=0;
            bfs(i);
        }
    }
    for(int i=1; i<wsk; i++)ans+=!!match[i];
    //cout<<wsk2<<" "<<wsk<<" "<<ans<<"\n";
    cout<<wsk2-wsk+1+ans/2;
}