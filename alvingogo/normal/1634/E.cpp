#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<vector<pair<int,pair<int,int> > > > e;
vector<vector<int> > ans,vis;
vector<int> it;
void add(int x,int y,int p,int i){
    e[x].push_back({y,{p,i}});
    e[y].push_back({x,{p,i}});
}
int nw=1;
void dfs(int x,pair<int,int> p){
    if(p.fs!=-1){
        vis[p.fs][p.sc]=1;
    }
    for(int& i=it[x];i<e[x].size();){
        auto y=e[x][i];
        i++;
        if(vis[y.sc.fs][y.sc.sc]){
            continue;
        }
        dfs(y.fs,y.sc);
    }
    if(p.fs!=-1){
        ans[p.fs][p.sc]=nw;
        nw=-nw;
    }
}
int main(){
	AquA;
    int m;
    cin >> m;
    vector<vector<int> > g(m);
    vector<int> k;
    ans.resize(m);
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        g[i].resize(a);
        ans[i].resize(a);
        for(int j=0;j<a;j++){
            cin >> g[i][j];
            k.push_back(g[i][j]);
        }
    }
    sort(k.begin(),k.end());
    k.erase(unique(k.begin(),k.end()),k.end());
    int mz=m+k.size();
    e.resize(mz);
    it.resize(mz);
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<g[i].size();j++){
            g[i][j]=lower_bound(k.begin(),k.end(),g[i][j])-k.begin();
            cnt++;
            add(i,g[i][j]+m,i,j);
        }
    }
    vis=ans;
    for(int i=0;i<mz;i++){
        if(e[i].size()%2){
            cout << "NO\n";
            exit(0);
        }
    }
    for(int i=0;i<mz;i++){
        dfs(i,{-1,-1});
    }
    cout << "YES\n";
    for(int i=0;i<m;i++){
        for(auto h:ans[i]){
            if(h>0){
                cout << "L";
            }
            else{
                cout << "R";
            }
        }
        cout << "\n";
    }
	return 0;
}