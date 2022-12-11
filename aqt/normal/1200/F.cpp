#include <bits/stdc++.h>

using namespace std;

int N, M = 2520, Q;
int ans[1005][2530];
int dist[1005][2530];
vector<int> graph[1005];
int val[1005], sz[1005];
int vis[1005][2530];
bool seen[1005];
stack<pair<int, int>> stk;

pair<int, int> nxt(pair<int, int> p){
    int n = p.first, k = p.second;
    k += val[n];
    k %= M;
    if(k < 0){
        k += M;
    }
    p = {graph[n][k%sz[n]], k};
    return p;
}

inline int getlen(pair<int, int> p, int c){
    if(vis[p.first][p.second] == 2){
        return ans[p.first][p.second] = c;
    }
    vis[p.first][p.second] = 2;
    if(!seen[p.first]){
        c++;
        seen[p.first] = 1;
    }
    int v = getlen(nxt(p), c);
    seen[p.first] = 0;
    return ans[p.first][p.second] = v;
}

bool precomp(pair<int, int> p, pair<int, int> q){
    //cout << p.first << " " << q.second << endl;
    stk.push(p);
    if(vis[p.first][p.second]){
        return 1;
    }
    if(p == q){
        return 0;
    }
    return precomp(nxt(p), nxt(nxt(q)));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> sz[i];
        for(int j = 1; j<=sz[i]; j++){
            int n;
            cin >> n;
            graph[i].push_back(n);
        }
    }
    for(int n= 1; n<=N; n++){
        for(int m = 0; m<M; m++){
            if(!vis[n][m]){
                int k = 0;
                stk.push({n, m});
                pair<int, int> p = nxt({n, m});
                if(precomp(p, nxt(p))){
                    //cout << "f: " << n << " " << m << endl;
                    k = ans[stk.top().first][stk.top().second];
                    //cout << stk.top().first << " " << stk.top().second << " " << n << " " << m << endl;
                }
                else{
                    k = getlen(stk.top(), 0);
                }
                while(stk.size()){
                    if(stk.top().first == 4 && stk.top().second == 2518){
                        //cout << "bing " << n << " " << m << " " << k << endl;
                    }
                    vis[stk.top().first][stk.top().second] = 1;
                    ans[stk.top().first][stk.top().second] = k;
                    stk.pop();
                }
            }
        }
    }
    cin >> Q;
    while(Q--){
        int n, k;
        cin >> n >> k;
        k %= M;
        if(k < 0){
            k += M;
        }
        cout << ans[n][k] << "\n";
    }
}