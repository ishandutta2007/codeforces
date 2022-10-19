#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int vis[N], act[N], ans;
vector<int> E[N];
void dfs(int v){
    vis[v]=1;
    for(int u:E[v]){
        if(!vis[u]){
            dfs(u);
            if(act[u]==u){
                swap(act[v], act[u]);
                ans+=2;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        act[i]=i;
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    act[n]=n;
    dfs(1);
    if(act[1]==1){
        swap(act[1], act[E[1][0]]);
        ans+=2;
    }
    cout<<ans<<"\n";
    for(int i=1; i<=n; i++){
        cout<<act[i]<<" ";
    }
}