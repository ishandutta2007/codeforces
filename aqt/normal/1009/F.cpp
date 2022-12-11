#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[1000005];
int dep[1000005];
int ans[1000005];

inline unordered_map<int, int> dfs(int n, int p){
    unordered_map<int, int> v;
    int idx = 0;
    for(int e : graph[n]){
        if(e != p){
            dep[e] = dep[n] + 1;
            unordered_map<int, int> k = dfs(e, n);
            if(k.size() > v.size()){
                if(v.size() == 0){
                    idx = ans[e]+dep[e];
                }
                else if(k[ans[e]+dep[e]] > v[idx]){
                    idx = ans[e]+dep[e];
                }
                else if(k[ans[e]+dep[e]] == v[idx] && ans[e]+dep[e] < idx){
                    idx = ans[e]+dep[e];
                }
                swap(k, v);
            }
            for(pair<int, int> i : k){
                v[i.first] += i.second;
                if(v[i.first] > v[idx]){
                    idx = i.first;
                }
                else if(v[idx] == v[i.first] && i.first < idx){
                    idx = i.first;
                }
            }
        }
    }
    v[dep[n]]++;
    if(v[dep[n]] >= v[idx] || v.size() == 1){
        idx = dep[n];
    }
    ans[n] = idx-dep[n];
    return v;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i<=N; i++){
        cout << ans[i] << "\n";
    }
}