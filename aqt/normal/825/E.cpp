#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
int dgr[100005];
priority_queue<int> pq;
int ans[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i =1 ; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        dgr[a]++;
    }
    for(int i = 1; i<=N; i++){
        if(!dgr[i]){
            pq.push(i);
        }
    }
    for(int i = N; i>=1; i--){
        int n = pq.top();
        pq.pop();
        ans[n] = i;
        for(int e : graph[n]){
            dgr[e]--;
            if(!dgr[e]){
                pq.push(e);
            }
        }
    }
    for(int i= 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}