#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=2e9+5, mod=1e9+7;
int vis[N], pre[N], post[N], ojc[N], wsk1, wsk2, ile[N], lo[N], ile2[N], czy[N];
vi E[N];
int s, n;
void dfs(int v){
    vis[v]=1;
    pre[v]=wsk1++;
    lo[v]=v;
    ile[v]=0;
    ile2[v]=0;
    for(int u:E[v]){
        if(!vis[u]){
            ojc[u]=v;
            dfs(u);
            ile[v]+=ile[u];
            if(pre[lo[v]]>pre[lo[u]])lo[v]=lo[u];
        }
        else{
            ile2[u]++;
            ile[v]++;
            if(pre[u]<pre[lo[v]])lo[v]=u;
        }
    }
    ile[v]-=ile2[v];
    post[v]=wsk2++;
}
int dfs2(int v){
    vis[v]=1;
    czy[v]=0;
    //cout<<v<<" "<<lo[v]<<" "<<czy[lo[v]]<<" ";
    if(v!=s && (czy[lo[v]] || lo[v]==v || ile[v]!=1)) czy[v]=1;
    //cout<<czy[v]<<"\n";
    for(int u:E[v]){
        if(!vis[u]) dfs2(u);
    }
}
void czysc(){
    wsk1=0;
    wsk2=0;
    for(int i=1; i<=n; i++){
        post[i]=0;
        pre[i]=0;
        vis[i]=0;
    }
}
bool check(){
    //cout<<wsk1<<" ";
    if(wsk1!=n){
        return 0;
    }
    for(int v=1; v<=n; ++v){
        for(int u:E[v]){
            if(ojc[u]!=v && (pre[u]>pre[v] || post[u]<post[v])){
                //cout<<u<<" "<<v<<" "<<pre[u]<<" "<<pre[v]<<" "<<post[u]<<" "<<post[v]<<" "<<ojc[u]<<"\n";
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    //mt19937 rng(247635747);
    int t=1, m, T=40;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            E[u].pb(v);
        }
        for(int k=0; k<T; k++){
            //s=rng()%n+1;
            //cout<<s<<"a\n";
            s=uniform_int_distribution<int>(1, n)(rng);
            dfs(s);
            if(!check())s=0;
            czysc();
            if(s)break;
        }
        if(s){
            /*cout<<"\n"<<s<<"\n\n";
            for(int i=1; i<=n; i++){
                cout<<i<<" "<<ile[i]<<" "<<lo[i]<<" "<<vis[i]<<czy[i]<<"\n";
            }*/
            dfs2(s);
            vi V;
            for(int i=1; i<=n; i++){
                if(!czy[i]){
                    V.pb(i);
                }
                vis[i]=0;

            }
            if(sz(V)*5>=n){
                //cout<<"\n\n";
                for(int i:V){
                    cout<<i<<" ";
                }
                cout<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else cout<<"-1\n";
        for(int i=1; i<=n; i++){
            E[i].clear();
        }
    }
}