#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2e5+5, INF=1e9+5;
int A[N], czy[N], val[N], vis[N], mini[N], ile1[N], ile2[N];
vi E[N];
ll ans;
void dfs(int v){
    vis[v]=1;
    bool b=0;
    if(mini[v]>A[v]){
        b=1;
        mini[v]=A[v];
    }
    for(int u:E[v]){
        if(!vis[u]){
            mini[u]=mini[v];
            dfs(u);
            ile1[v]+=ile1[u];
            ile2[v]+=ile2[u];
        }
    }
    if(czy[v]&&val[v])ile1[v]++;
    else if(czy[v]) ile2[v]++;
    if(b){
        int t=min(ile1[v], ile2[v]);
        ans+=t*1ll*A[v];
        ile1[v]-=t;
        ile2[v]-=t;
    }
}
int main(){
    int n;
    cin>>n;
    int cnt1=0, cnt2=0;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin>>A[i]>>b>>c;
        val[i]=b;
        if(b!=c){
            czy[i]=1;
            if(b)cnt1++;
            else cnt2++;
        }
    }
    if(cnt1!=cnt2){
        cout<<"-1";
        return 0;
    }
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    mini[1]=INF;
    dfs(1);
    cout<<2*ans;
}