#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[200000];
int col[200000];
int hi=0;

void solve(int v, int p=-1) {
    hi=max(hi,col[v]);
    int c=1;
    for(int to:g[v]){
        if(to==p)continue;
        while(c==col[v]||p!=-1&&c==col[p])c++;
        col[to]=c;
        c++;
        solve(to, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    //freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    col[0]=1;
    solve(0);
    cout<<hi<<"\n";
    for(int i=0; i<n; i++) cout<<col[i]<<' ';
}