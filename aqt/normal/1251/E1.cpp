#include <bits/stdc++.h>

using namespace std;

int T, N;
priority_queue<pair<int, int>> pq;
priority_queue<int, vector<int>, greater<int>> lst;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i<=N; i++){
            int a, b;
            cin >> a >> b;
            pq.push({a, b});
        }
        int num = 0;
        long long tot = 0;
        for(int i = 1; i<=N; i++){
            lst.push(pq.top().second);
            if(num+N-i < pq.top().first){
                tot += lst.top();
                lst.pop();
                num++;
            }
            pq.pop();
        }
        cout << tot << "\n";
        while(pq.size()){
            pq.pop();
        }
        while(lst.size()){
            lst.pop();
        }
    }
}