
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct TPS{
    vector<vector<int> > e;
    vector<int> in;
    int n;
    void init(int nn){
        n=nn;
        e.resize(n);
        in.resize(n);
    }
    void add(int x,int y){
        if(x==-1 || y==-1){
            return;
        }
        e[x].push_back(y);
        in[y]++;
        //cout << x << " " << y << endl;
    }
    void print(){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto h=q.front();
            q.pop();
            cout << h+1 << " ";
            for(auto y:e[h]){
                in[y]--;
                if(in[y]==0){
                    q.push(y);
                }
            }
        }   
        cout << "\n";
    }
}tps;
struct no{
    vector<pair<int,int> > ch;
    int u=-1,d=-1;
};
vector<no> v;
vector<int> vis;
vector<int> p;
void dfs(int r,int f){
    vis[r]=1;
    int w=-1;
    for(auto h:v[r].ch){
        if(h.fs!=f){
            dfs(h.fs,r);
        }
        else{
            w=h.sc;
        }
    }
    map<int,int> m,m2;
    for(int i=0;i<v[r].ch.size();i++){
        auto h=v[r].ch[i];
        if(h.fs!=f){
            m2[v[h.fs].u]=i;
        }
    }
    m2[p[r]]=-1;
    int x=w;
    if(r!=f){
        v[r].d=r;
    }
    for(int i=0;i<v[r].ch.size();i++){
        auto h=v[r].ch[i];
        if(h.fs!=f && m2.find(v[h.fs].d)==m2.end()){
            v[r].d=v[h.fs].d;
            break;
        }
    }
    for(int i=0;i<v[r].ch.size();i++){
        auto h=v[r].ch[i];
        if(h.fs!=f){
            m[v[h.fs].d]=i;
        }
    }
    m[r]=-1;
    int nw=-1;
    while(p[r]!=r){
        int z=p[r];
        if(m.find(z)==m.end()){
            v[r].u=z;
            p[r]=v[r].d;
            tps.add(nw,x);
            nw=x;
        }
        else{
            if(m[z]==-1){
                p[r]=r;
                break;
            }
            auto y=v[r].ch[m[z]];
            p[r]=v[y.fs].u;
            tps.add(nw,y.sc);
            nw=y.sc;
        }
    }
    //cout << r << " " << v[r].u << " " << v[r].d << " " << x << "\n";
}
int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    p.resize(n);
    v.resize(n);
    vis.resize(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].ch.push_back({b,i});
        v[b].ch.push_back({a,i});
    }
    tps.init(m);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,i);
        }
    }
    tps.print();
    return 0;
}