#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int n;
vector<vector<vector<int> > > v;
struct TR{
    struct no{
        vector<int> ch;
        int dep=-1;
        int fa=-1;
        vector<int> dis;
    };
    vector<no> v;
    void init(int x){
        v.resize(x);
        for(int i=0;i<x;i++){
            v[i].dis.resize(x);
        }
    }
    void add(int x,int y){
        v[x].ch.push_back(y);
        v[y].fa=x;
    }
    void trav(int r,int f){
        v[r].dep=v[f].dep+1;
        for(auto h:v[r].ch){
            if(h!=f){
                trav(h,r);
            }
        }
    }
    void count(){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=i,b=j;
                while(v[a].dep>v[b].dep){
                    a=v[a].fa;
                    v[i].dis[j]++;
                    v[j].dis[i]++;
                }
                while(v[a].dep<v[b].dep){
                    b=v[b].fa;
                    v[i].dis[j]++;
                    v[j].dis[i]++;
                }
                if(a==b){
                    continue;
                }
                while(a!=b){
                    a=v[a].fa;
                    b=v[b].fa;
                    v[i].dis[j]+=2;
                    v[j].dis[i]+=2;
                }
            }
        }
    }
};
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        v.resize(n,vector<vector<int> >(n,vector<int>(n)));
        for(int i=0;i<n;i++){
            for(int j=1;i+j<n;j++){
                string s;
                cin >> s;
                for(int k=0;k<n;k++){
                    v[k][i][i+j]=v[k][i+j][i]=s[k]-'0';
                }
            }
        }
        int ff=0;
        for(int i=1;i<n;i++){
            TR tr;
            tr.init(n);
            vector<int> vis(n);
            vector<pair<int,int> > ans;
            vis[0]=1;
            queue<pair<int,int> > q;
            int cnt=1;
            for(int j=1;j<n;j++){
                if(i==j || v[0][i][j]==1){
                    q.push({0,j});
                    ans.push_back({0,j});
                    vis[j]=1;
                    tr.add(0,j);
                    cnt++;
                }
            }
            while(q.size()){
                auto h=q.front();
                q.pop();
                for(int l=0;l<n;l++){
                    if(vis[l]){
                        continue;
                    }
                    if(v[h.sc][h.fs][l]){
                        q.push({h.sc,l});
                        ans.push_back({h.sc,l});
                        vis[l]=1;
                        tr.add(h.sc,l);
                        cnt++;
                    }
                }
            }
            if(cnt!=n){
                continue;
            }
            tr.trav(0,0);
            tr.count();
            int flag=0;
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    for(int c=b+1;c<n;c++){
                        if((v[a][b][c]) xor (tr.v[a].dis[b]==tr.v[a].dis[c])){
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag){
                continue;
            }
            else{
                cout << "YES\n";
                ff=1;
                for(auto h:ans){
                    cout << h.fs+1 << " " << h.sc+1 << "\n";
                }
                break;
            }
        }
        if(ff==0){
            cout << "NO\n";
        }
    }
    
    return 0;
}