#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct DSU{
    vector<int> bo;
    void init(int x){
        bo.resize(x);
        iota(bo.begin(),bo.end(),0);
    }
    int find(int x){
        return bo[x]==x?x:bo[x]=find(bo[x]);
    }
    int merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return 0;
        }
        bo[x]=y;
        return 1;
    }
}dsu;
struct no{
    vector<int> ch;
    vector<pair<int,int> > ch2;
    int tag=0,tag2=0;
    int in=-1,out=-1;
    int ans=0;
};
int cnt=1;
vector<no> v;
void dfs(int r,int f){
    v[r].in=cnt;
    cnt++;
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
        }
    }
    v[r].out=cnt;
    cnt++;
}
bool as(int a,int b){
    return v[a].in<=v[b].in && v[a].out>=v[b].out;
}
int y=0;
void dfs2(int r,int f,int c){
    c+=v[r].tag;
    if(c==y){
        v[r].ans=1;
    }
    c+=v[r].tag2;
    for(auto h:v[r].ch){
        if(h!=f){
            dfs2(h,r,c);
        }
    }
}
int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    dsu.init(n);
    v.resize(n);
    vector<pair<int,int> > e(m),f;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(dsu.merge(a,b)){
            v[a].ch.push_back(b);
            v[b].ch.push_back(a);
        }
        else{
            f.push_back({a,b});
            y++;
        }
    }
    dfs(0,0);
    for(int r=0;r<n;r++){
        for(auto h:v[r].ch){
            v[r].ch2.push_back({v[h].in,h});
        }
        sort(v[r].ch2.begin(),v[r].ch2.end());
    }
    for(auto h:f){
        if(as(h.fs,h.sc)){
            auto a=upper_bound(v[h.fs].ch2.begin(),v[h.fs].ch2.end(),pair<int,int>(v[h.sc].in,1e9))-v[h.fs].ch2.begin()-1;
            assert(a>=0);
            v[0].tag++;
            v[v[h.fs].ch2[a].sc].tag--;
            v[h.sc].tag++;
        }    
        else if(as(h.sc,h.fs)){
            auto a=upper_bound(v[h.sc].ch2.begin(),v[h.sc].ch2.end(),pair<int,int>(v[h.fs].in,1e9))-v[h.sc].ch2.begin()-1;
            assert(a>=0);
            v[0].tag++;
            v[v[h.sc].ch2[a].sc].tag--;
            v[h.fs].tag++;
        }
        else{
            v[h.fs].tag++;
            v[h.sc].tag++;
        }
    }
    dfs2(0,0,0);
    for(int i=0;i<n;i++){
        cout << v[i].ans;
    }
    cout << "\n";
    return 0;
}