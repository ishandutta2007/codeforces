#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1005];
priority_queue<int> pq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int k = 1; k<=K; k++){
        pq.push(arr[k]);
    }
    int lim = (N+1)/2;
    int ans = 0;
    while(lim){
        int n = pq.top();
        pq.pop();
        if(n >= 2){
            ans += 2;
            n -= 2;
        }
        else if(n == 1){
            ans += 1;
            n-= 1;
        }
        if(n){
            pq.push(n);
        }
        lim--;
    }
    cout << ans << endl;
}