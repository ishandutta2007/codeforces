#include <bits/stdc++.h>

using namespace std;

int N, C;
int arr[100005];
deque<pair<int, int>> dq;
long long pre[100005];
long long dp[100005];

int main(){
    cin >> N >> C;
    for(int i = 1; i<=N; i++){
        cin >>arr[i];
        pre[i] = pre[i-1] + arr[i];
        while(dq.size() && dq.back().first >= arr[i]){
            dq.pop_back();
        }
        dq.push_back({arr[i], i});
        if(i < C){
            dp[i] = dp[i-1] + arr[i];
        }
        else{
            dp[i] = min(dp[i-1] + arr[i], dp[i - C] + pre[i] - pre[i - C] - dq.front().first);
        }
        while(dq.size() && dq.front().second <= i - C + 1){
            dq.pop_front();
        }
    }
    cout << dp[N] << endl;
}