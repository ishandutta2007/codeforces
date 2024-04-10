#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> graph[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    long long cnt = N-1;
    for(int i= 1; i<=N; i++){
        for(int j = i+1; j<=N; j++){
            if(!graph[i].count(j)){
                cnt--;
                if(graph[j].size() > graph[i].size()){
                    swap(graph[i], graph[j]);
                }
                set<int> t;
                for(int n : graph[j]){
                    if(graph[i].count(n)){
                        t.insert(n);
                    }
                }
                graph[j] = t;
                break;
            }
        }
    }
    cout << cnt << endl;
}