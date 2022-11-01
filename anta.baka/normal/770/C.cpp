#include <bits/stdc++.h>
using namespace std;
const int N = 100001;

vector<int> g[N];
int n,k,b[N],ans;
vector<int> tps, imp;

void dfs(int v){
    ans++;
    b[v]=1;
    for(int to:g[v])
        if(b[to]==0)dfs(to);
        else if(b[to]==1){
            cout<<-1;
            exit(0);
        }
    b[v]=2;
    tps.push_back(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int v;
        cin>>v;
        --v;
        imp.push_back(v);
    }
    for(int u=0;u<n;u++){
        int t;
        cin>>t;
        g[u].resize(t);
        for(int i=0;i<t;i++){
            int v;
            cin>>v;
            --v;
            g[u][i] = v;
        }
    }
    for(int x : imp) if (!b[x]) dfs(x);
    cout<<ans<<"\n";
    for(int v:tps) cout<<v+1<<' ';
}