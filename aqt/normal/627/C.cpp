#include <bits/stdc++.h>

using namespace std;

int D, C, N;
pair<int, int> arr[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> D >> C >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    arr[N+1].first = D;
    sort(arr+1, arr+2+N);
    pq.push({0, 0});
    int c = 0;
    long long ans = 0;
    for(int i = 1; i<=N+1; i++){
        int p = arr[i].first;
        while(pq.size() && c < p){
            int t = min(C+pq.top().second, p);
            ans += 1LL*(max(0, t-c))*pq.top().first;
            c = max(t, c);
            if(c >= C+pq.top().second){
                pq.pop();
            }
        }
        if(pq.empty() && c < p){
            cout << -1 << endl;
            return 0;
        }
        pq.push({arr[i].second, arr[i].first});
    }
    cout << ans << endl;
}