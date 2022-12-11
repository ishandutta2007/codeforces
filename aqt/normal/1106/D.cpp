#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
priority_queue<int> pq;
bool vis[100005];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    pq.push(-1);
    vis[1] = 1;
    while(pq.size()){
        int n = -pq.top();
        pq.pop();
        printf("%d ", n);
        for(int e : graph[n]){
            if(!vis[e]){
                pq.push(-e);
                vis[e] = 1;
            }
        }
    }
}