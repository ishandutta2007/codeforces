#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<pair<int, int>, int> arr[300005];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i =1; i<=N; i++){
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].first.second++;
        arr[i].second = i;
    }
    sort(arr+1, arr+1+N);
    int ans = 0, l = 2000000000, r = -2000000000;
    for(int i = 1; i<=N; i++){
        while(pq.size() && pq.top() <= arr[i].first.first){
            pq.pop();
        }
        pq.push(arr[i].first.second);
        //cout << arr[i].second << " " << pq.size() << " " << arr[i].first.first << " " << pq.top() << endl;
        while(pq.size() > K){
            pq.pop();
        }
        if(pq.size() >= K && ans < pq.top()-arr[i].first.first){
            l = arr[i].first.first;
            r = pq.top();
            ans = r-l;
        }
    }
    cout << ans << "\n";
    for(int i = 1, c = 0; i<=N && c < K; i++){
        if(arr[i].first.first <= l && arr[i].first.second >= r){
            cout << arr[i].second << " ";
            c++;
        }
    }
}