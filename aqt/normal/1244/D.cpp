#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
long long cst[3][100005];
int dist[100005];
long long cstclr[3][3];

void dfs(int n, int p){
    dist[n] %= 3;
    for(int c = 0; c<3; c++){
        cstclr[dist[n]][c] += cst[c][n];
    }
    for(int e : graph[n]){
        if(e != p){
            dist[e] = dist[n] + 1;
            dfs(e, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int c = 0; c<3; c++){
        for(int i= 1; i<=N; i++){
            cin >> cst[c][i];
        }
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int s = 0;
    for(int i = 1; i<=N; i++){
        if(graph[i].size() > 2){
            cout << -1 << "\n";
            return 0;
        }
        else if(graph[i].size() == 1){
            s = i;
        }
    }
    dfs(s, 0);
    vector<int> p = {0, 1, 2};
    long long ans = LLONG_MAX;
    do{
        long long temp = 0;
        for(int c = 0; c<3; c++){
            temp += cstclr[c][p[c]];
        }
        ans = min(temp, ans);
    }
    while(next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
    p = {0, 1, 2};
    do{
        long long temp = 0;
        for(int c = 0; c<3; c++){
            temp += cstclr[c][p[c]];
        }
        if(temp == ans){
            for(int i = 1; i<=N; i++){
                cout << p[dist[i]]+1 << " ";
            }
            break;
        }
    }
    while(next_permutation(p.begin(), p.end()));
}