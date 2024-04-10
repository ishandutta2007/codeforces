#include <bits/stdc++.h>

using namespace std;

int N, maxA = 200000;
vector<int> prime[200005];
vector<int> graph[200005];
vector<int> fact[200005];
vector<int> comp[200005];
int arr[200005];
int dist[200005];
int vis[200005];
int ans = 0;

int dfs(int n, int p, int f){
    vis[n] = f;
    int longest = 1;
    for(int e : graph[n]){
        if(e != p && arr[e]%f == 0){
            dist[e] = dist[n] + 1;
            int chk = dfs(e, n, f);
            ans = max(longest + chk, ans);
            longest =max(chk + 1, longest);
        }
    }
    return longest;
}

int main(){
    cin >> N;
    for(int i = 2; i<=maxA; i++){
        if(prime[i].empty()){
            for(int j = i; j<=maxA; j+=i){
                prime[j].push_back(i);
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        for(int p : prime[arr[i]]){
            comp[p].push_back(i);
        }
    }
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int f = 2; f<=maxA; f++){
        if(comp[f].empty()){
            continue;
        }
        for(int n : comp[f]){
            if(vis[n] < f){
                dist[n] = 1;
                ans = max(dfs(n, 0, f), ans);
            }
        }
    }
    cout << ans << endl;
}