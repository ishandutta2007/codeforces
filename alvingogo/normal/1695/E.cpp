#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

vector<vector<pair<int,int> > > e;
vector<int> vis;
vector<int> nw;
vector<int> ans;
vector<pair<int,int> > p;
void dfs(int x,int f){
    if(f!=-1){
        vis[f]=1;
    }
    for(auto &it=nw[x];it<e[x].size();){
        auto y=e[x][it];
        it++;
        if(!vis[y.sc]){
            dfs(y.fs,y.sc);
        }
    }
    if(f!=-1){
        ans.push_back(f);
    }
}
int main(){
    AquA;
    int n;
    cin >> n;
    e.resize(2*n);
    vis.resize(4*n);
    nw.resize(2*n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back({b,i*2});
        e[b].push_back({a,i*2+1});
        p.push_back({a,b});
        p.push_back({b,a});
    }
    vector<vector<int> > so;
    for(int i=0;i<2*n;i++){
        if(nw[i]!=e[i].size()){
            ans.clear();
            dfs(i,-1);
            if(ans.size()==2){
                cout << -1 << "\n";
                return 0;
            }
            so.push_back(ans);
        }
    }
    vector<vector<int> > l(n,vector<int>(2));
    cout << 2 << " " << n << "\n";
    vector<vector<char> > ru[2];
    for(int i=0;i<2;i++){
        ru[i].resize(n);
        for(int j=0;j<n;j++){
            ru[i][j].resize(2,'$');
        }
    }
    int gx=0,gy=0;
    for(auto &h:so){
        int k=0;
        int tr=0;
        assert(h.size()%2==0);
        int u=h.size()/2;
        tr=gx; 
        for(auto q:h){
            auto y=p[q];
            l[gx][gy]=y.sc;
            if(gx==tr+u-1 && gy==0){
                ru[k][gx][gy]='U';
                gy++;
                ru[k][gx][gy]='D';
            }
            else if(gx==tr && gy==1){
                ru[k][gx][gy]='D';
                gy--;
                ru[k][gx][gy]='U';
            }
            else{
                if(gy==1){
                    ru[k][gx][gy]='R';
                    gx--;
                    ru[k][gx][gy]='L';
                }
                else{
                    ru[k][gx][gy]='L';
                    gx++;
                    ru[k][gx][gy]='R';
                }
            }
            k^=1;
        }
        gx=tr+u;
        gy=0;
    }
    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            cout << l[i][j]+1 << " ";
        }
        cout << "\n";
    }
    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            cout << ru[0][i][j];
        }
        cout << "\n";
    }
    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            cout << ru[1][i][j];
        }
        cout << "\n";
    }
    return 0;
}