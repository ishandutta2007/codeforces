#include <bits/stdc++.h>

using namespace std;

int N;
long long val[100005];
vector<int> graph[100005];
bool vis[100005];

int main(){
    cin >> N;
    for(int i= 2; i<=N; i++){
        for(int j = 2; i*j <= N; j++){
            val[i] += j;
            val[j] += i;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    long long ans = 0;
    for(int i = 2; i<=N; i++){
        if(!vis[i]){
            deque<int> dq;
            dq.push_back(i);
            vis[i] = 1;
            long long c = 0;
            while(dq.size()){
                int n = dq.front();
                c += val[n];
                dq.pop_front();
                for(int e : graph[n]){
                    if(!vis[e]){
                        dq.push_back(e);
                        vis[e] = 1;
                    }
                }
            }
            ans = max(c, ans);
        }
    }
    cout << ans*2 << endl;
}