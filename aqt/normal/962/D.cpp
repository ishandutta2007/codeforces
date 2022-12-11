#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<pair<long long, int>,
vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long ans[150005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        long long n;
        cin >> n;
        pq.push({n, i});
    }
    int cnt = 0;
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        if(pq.empty() || pq.top().first != p.first){
            cnt++;
            ans[p.second] = p.first;
            continue;
        }
        auto q = pq.top();
        pq.pop();
        q.first += p.first;
        pq.push(q);
    }
    cout << cnt << "\n";
    for(int i = 1; i<=N; i++){
        if(ans[i]){
            cout << ans[i] << " ";
        }
    }
}