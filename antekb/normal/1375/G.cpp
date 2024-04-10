#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> E[N];
int d[N];
void dfs(int v){
    for(int u:E[v]){
        if(!d[u]){
            d[u]=d[v]+1;
            dfs(u);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    d[1]=1;
    dfs(1);
    int k=0;
    for(int i=1; i<=n; i++){
        k+=d[i]&1;
    }
    cout<<min(k-1, n-1-k);
}