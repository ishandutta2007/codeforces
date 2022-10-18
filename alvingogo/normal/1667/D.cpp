#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        struct no{
            vector<pair<int,int> > ch;
        };
        int n;
        cin >> n;
        vector<no> v(n);
        vector<int> eg(n,-1);
        vector<pair<int,int> > ve(n);
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            v[a].ch.push_back({b,i});
            v[b].ch.push_back({a,i});
            ve[i]={a,b};
        }
        int flag=0;
        function<void(int,int)> dfs=[&](int r,int f){
            int c[2]={0};
            int u=-1;
            for(auto h:v[r].ch){
                if(h.fs!=f){
                    dfs(h.fs,r);
                    c[eg[h.sc]]++;
                }
                else{
                    u=h.sc;
                }
            }
            int z=c[0]-c[1];
            if(z<-1 || z>2){
                flag=1;
            }
            if(r==0 && (z<0 || z>1)){
                flag=1;
            }
            if(u<0){
                return;
            }
            if(z<=0){
                eg[u]=0;
            }
            else{
                eg[u]=1;
            }
        };
        dfs(0,0);
        if(flag==1){
            cout << "NO\n";
            continue;
        }
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
                e[x].push_back(y);
                in[y]++;
            }
            void print(vector<pair<int,int> > &k){
                cout << "YES\n";
                queue<int> q;
                for(int i=1;i<n;i++){
                    if(in[i]==0){
                        q.push(i);
                    }
                }
                while(!q.empty()){
                    auto h=q.front();
                    q.pop();
                    cout << k[h].fs+1 << " " << k[h].sc+1 << '\n';
                    for(auto y:e[h]){
                        in[y]--;
                        if(in[y]==0){
                            q.push(y);
                        }
                    }
                }   
            }
        };
        TPS tps;
        tps.init(n);
        function<void(int,int)> dfs2=[&](int r,int f){
            vector<int> c[2];
            for(auto h:v[r].ch){
                c[eg[h.sc]].push_back(h.sc);
            }
            if(v[r].ch.size()%2){
                for(int i=0;i<c[1].size();i++){
                    tps.add(c[0][i],c[1][i]);
                    tps.add(c[1][i],c[0][i+1]);
                }
            }
            else{
                for(int i=0;i<c[0].size();i++){
                    tps.add(c[1][i],c[0][i]);
                    if(i+1!=c[0].size()){
                        tps.add(c[0][i+1],c[1][i]);
                    }
                }
            }
            for(auto h:v[r].ch){
                if(h.fs!=f){
                    dfs2(h.fs,r);
                }
            }
        };
        dfs2(0,0);
        tps.print(ve);
    }
    return 0;
}