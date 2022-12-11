#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[500005];
vector<int> v;
int dep[500005];

void dfs(int n, int p){
    if(graph[n].size() == 1){
        v.push_back(dep[n]);
        return;
    }
    for(int e : graph[n]){
        if(e != p){
            dep[e] =dep[n] + 1;
            dfs(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for(int e : graph[1]){
        dep[e] = 1;
        dfs(e, 1);
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++){
            v[i] = max(v[i-1] + 1, v[i]);
        }
        ans = max(ans, v.back());
        v.clear();
    }
    cout << ans << endl;
}