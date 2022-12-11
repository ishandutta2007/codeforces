#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
int dist[100005];

double dfs(int n, int p){
    double ret = 0;
    if(graph[n].size() == 1 && p){
        return dist[n];
    }
    for(int e : graph[n]){
        if(e != p){
            dist[e] = dist[n] + 1;
            ret += dfs(e, n);
        }
    }
    if(p){
        ret *= 1.0/(graph[n].size()-1);
    }
    else{
        ret *= 1.0/graph[n].size();
    }
    return ret;
}

int main(){
    cin >> N;
    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    cout.precision(11);
    for(int i =1 ; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << dfs(1, 0) << "\n";
}