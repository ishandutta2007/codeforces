#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    vector<vector<int> > v(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> dis(n,1e9);
    dis[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        auto h=q.front();
        q.pop();
        for(auto a:v[h]){
            if(dis[a]>5e8){
                dis[a]=dis[h]+1;
                q.push(a);
            }
        }
    }
    if(dis[n-1]<=4){
        int nw=n-1;
        vector<int> ans;
        ans.push_back(nw);
        while(nw!=0){
            for(auto a:v[nw]){
                if(dis[a]==dis[nw]-1){
                    nw=a;
                    ans.push_back(nw);
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout << dis[n-1] << "\n";
        for(auto h:ans){
            cout << h+1 << " ";
        }
        cout << "\n";
    }
    else{
        int flag=-1;
        for(int i=0;i<n;i++){
            if(dis[i]==2){
                flag=i;
            }
        }
        if(flag==-1){
            vector<int> vis(n);
            vector<int> d2(n,1e9);
            for(int i=1;i<n;i++){
                if(dis[i]==1){
                    if(!vis[i]){
                        vector<int> k;
                        queue<int> q;
                        q.push(i);
                        d2[i]=0;
                        while(q.size()){
                            auto h=q.front();
                            q.pop();
                            vis[h]=1;
                            k.push_back(h);
                            for(auto a:v[h]){
                                if(!a){
                                    continue;
                                }
                                if(d2[a]>5e8){
                                    d2[a]=d2[h]+1;
                                    q.push(a);
                                }
                            }
                        }
                        for(auto h:k){
                            if(v[h].size()!=k.size()){
                                vector<int> d3(n,1e9);
                                queue<int> q2;
                                q2.push(h);
                                d3[h]=0;
                                while(q2.size()){
                                    auto w=q2.front();
                                    q2.pop();
                                    for(auto a:v[w]){
                                        if(!a){
                                            continue;
                                        }
                                        if(d3[a]>5e8){
                                            d3[a]=d3[w]+1;
                                            q2.push(a);
                                        }
                                    }
                                }
                                for(int j=0;j<n;j++){
                                    if(d3[j]==2){
                                        cout << 5 << "\n";
                                        cout << 1 << " " << h+1 << " ";
                                        for(auto y:v[j]){
                                            if(d3[y]==1){
                                                cout << y+1 << " ";
                                                break;
                                            }
                                        }
                                        cout << j+1 << " " << h+1 << " " << n << "\n";
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << -1 << "\n";
        }
        else{
            vector<int> ans(5);
            ans[4]=n-1;
            ans[3]=0;
            ans[2]=flag;
            ans[0]=0;
            for(auto h:v[flag]){
                if(dis[h]==1){
                    ans[1]=h;
                    break;
                }
            }
            cout << 4 << "\n";
            for(auto h:ans){
                cout << h+1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}