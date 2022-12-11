#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> arr[55];
long long dp[55][55][5005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first;
        arr[i].first *= 1000;
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i].second;
    }
    sort(arr+1, arr+1+N, greater<pair<long long, long long>>());
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            for(int k = 0; k<=5000; k++){
                dp[i][j][k] = LLONG_MAX/4;
            }
        }
    }
    dp[0][0][0] = 0;
    int lst = 0;
    for(int i = 1; i<=N; i++){
        while(arr[lst+1].first == arr[i+1].first){
            i++;
        }
        for(int j = 0; j<=lst; j++){
            for(int k = 0; k<=lst*100; k++){
                long long sum1 = 0, sum2 = 0;
                for(int a = lst; a<=i; a++){
                    if(a-lst){
                        sum1 += arr[a].first;
                        sum2 += arr[a].second;
                    }
                    if(i-a <= j){
                        dp[i][j-(i-a)+a-lst][k+sum2] =
                        min(dp[i][j-(i-a)+a-lst][k+sum2], dp[lst][j][k] + sum1);
                    }
                }
            }
        }
        lst = i;
    }
    long long ans = LLONG_MAX;
    for(int j = 0; j<=N; j++){
        for(int k = 1; k<=lst*100; k++){
            ans = min(ans, (dp[N][j][k]+k-1)/k);
        }
    }
    cout << ans << endl;
}