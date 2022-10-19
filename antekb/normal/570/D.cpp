#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int A=30, N=5e5+5;
int d[N], siz[N], ile[A][N], ile2[N], ans[N];
char c[N];
vector<int> E[N];
vector<pair<int, int> > Q[N];
void prepare(int v){
    siz[v]=1;
    for(int u:E[v]){
        d[u]=d[v]+1;
        prepare(u);
        siz[v]+=siz[u];
    }
    //cout<<v<<" "<<siz[v]<<" "<<d[v]<<"\n";
}
void paint(int v, int t){
    if(ile[c[v]-'a'][d[v]]&1)   ile2[d[v]]--;
    else ile2[d[v]]++;
    ile[c[v]-'a'][d[v]]+=t;
    for(int u:E[v]){
        paint(u, t);
    }
}
void solve(int v, int t){
    int heavy=0;
    for(int u:E[v]){
        if(siz[u]>siz[heavy])   heavy=u;
    }
    for(int u:E[v]){
        if(heavy!=u)    solve(u, -1);
    }
    if(heavy!=0)    solve(heavy, 1);
    for(int u:E[v]){
        if(heavy!=u)    paint(u, 1);
    }
    if(ile[c[v]-'a'][d[v]]&1)   ile2[d[v]]--;
    else ile2[d[v]]++;
    ile[c[v]-'a'][d[v]]++;
    for(auto i:Q[v]){
        //cout<<v<<" "<<i.st<<" "<<i.nd<<" "<<ile2[i.st]<<"\n";
        if(ile2[i.st]<2)    ans[i.nd]=1;
    }
    if(t==-1)   paint(v, -1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        E[x].push_back(i);
    }
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    for(int i=0; i<q; i++){
        int v, h;
        cin>>v>>h;
        Q[v].push_back({h, i});
    }
    d[1]=1;
    prepare(1);
    solve(1, 1);
    for(int i=0; i<q; i++){
        if(ans[i])  cout<<"Yes\n";
        else cout<<"No\n";
    }
}