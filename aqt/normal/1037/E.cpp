#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int, int>> graph[200005];
stack<int> ans;
vector<pair<int, int>> v;
bool exist[200005];
int dgr[200005];
queue<int> qu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    fill(exist+1, exist+1+N, 1);
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        graph[a].push_back({b, i-1});
        graph[b].push_back({a, i-1});
        dgr[a]++, dgr[b]++;
    }
    int crnt = N;
    for(int i= 1; i<=N; i++){
        if(dgr[i] < K){
            qu.push(i);
        }
    }
    while(qu.size()){
        int n = qu.front();
        qu.pop();
        crnt--;
        exist[n] = 0;
        for(auto e : graph[n]){
            dgr[e.first]--;
            if(dgr[e.first] == K-1 && exist[e.first]){
                qu.push(e.first);
                exist[e.first] = 0;
            }
        }
    }
    for(int i = M-1; i>=0; i--){
        ans.push(crnt);
        if(exist[v[i].first] && exist[v[i].second]){
            dgr[v[i].first]--, dgr[v[i].second]--;
            if(dgr[v[i].first] < K && exist[v[i].first]){
                qu.push(v[i].first);
                exist[v[i].first] = 0;
            }
            if(dgr[v[i].second] < K && exist[v[i].second]){
                qu.push(v[i].second);
                exist[v[i].second] = 0;
            }
            while(qu.size()){
                int n = qu.front();
                qu.pop();
                crnt--;
                exist[n] = 0;
                for(auto e : graph[n]){
                    if(e.second >= i){
                        continue;
                    }
                    dgr[e.first]--;
                    if(dgr[e.first] == K-1 && exist[e.first]){
                        qu.push(e.first);
                        exist[e.first] = 0;
                    }
                }
            }
        }
    }
    while(ans.size()){
        cout << ans.top() << "\n";
        ans.pop();
    }
}