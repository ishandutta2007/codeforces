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
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<int> > e(n);
        vector<int> deg(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            e[a].push_back(b);
            e[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        if(k>500){
            cout << -1 << "\n";
            continue;
        }
        set<pair<int,int> > s;
        for(int i=0;i<n;i++){
            s.insert({deg[i],i});
        }
        int flag=0;
        vector<vector<int> > cad;
        while(s.size()){
            auto h=*s.begin();
            s.erase(h);
            assert(deg[h.sc]==h.fs);
            deg[h.sc]=-1;
            if(h.fs>=k){
                cout << 1 << " " << s.size()+1 << "\n";
                for(auto a:s){
                    cout << a.sc+1 << " ";
                }
                cout << h.sc+1 << " ";
                cout << "\n";
                flag=1;
                break;
            }
            else if(h.fs==k-1){
                vector<int> v;
                v.push_back(h.sc);
                for(auto y:e[h.sc]){
                    if(deg[y]!=-1){
                        v.push_back(y);
                    }
                }
                cad.push_back(v);
            }
            for(auto y:e[h.sc]){
                if(deg[y]!=-1){
                    s.erase({deg[y],y});
                    s.insert({deg[y]-1,y});
                    deg[y]--;
                }
            }
        }
        if(flag){
            continue;
        }
        for(int i=0;i<n;i++){
            sort(e[i].begin(),e[i].end());
        }
        for(auto p:cad){
            int f2=0;
            for(auto z:p){
                for(auto h:p){
                    if(h!=z){
                        auto y=lower_bound(e[h].begin(),e[h].end(),z);
                        if(y==e[h].end() || *y!=z){
                            f2=1;
                            break;
                        }
                    }
                }
                if(f2){
                    break;
                }
            }
            if(!f2){
                cout << 2 << "\n";
                for(auto h:p){
                    cout << h+1 << " ";
                }
                cout << "\n";
                flag=1;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
        }
    }
    return 0;
}