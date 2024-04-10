#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<int> pq;
    int N, K;
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        pq.push(-n);
    }
    int M;
    cin >> M;
    long long ans = 0;
    for(int i = 1; i<=M; i++){
        if(pq.empty()){
            ans -= K;
        }
        else{
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}