#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[300000];
long long tot = 0;
long long sz[300000], subdis[300000], pdis[300000], arr[300000];

void dfs1(int n, int p){
    sz[n] = arr[n];
    for(int e : graph[n]){
        if(e != p){
            dfs1(e, n);
            sz[n] += sz[e];
            subdis[n] += subdis[e] + sz[e];
        }
    }
}

void dfs2(int n, int p){
    for(int e : graph[n]){
        if(e != p){
            pdis[e] = pdis[n] + subdis[n] - (subdis[e] + sz[e]) + tot - sz[e];
            dfs2(e, n);
        }
    }
}

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
        tot += arr[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, pdis[i] + subdis[i]);
    }
    cout << ans << endl;
}