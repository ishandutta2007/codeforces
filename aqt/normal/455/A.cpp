#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[100005];
long long arr[100005];

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        int n;
        cin >> n;
        arr[n] += n;
    }
    dp[1] = arr[1];
    for(int i = 2; i<=100000; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    cout << dp[100000] << endl;
}